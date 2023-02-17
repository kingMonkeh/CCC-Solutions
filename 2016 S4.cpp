/*

2016 S4 - Combining Riceballs

Topics: Dynamic Programming

Difficulty: Hard

For this problem, we will create a 2-D array called combinable

combinable[i][j] will tell us whether riceballs from index i to index j can be combined.

Key insight #1:
If riceballs from index i to index j can be combined, does the order they're combined in affect the sum?

Answer: No, regardless of how they're combined, their end result will always be the sum of the riceballs in that interval.
This will allow us to create an array called sum.
sum[i] will tell us the sum of all riceballs from index 0 to index i. We can use sum to calculate the riceball sizes quickly.
largest riceball from i to j = sum[j] - sum[i]

Now comes the tricky part, determining which riceballs can be combined.
To accomplish this, we will iterate through every possible combination size aka 2 -> N-1

For each of these possible combination sizes, we will iterate through every possible starting position

Then for each starting position, we will iterate through all possible front, middle and end block sizes

When checking with the front, middle and end blocks, for combinable[i][j] to be true

The front must be combinable, the middle must be combinable (note that if there's no middle we can exclude it), the end block must be combinable and the front block must equal the end block

Imagine we have the riceballs

2 1 2 21 21 1 3 1

We can view the front block as 2 1 2, which can be combined to equal 5
We can view the middle block as 21 21, which can be combined to equal 42
We can view the end block as 1 3 1, which can also be combined to make 5

Since the front block == end block and they're both combinable, this entire segment is combinable since it can be reduced to
5 42 5
Following the three block rule, this can now be combined into 52

*/

#include <iostream>
#include <vector>

int main(){

    int N;
    std::cin >> N;

    std::vector<int> riceballs (N); //Riceballs
    std::vector<int> sum (N); //Sum array, sum[i] = sum from index 0 to index i in the riceballs

    //For the first riceball since the remaining sums will make use of the previous sum
    std::cin >> riceballs[0];
    sum[0] = riceballs[0];

    for (int i = 1; i < N; i++){

        std::cin >> riceballs[i];
        sum[i] = sum[i - 1] + riceballs[i]; //Sum = previous sum + current riceball

    }

    std::vector<std::vector<bool>> combinable (N, std::vector<bool> (N, false)); //combinable[i][j] tells us whether we can combine riceballs from riceballs[i] to riceballs[j]

    //Initialize the base case, all segments of size 1 are possible
    for (int i = 0; i < N; i++){

        combinable[i][i] = true;

    }

    //For every possible segment size
    for (int range = 1; range < N; range++){

        //For every start position
        for (int start = 0; start < N - range; start++){

            int end = start + range; //end is the END OF THE END BLOCK

            int frontBlock = riceballs[start]; //sum of riceballs in front block
            int endBlock = riceballs[end]; //sum of riceballs in end block

            int frontBlockEnd = start; //frontBlockEnd is the index of the end of the front block
            int endBlockBegin = end; //endBlockBegin is the starting index of the end block

            //The end of the front block can't go past the beginning of the end block otherwise they'd be eating from one another
            while (frontBlockEnd < endBlockBegin){

                //if front is combinable, there exists no middle or middle is combinable, end is combinable and front block == end block
                if (combinable[start][frontBlockEnd] && (endBlockBegin - 1 < frontBlockEnd + 1 || combinable[frontBlockEnd + 1][endBlockBegin - 1]) && combinable[endBlockBegin][end] && frontBlock == endBlock){
                    combinable[start][end] = true; //It's possible
                    break;
                }

                //If frontblock is smaller than endblock, we should increase add a riceball to it in hopes that it will now equal the end block and possibly allow a merge
                if (frontBlock < endBlock){
                    frontBlockEnd++;
                    frontBlock += riceballs[frontBlockEnd];
                }

                //If end block is smaller, we should add a riceball in hopes that it will equal the front block
                else{
                    endBlockBegin--;
                    endBlock += riceballs[endBlockBegin];
                }

            }

        }

    }

    int largestRiceball = 0; //Largest possible riceball to be made

    //Loop through every range, if it can be combined, determine the sum of riceballs in that range, update max accordingly
    for (int i = 0; i < N; i++){

        for (int j = 0; j < N; j++){

            if (combinable[i][j]){

                largestRiceball = std::max(largestRiceball, sum[j] - sum[i] + riceballs[i]); // + riceballs[i] since the substraction of sums actually excludes the initial riceball

            }

        }

    }

    std::cout << largestRiceball;

    return 0;

}