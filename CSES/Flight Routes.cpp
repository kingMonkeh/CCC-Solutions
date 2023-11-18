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

k shortest paths

let dist[i][k] tell us the kth best distance to reach city i

modified dijkstras

if our current state distance is better than the worst distance for city i, we should take it since it will improve it

*/

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::vector<pii>> graph (n + 1);

        for (int i = 0; i < m; i++){
            int a, b, c;
            std::cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }

        std::vector<vi> dist (n + 1, vi (k, inf));

        std::priority_queue<pii> pq;
        pq.push({0, 1});

        //use negative distance for simpler priority queue implementation
        while (!pq.empty()){
            pii state = pq.top();
            pq.pop();
            int cur = state.s, d = state.f;
            if (-d > dist[cur][k - 1]) continue;
            for (auto& edge: graph[cur]){
                if (-(d - edge.s) < dist[edge.f][k - 1]){
                    pq.push({d - edge.s, edge.f});
                    dist[edge.f][k - 1] = -(d - edge.s);
                    std::sort(dist[edge.f].begin(), dist[edge.f].end());
                }
            }
        }

        for (int i = 0; i < k; i++){
            std::cout << dist[n][i] << ' ';
        }

    }
    
    return 0;
    
}