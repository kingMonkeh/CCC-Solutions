#include <bits/stdc++.h>

int N;
double coins [3000];
double DP [3000][3000]; //DP[i][j] tells us probability of having j heads using the first i coins

/*
Slow Brute Force
Useful for noticing pattern and what states are important to keep track of

void solve (int coin, int heads = 0, int tails = 0, double prob = 1){

    if (coin == N){
        if (heads > tails){
            ans += prob;
        }
        return;
    }

    solve(coin + 1, heads + 1, tails, prob * coins[coin]);
    solve(coin + 1, heads, tails + 1, prob * (1 - coins[coin]));
        
}
*/

int main (){

    std::cin >> N;
    for (int i = 0; i < N; i++) std::cin >> coins[i];

    DP[0][0] = 1 - coins[0];
    DP[0][1] = coins[0];

    for (int i = 1; i < N; i++){
        //weird since 0 indexing, but if you have i coins, you would have i + 1 possible values for total heads, 0 --> i
        for (int j = 0; j <= i + 1; j++){
            DP[i][j] = DP[i - 1][j] * (1 - coins[i]); //Take tails
            if (j > 0) DP[i][j] += DP[i - 1][j - 1] * (coins[i]); //Take heads if possible
        }
    }

    //Count all occurrences where heads > tails, (N / 2) + 1
    double ans = 0;
    for (int i = (N / 2) + 1; i <= N; i++){
        ans += DP[N - 1][i];
    }

    std::cout << std::fixed << std::setprecision(10) << ans << '\n'; 
    
    return 0;
    
}