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

        int n;
        std::cin >> n;

        int ans = 0;
        std::map<int, int> found;
        for (int i = 0; i < n; i++){
            int x;
            std::cin >> x;
            if (!found[x]){
                ans++;
                found[x] = true;
            }
        }

        std::cout << ans << '\n';
        
    }

    return 0;
    
}