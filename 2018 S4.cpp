/*

2018 S4 - Balanced Trees

Difficulty: Medium/Hard

Maybe I'm getting better, but for a question rated 15pp on DMOJ, I didn't find it as challenging as the other S4 problems.

General idea:
We will write a recursive function called solve(i), which determines the total number of trees for weight i

Key Insight #1: Balanced trees can be made up of several other balanced trees

For example, imagine we need to solve N = 10

if k = 2, then subtreeWeight = 5
if k = 3, then subtreeWeight = 3
if k = 4, then subtreeWeight = 2
if k = 5, then subtreeWeight = 2
if k = 6, then subtreeWeight = 1
if k = 7, then subtreeWeight = 1
if k = 8, then subtreeWeight = 1
if k = 9, then subtreeWeight = 1
if k = 10, then subtreeWeight = 1

Notice that when k = 2, there are several ways we can arrage a balanced tree of weight 5, we must add this number to the ways we can solve 10

Therefore, solve(10) = solve(5) + solve(3) + solve(2) + solve(2) + solve(1) + solve(1) + solve(1) + solve(1) + solve(1)
Collecting like terms, solve(10) = solve(5) + solve(3) + 2 * solve(2) + 5 * solve(1)

So obviously, you can try iterating linearly for every recurse determining the amount of trees and adding them, but this is too slow.
To optimize it, we will memoize it, to accomplish this we will create a map called trees
trees[i] will tell us the total number of trees for weight i, this way we don't have to compute the same weight repeatedly

Still this is too slow for the last subtask, since we're still iterating through every possible value of k.
To reduce this, we notice that all we really need to determine is each subtree weight and its frequency

This is where things get tricky, essentially we will start by creating a window over all possible # of subtrees
Upon creation, this window will have its last index as the maximum number of subtrees, to determine its start index, we will calculate weight / (the current subtreeweight (aka 1) + 1)
This number will tell us the largest value of k in which the weight is no longer equal to the current subtree weight, thus the next value of k would be the last frequency of the subtree weight

For example if N = 10
Our window will have its end at 10, the current weight would be 1 since 10/10 = 1, the start of this window would be at 10 / (1 + 1) = 5
This is correct because if k < 5, then the subtree weight can be larger. Therefore there is 5 occurences of solve(1).

*/

#include <iostream>
#include <unordered_map>

std::unordered_map<int, long long> trees; //trees[i] tells us number of trees for weight i, we use unordered_map since it's faster and we have no need for order

//Determines number of trees for this weight
void solve (int weight){
    
    long long totaltrees = 0;

    //Moving window concept i talked about earlier, essentially determining frequency of each subtree weight
    //Should terminate when weightEndIndex = 1 since this means that the end of the window has made it to the beginning of the list
    for (int weightEndIndex = weight, weightStartIndex; weightEndIndex > 1; weightEndIndex = weightStartIndex){

        int subtreeWeight = weight / weightEndIndex; //Determine subtree weight
        weightStartIndex = weight / (subtreeWeight + 1); //Determine max value of k that will generate a greater weight value, which also tells us the end of the current weight value

        //If this weight hasn't been solved yet
        if (trees.count(subtreeWeight) == 0){
            solve(subtreeWeight);
        }

        //Add memoized information to the total number of trees
        totaltrees += trees[subtreeWeight] * (weightEndIndex - weightStartIndex);

    }

    trees[weight] = totaltrees; //Memoize information

}

int main(){

    int N;
    std::cin >> N;
    
    trees[1] = 1; //Initialize base case, aka just a root

    //We only need to solve if N > 1
    if (N > 1) solve(N);

    std::cout << trees[N];

    return 0;

}