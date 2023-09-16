#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

/*

1 * 9
2 * 90
3 * 900
4 * 9000
5 * 90000

*/

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int q;
        std::cin >> q;

        while (q--){
            
            int k;
            std::cin >> k;

            int tot = 9, dig = 1;
            while (k - (tot * dig) >= 0){
                k -= tot * dig;
                dig++;
                tot *= 10;
            }

            
            int num = 1;
            for (int i = 0; i < dig - 1; i++) num *= 10;
            num += k / dig;
            if (k % dig == 0){
                num--;
                std::cout << num % 10 << '\n';
                continue;
            }
            for (int i = 0; i < dig - (k % dig); i++){
                num /= 10;
            }

            std::cout << num % 10 << '\n';
            
        }
        
    }

    return 0;
    
}