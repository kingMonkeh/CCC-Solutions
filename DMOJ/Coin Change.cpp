#include <iostream>
#include <algorithm>
#include <string.h>

int main(){
    
    int x, n;
    std::cin >> x >> n;

    int denominators[n];
    for (int i = 0; i < n; i++){
        std::cin >> denominators[i];
    }

    int DP[x + 1];
    memset(DP, 999999, sizeof(DP));
    DP[0] = 0;

    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (i - denominators[j] >= 0 && DP[i - denominators[j]] != 999999){
                DP[i] = std::min(DP[i], DP[i - denominators[j]] + 1);
            }
        }
    }

    std::cout << DP[x] << '\n';
    return 0;
    
}