#include <bits/stdc++.h>

/*

Given a square in the grid, the incoming path could only have come from above it or from the left, due to the movement constraints
therefore dp[i][j] = dp [i - 1][j] + dp[i][j - 1] so long as there are no obstacles and the square exists

*/

//(a + b) % m = ((a % m) + (b % m)) % m
const int MOD = 1e9 + 7;

long long DP [1000][1000];
std::vector<std::string> grid; 

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    memset(DP, 0, sizeof(DP));
    int H, W;
    std::cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; i++) std::cin >> grid[i];

    DP[0][0] = 1;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (i > 0 && grid[i - 1][j] != '#') DP[i][j] += DP[i - 1][j] % MOD;
            if (j > 0 && grid[i][j - 1] != '#') DP[i][j] += DP[i][j - 1] % MOD;
            DP[i][j] %= MOD;
        }
    }

    std::cout << DP[H - 1][W - 1] << '\n';
    
    return 0;
    
}