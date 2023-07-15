/*

Let DP[i] tell us the minimum cost to reach stone i
DP[i] = min(DP[i - 1] + abs(cur stone - prev stone), DP[i - 2] + abs (cur stone - prev stone))

*/

#include <bits/stdc++.h>

int N;
std::vector<int> stones;
int DP [100001];

int main (){

    std::cin >> N;
    stones.resize(N);
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < N; i++){
        std::cin >> stones[i];
    }

    for (int i = 1; i < N; i++){
        DP[i] = DP[i - 1] + abs(stones[i] - stones[i - 1]);
        if (i >= 2) DP[i] = std::min(DP[i], DP[i - 2] + abs(stones[i] - stones[i - 2]));
    }

    std::cout << DP[N - 1] << '\n';
    
    return 0;
    
}