#include <iostream>
#include <algorithm>
#include <string.h>

int main(){
    
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    int DP[N + 1];
    memset(DP, -1, sizeof(DP));
    DP[0] = 0;

    for (int i = 1; i <= N; i++){
        if (i - X >= 0 && DP[i - X] != -1){
            DP[i] = std::max(DP[i], DP[i - X] + 1);
        }
        if (i - Y >= 0 && DP[i - Y] != -1){
            DP[i] = std::max(DP[i], DP[i - Y] + 1);
        }
        if (i - Z >= 0 && DP[i - Z] != -1){
           DP[i] = std::max(DP[i], DP[i - Z] + 1); 
        }
    }

    std::cout << DP[N] << '\n';
    return 0;
    
}