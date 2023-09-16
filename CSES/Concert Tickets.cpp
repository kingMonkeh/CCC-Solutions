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

        int n, m;
        std::cin >> n >> m;

        std::multiset<int> h;
        vi t (m);

        for (int i = 0; i < n; i++){
            int num;
            std::cin >> num;
            h.insert(num);
        }

        for (int i = 0; i < m; i++){
            std::cin >> t[i];
            auto res = h.upper_bound(t[i]);
            if (res == h.begin()){
                std::cout << -1 << '\n';
            }
            else{
                res--;
                std::cout << *res << '\n';
                h.erase(res);
            }
        }

    }

    return 0;
    
}