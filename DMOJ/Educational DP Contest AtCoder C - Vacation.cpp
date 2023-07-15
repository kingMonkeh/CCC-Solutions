/*

idea
let DP[i][j] tell us max total value for all days up to and including day i, picking activity j as the activity for day i

Due to the restriction that we cannot pick the same activity two days in a row
Then DP[i][j] = activity + max(DP[i - 1][other activity], DP[i - 1][other other activity])

*/

#include <bits/stdc++.h>

int N;
int DP [100001][3];

int main (){

    std::cin >> N;
    std::vector<std::vector<int>> days (N);
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < N; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        days[i] = {a, b, c};
    }
    
    //let 0 = a, 1 = b, 2 = c
    DP[0][0] = days[0][0], DP[0][1] = days[0][1], DP[0][2] = days[0][2];
    for (int i = 1; i < N; i++){
        for (int j = 0; j < 3; j++){
            DP[i][j] = days[i][j] + std::max(DP[i - 1][(j + 1) % 3], DP[i - 1][(j + 2) % 3]);
        }
    }

    int ans = 0;
    for (int j = 0; j < 3; j++) ans = std::max(ans, DP[N - 1][j]);
    std::cout << ans << '\n';
    
    return 0;
    
}