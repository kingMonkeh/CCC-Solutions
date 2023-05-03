/*

2012 S5 - Mouse Journey
Difficulty: Very Easy

This is like textbook level dynammic programming problem.
Work backwards.
Given the end position, how many ways are there to reach it?
Total ways = total ways to reach the above node + total ways to reach the left node
You can then keep applying this logic until you return to the start

You can see that once we calculate the total ways to reach a certain cage, we can reuse this result in later calculations
Hence, DP problem

Watch out for out of bounds and cat cages

*/

#include <iostream>
#include <unordered_map>

int R, C;
int DP[626]; //Memoize our solution
std::unordered_map<int, bool> cat;

int solve (int row, int col){
    //If we've already solved it
    if (DP[C * (row - 1) + col]){
        return DP[C * (row - 1) + col];
    }
    //If we're at the start, only 1 way
    if (row == 1 && col == 1){
        return 1;
    }
    //If we're at a cat cage, impossible
    if (cat[C * (row - 1) + col] == true){
        return 0;
    }
    //Otherwise, check left and up
    int ways = 0;
    if (row > 1) ways += solve(row - 1, col);
    if (col > 1) ways += solve(row, col - 1);
    DP[C * (row - 1) + col] = ways; //Memoize
    return ways;
}

int main(){  
    std::cin >> R >> C;
    int K;
    std::cin >> K;
    for (int i = 0; i < K; i++){
        int r, c;
        std::cin >> r >> c;
        cat[C * (r - 1) + c] = true; //Convert 2-D array to 1-D array for easy mapping
    }
    std::cout << solve(R, C) << '\n';
    return 0;
}