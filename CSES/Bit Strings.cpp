#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

int binpow (int x, int p){

    if (p == 0) return 1;
    else if (p == 1) return x;

    if (p % 2 == 0) return binpow(2, p / 2) * binpow(2, p / 2) % MOD;
    else return 2 * binpow(2, p - 1) % MOD;
    
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        std::cout << binpow(2, n);
        
    }

    return 0;
    
}