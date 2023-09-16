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

        int n, m, k;
        std::cin >> n >> m >> k;

        vi a (n), b (m);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < m; i++) std::cin >> b[i];

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++){
            while (b[j] <= a[i] + k && j < m){
                if (a[i] - k <= b[j] && b[j] <= a[i] + k){
                    ans++;
                    j++;
                    break;
                }
                j++;
            }
        }

        std::cout << ans << '\n';

    }

    return 0;
    
}