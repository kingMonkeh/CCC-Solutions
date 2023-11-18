#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX / 2
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

/*

bellman ford

*/

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        std::vector<vi> edges (m);
        for (int i = 0; i < m; i++){
            edges[i].resize(3);
            std::cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
            edges[i][2] *= -1;
        }

        vi dist (n + 1, inf);
        dist[1] = 0;
        for (int i = 0; i < n; i++){
            for (auto& edge: edges){
                if (dist[edge[0]] == inf) continue;
                if (dist[edge[0]] + edge[2] < dist[edge[1]]){
                    dist[edge[1]] = dist[edge[0]] + edge[2];
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (auto& edge: edges){
                if (dist[edge[0]] == inf) continue;
                if (dist[edge[0]] + edge[2] < dist[edge[1]]){
                    dist[edge[1]] = -inf;
                }
            }
        }
        
        std::cout << (dist[n] == -inf ? -1 : -dist[n]) << '\n';

    }
    
    return 0;
    
}