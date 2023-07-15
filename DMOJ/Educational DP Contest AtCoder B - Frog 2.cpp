/*

Just like Frog 1
let DP[i] = min cost to reach stone i

Only difference is, we now just check every single k value
for (k = 1 ... K)
DP[i] = min(DP[i], DP[i - k] + abs(cur stone - stones[i - k]))

*/

#include <bits/stdc++.h>

int N, K;
std::vector<int> stones;
int DP [100001];

int main (){

    std::cin >> N >> K;
    stones.resize(N);
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < N; i++){
        std::cin >> stones[i];
    }

    for (int i = 1; i < N; i++){
        DP[i] = DP[i - 1] + abs(stones[i] - stones[i - 1]);
        for (int k = 2; k <= K && i - k >= 0; k++){
            DP[i] = std::min(DP[i], DP[i - k] + abs(stones[i] - stones[i - k]));
        }
    }

    std::cout << DP[N - 1] << '\n';
    
    return 0;
    
}