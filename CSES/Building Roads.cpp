#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

int par [100001];

int root (int x){
   return par[x] == x ? x : par[x] = root(par[x]);
}

void merge (int x, int y){
    x = root(x);
    y = root(y);
    par[y] = x;
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
   
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
   
        int n, m;
        std::cin >> n >> m;

        for (int i = 1; i <= n; i++){
            par[i] = i;
        }

        for (int i = 0; i < m; i++){
            int x, y;
            std::cin >> x >> y;
            if (root(x) != root(y)) merge(x, y);
        }

        std::vector<pii> roads;
        int ans = 0;
        for (int i = 2; i <= n; i++){
            if (root(i - 1) != root(i)){
                merge(i - 1, i);
                ans++;
                roads.push_back({i - 1, i});
            }
        }

        std::cout << ans << '\n';
        for (auto& p: roads){
            std::cout << p.f << ' ' << p.s << '\n';
        }
       
    }
   
    return 0;
   
}