/*

2015 S5 - Greedy For Pies

Difficulty: Hard

This is a dynammic programming problem, here's the main idea:

As with any DP problem, it's basically just optimized brute force
Meaning we have to try every possible arrangement of pies
And every possible way of choosing pies for each arrangement

To accomplish this, we do not actually need to merge the two arrays
Notice that when inserting the pies from the M line, we would use a pie for one of 2 things

1. To use it as a seperator, if this is the case, we would want to choose the lowest value pie that's left from line M
2. Actually take this pie for its sugar, in this case, we'd want to choose the highest sugar pie that's left from Line M

Therefore, we will sort the M line from least to greatest and maintain 2 iterators
1 on the left that tells us the lowest sugar pie remaining, and 1 on the right that tells us the highest sugar pie remaining

We will now make a 4-D DP array that will indicate the unique state of a scenario
DP [i][j][k][l] tells us that we're at index i of the N pies, j is the left iterator of the M line, k is the right iterator of the M line, and l tells us whether or not we have previously taken a pie

Now that we have a way of representing the state of a scenario, now comes the logic/casework to deciding what to do to reach the next state

Main Case #1 - We've previously taken a pie

Here we cannot take another pie, therefore we can either skip the N pie
Or we can use a pie from the M line as a seperator

Main Case #2 - We haven't taken a pie previously
Here we can choose the pie from the N line
Choose a pie from the M line
Or we can choose to skip the current pie in the N line, imagine the case 999 1 1 999999 (here we need to skip 2 to reach optimal)

Note that if we've reached the end of the N line, we can only access the M line
If both have been exhausted, return our result

Essentially, work backwards with DP

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define vi std::vector<int>
#define IMPOSSIBLE -1
const int MAX_N = 3001, MAX_M = 102;
int N, M;

vi A, B; //Sugar of each pie
int DP [MAX_N][MAX_M][MAX_M][2]; //DP array

int solve (int nPie, int leftM, int rightM, bool prevTake){
    
    //Use memoized info if it exists
    if (DP[nPie][leftM][rightM][prevTake] > IMPOSSIBLE){
        return DP[nPie][leftM][rightM][prevTake];
    }

    int maxSugar = 0;

    //If we've used all pies
    if (nPie == N && leftM > rightM){
        DP[nPie][leftM][rightM][prevTake] = maxSugar;
        return maxSugar;
    }

    //If previously took a pie
    if (prevTake == true){

        //If not at the end of the line, we can just skip this pie
        if (nPie < N){
            maxSugar = std::max(maxSugar, solve(nPie + 1, leftM, rightM, false));
        }

        //Use seperator pie from M line
        if (leftM <= rightM){
            maxSugar = std::max(maxSugar, solve(nPie, leftM + 1, rightM, false));
        }

    }

    //If you didn't previously take a pie, more options
    else{
        
        //If not at the end of the line
        if (nPie < N){

            //Take the a pie from the N line
            maxSugar = std::max(maxSugar, A[nPie] + solve(nPie + 1, leftM, rightM, true));

            //Skip this pie
            maxSugar = std::max(maxSugar, solve(nPie + 1, leftM, rightM, false));

        }

        //Take a pie from the  M line
        if (leftM <= rightM){
            maxSugar = std::max(maxSugar, B[rightM] + solve(nPie, leftM, rightM - 1, true));
        }
        
    }
    

    DP[nPie][leftM][rightM][prevTake] = maxSugar;
    return maxSugar;

}

int main(){

    std::cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++){
        std::cin >> A[i];
    }

    std::cin >> M;
    B.resize(M + 1);

    //NOTE! VERY IMPORTANT YOU USE 1 INDEXING BECAUSE rightM MAY BECOME -1 WITH ZERO INDEXING IF ONE CHOOSES TO REPEATEDLY PICK PIES FROM THE M LINE
    for (int i = 1; i <= M; i++){
        std::cin >> B[i];
    }

    std::sort(B.begin(), B.end());
    
    memset(DP, -1, sizeof(DP)); //-1 just means impossible

    //Since we recursive tree goes to the edge and then collapses back, the answer is at index 0 in N, index 1 in M, index M in M, no pie taken yet
    std::cout << solve(0, 1, M, false) << '\n';

    return 0;

}