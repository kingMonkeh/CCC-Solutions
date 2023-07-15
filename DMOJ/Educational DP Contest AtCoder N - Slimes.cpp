#include <bits/stdc++.h>

/*

So... Idk really know how to explain it, it was just kinda gut feeling
Very similar problem to CCC S4 Combining Riceballs

Basically we notice that since the cost can be represented as a sum
We want to minimize the values of that sum, meaning we want to choose the smallest slimes to combine

We let DP[i][j] tell us the smallest slime we can make from segment i --> j (inclusive)
Note that the cost isn't just the slime itself, the cost is cumulative of all the moves
Therefore we will maintain a second array called cost[i][j] which tells us the minimum cost to combine segment i --> j (inclusive)

We notice the transition is quite simple, we have two choices
Given a segment, we can either append one slime to the front or back of it
Or we can append another segment to it

Therefore we just try every possible combination of contiguous pairs of segments and take the minimum

*/

long long DP[400][400];
long long cost[400][400];

int main(){

    int N;
    std::cin >> N;
    int slimes [N];
    for (auto& slime: slimes) std::cin >> slime;

    //Minimum 2 slimes, base case is we have only 2 slimes, your only choice is to combine
    for (int i = 1; i < N; i++){
        DP[i - 1][i] = cost[i - 1][i] = slimes[i - 1] + slimes[i];
    }

    //let i represent the size of the entire combined segment
    for (int i = 2; i < N; i++){
        //let l represent the left of the entire segment
        for (int l = 0; l <= N - i - 1; l++){
            int r = l + i; //let r represent the right of the entire segment
            DP[l][r] = DP[l + 1][r] + slimes[l]; //Add a slime to the left
            cost[l][r] = cost[l + 1][r] + DP[l + 1][r] + slimes[l]; //Check cost
            DP[l][r] = std::min(DP[l][r], DP[l][r - 1] + slimes[r]); //Add a slime to the right
            cost[l][r] = std::min(cost[l][r], cost[l][r - 1] + DP[l][r - 1] + slimes[r]); //Check cost
            //Combining segments that are each size 2 or greater
            //let m be the end of the segment starting at l (inclusive)
            //segment {l, r} = {l, m} + {m + 1, r}
            for (int m = l + 1; m < r - 1; m++){
                DP[l][r] = std::min(DP[l][r], DP[l][m] + DP[m + 1][r]);
                cost[l][r] = std::min(cost[l][r], cost[l][m] + cost[m + 1][r] + DP[l][m] + DP[m + 1][r]);
            }
        }
    }

    std::cout << cost[0][N - 1] << '\n';
    
    return 0;
    
}