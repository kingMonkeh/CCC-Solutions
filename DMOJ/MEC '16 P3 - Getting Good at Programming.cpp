/*

interesting knapsack problem, normally we do this recursively, but this time we're doing it iteratively

DP[i][j] tells us the max exp we can earn using the first i skills, and j time used
Default value is 0, indicating no exp can be earned

We basically use prefix sum to determine how much time is required in total to reach a certain level of a skill, and how much exp we would earn

We then go through every level of a skill and update DP accordingly

*/

#include <iostream>
#include <algorithm>
#include <string.h>

int DP[101][101];

int main(){
    memset(DP, 0, sizeof(DP));
    int N, T;
    std::cin >> N >> T;
    //For each skill
    for (int i = 1; i <= N; i++){
        int totalTime = 0, totalExp = 0; //Prefix sum
        int levels;
        std::cin >> levels;
        //For each level of this skill
        for (int j = 1; j <= levels; j++){
            int time, exp;
            std::cin >> time >> exp;
            totalTime += time, totalExp += exp; //Update prefix sum
            //For every possible weight used
            for (int k = 0; k <= 100; k++){
                //Say if we don't level this skill
                DP[i][k] = std::max(DP[i][k], DP[i - 1][k]);
                //If it's possible to level the skill, then try it
                if (totalTime <= k){
                    //DP[i][k] = max(self, max amount from previous skill before adding this amount)
                    DP[i][k] = std::max(DP[i][k], DP[i - 1][k - totalTime] + totalExp);
                }
            }
        }
    }
    std::cout << DP[N][T];
    return 0;
}