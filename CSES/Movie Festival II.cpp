#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

signed main (){

    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
        
        int n, k;
        std::cin >> n >> k;

        std::vector<std::pair<int, int>> movies (n);
        for (int i = 0; i < n; i++){
            std::cin >> movies[i].f >> movies[i].s;
        }

        std::sort(movies.begin(), movies.end(), [](std::pair<int, int>& x, std::pair<int, int>& y){
            return x.s == y.s ? x.f < y.f : x.s < y.s;
        });

        std::multiset<int> ms;
        for (int i = 0; i < k; i++) ms.insert(0);
        int ans = 0, time = 0;
        for (int i = 0; i < n; i++){
            //find person who finishes movie closest to the start of this one
            auto it = ms.upper_bound(movies[i].first);
            if (it == ms.begin()) continue;
            ms.erase(--it);
            ms.insert(movies[i].s);
            ans++;
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}