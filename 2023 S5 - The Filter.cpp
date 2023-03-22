/*

2023 S5 - The Filter

Difficulty: HARD

This problem is top tier recursion.

I find this problem quite deceptive, since Cantor sets are very deceptive
Although N can be up to 1 000 000 000, if you applied the first dozen filters or so, there's only like 100 000 numbers max that remain

Therefore, our first step should be to just filter out the majority of the numbers
To do this, we write a recursive function called filter(iter, start, stop), which takes the current filter level (top to bottom) as well as the left and right of the examined section

Afterwards, if we've reached the last level of filter we want to apply, we just add the all the number within the range (start, stop) to a global vector
Otherwise, we split the current section into 3 parts, and only recurse further into the leftmost and rightmost sections since the middle numbers would have been filtered

What remains in our global vector, are potential candidates that are either filtered much further down, or that live forever

For these remaining numbers, we will have to check much more deeply to see if they're filtered
To do this, we will recursively apply the filter over and over and over

0                           N
|         ---------         |
|   ---   |       |   ---   |
0         N       0         N
 
Notice how the left and right bottom filters are exact copies of the top filter, except they're compressed
We will take advantage of this during our recursion, by setting the left side of a section as 0, and the right side as N

To get to the next level of filter, we ask ourselves, how much would we have to scale our current value?

Notice that if we're on the left side, we can multiply our value by 3 to get its position in the next section
For example, in the samply input, 1/12 is on the left side of the first filter
If we multiply it by 3, it becomes 3/12, and if we look at the second layer of filters
With respect to the left section only, it's indeed at 3/12 on the second layer of filters

On the other hand, if the number (x) passes through the right side, then its position in the next level would be:
new x = x * 3 - N * 2
For example, 9/12 (technically just 9) in the sample input, would become 3/12 in the next filter
And if we look further down, this is the case.

As we keep applying filters, one of two outcomes will occur, either we hit the middle filter or we run into a cycle
For example take 4/12
Its next position would be 12/12
And its next position would be 12/12 again (since it was on right side previously, 12 * 3 - 12 * 2 = 12)
And it would keep producing 12, therefore we will create a map telling us what numbers have already been visited
If a number has already been visited, then that means that it creates a cycle which means it lives forever, meaning it never touches the middle filter

With this. We can solve the problem

*/

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

double N;
std::vector<int> nums; //Store possible points, note it's possible some points in this vector are not actually in the cantor set, that's why we use the better filter

//Initial filter
void filter (int iteration, double start, double end){
    
    //Once we've applied the last layer of filters, we can now begin adding possible candidates to our vector
    if (iteration == 0){
        
        //We want to be rounding up on the left and rounding down on the right to ensure we don't take points past our range
        for (int i = ceil(start); i <= floor(end); i++){
            nums.push_back(i);
        }
        
    }

    else{

        //View it as 3 sections, left middle and right

        double section1Right = start + (end - start) / 3;
        double section3Left = start + 2 * (end - start) / 3;

        //Continue only on the left and right section since the middle is the filter
        filter(iteration - 1, start, section1Right);
        filter(iteration - 1, section3Left, end);

    }
    
}

std::unordered_map <long long, bool> cycle;

//The much more precise filter that recursively applies the filter over a number
bool isCantor(long long i){

    //If it's in the middle, it's not in the Cantor set
    if (i * 3 > N && i * 3 < 2 * N){
        return false;
    }

    //If it's on the left side, scale by a factor of 3
    if (i * 3 <= N){

        i *= 3;

        //Check if this creates a cycle
        if (cycle[i]){
            return true;
        }

        cycle[i] = true;

        return isCantor(i);

    }

    //If it's not middle, not left, then it must be right side
    else{

        i *= 3;
        i -= N * 2;

        //Check cycle
        if (cycle[i]){
            return true;
        }

        cycle[i] = true;

        return isCantor(i);

    }

}

int main()
{
    
    std::cin >> N;
    
    filter(19, 0.0, N); //Perform initial filter

    //Iterate through remaining possible candidates, which isn't actually that many
    for (int i: nums){

        //Check if they're Cantor
        if (isCantor(i)){
            std::cout << i << '\n';
        }

        //Clear the cycle map, for the next candidate
        cycle.clear();

    }
    
    return 0;
    
}


