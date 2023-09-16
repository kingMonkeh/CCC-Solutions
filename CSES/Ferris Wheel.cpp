#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
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

        int n, x;
        std::cin >> n >> x;

        vi p (n);
        for (int i = 0; i < n; i++) std::cin >> p[i];

        std::sort(p.begin(), p.end());
        int i = 0, j = n - 1, ans = 0;
        while (i < j){
            if (p[i] + p[j] > x){
                ans++;
                j--;
            }
            else{
                i++;
                j--;
                ans++;
            }
        }

        if (i == j) ans++;

        std::cout << ans << '\n';

    }

    return 0;
    
}