#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

/*



*/

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;
        
        for (int i = 0; i < pow(2, n); i++){
            int x = i ^ (i >> 1);
            std::string s = "";
            for (int j = 0; j < n; j++){
                if (x % 2 == 1) s += '1';
                else s += '0';
                x /= 2;
            }
            for (int j = n - 1; j >= 0; j--) std::cout << s[j];
            std::cout << '\n';
        }   
        
    }

    return 0;
    
}