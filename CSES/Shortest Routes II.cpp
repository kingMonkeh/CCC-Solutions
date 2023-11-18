#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
//#define inf LONG_LONG_MAX
#define inf LONG_LONG_MAX / 2
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

/*

floyd warshall

*/

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m, q;
        std::cin >> n >> m >> q;

        std::vector<vi> dist (n + 1, vi (n + 1, inf));
        for (int i = 0; i < m; i++){
            int a, b, c;
            std::cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }

        for (int k = 1; k <= n; k++){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if (dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        while (q--){
            int a, b;
            std::cin >> a >> b;
            int ans = std::min(dist[a][b], dist[b][a]);
            std::cout << (dist[a][b] == inf ? -1 : ans) << '\n';
        }

    }
    
    return 0;
    
}