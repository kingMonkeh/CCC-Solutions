#include <bits/stdc++.h>

/*



*/

int main (){

    int N, M;
    std::cin >> N >> M;
    long long A [N];
    for (int i = 0; i < N; i++){
        std::cin >> A[i];
    }

    long long DP [N][M];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) DP[i][j] = -LONG_LONG_MAX;
    DP[0][0] = A[0];
    for (int i = 1; i < N; i++){
        DP[i][0] = std::max(DP[i - 1][0], A[i]);
        for (int j = 1; j < M && j <= i; j++){
            //Choose to take or not take
            DP[i][j] = std::max(DP[i - 1][j], DP[i - 1][j - 1] + A[i] * (j + 1));
        }
    }

    long long ans = -LONG_LONG_MAX;
    for (int i = 0; i < N; i++){
        ans = std::max(ans, DP[i][M - 1]);
    }

    std::cout << ans << '\n';
    
    return 0;
    
}