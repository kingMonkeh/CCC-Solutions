#include <bits/stdc++.h>

//bait constraints, you will find answer very fast

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int l, r;
        std::cin >> l >> r;

        int car;
        int ans = -1;
        for (int i = l; i <= r; i++){
            int _i = i;
            int big = 0, small = 9;
            while (_i){
                big = std::max(big, _i % 10);
                small = std::min(small, _i % 10);
                _i /= 10;
            }
            if (abs(big - small) > ans){
                ans = abs(big - small);
                car = i;
            }
            if (ans == 9) break;
        }

        std::cout << car << '\n';
        
    }
    
    return 0;
    
}