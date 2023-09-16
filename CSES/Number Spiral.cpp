#include <bits/stdc++.h>

#define int long long

signed main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int r, c;
        std::cin >> r >> c;
    
        int cur_r = std::max(r, c), cur_c = std::max(r, c);
        int n = std::max(r, c) - 1, d = 2, a = 2;
        int val = 1;

        //notice diagonal pattern, arithmetic series with a = 2, d = 2, n = max(r, c) - 1
        val += n * ((2 * a) + ((n - 1) * d)) / 2;
    
        if (cur_r != r){
            int diff = llabs(cur_r - r);
            if (c % 2 == 0) val -= diff;
            else val += diff;
        }
    
        if (cur_c != c){
            int diff = llabs(cur_c - c);
            if (r % 2 == 0) val += diff;
            else val -= diff;
        }
    
        std::cout << std::fixed << std::setprecision(0) <<  val << '\n';
        
    }

    return 0;
    
}