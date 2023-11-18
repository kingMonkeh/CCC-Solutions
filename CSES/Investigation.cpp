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

const int MOD = 1e9 + 7;

/*

dijkstra haha

keep track of additional info using more vectors

*/

std::vector<std::vector<pii>> graph;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        graph.resize(n + 1);
        for (int i = 0; i < m; i++){
            int a, b, c;
            std::cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }

        std::priority_queue<pii> pq;
        pq.push({0, 1});

        vi dist (n + 1, inf), ways (n + 1, 0), mn_len (n + 1), mx_len (n + 1);
        //base case 0 dist, 1 way, 0 flights taken so far
        dist[1] = 0; ways[1] = 1; mn_len[1] = 0; mx_len[1] = 0;
        while (!pq.empty()){
            pii state = pq.top();
            pq.pop();
            int d = state.f, cur = state.s;
            //if suboptimal state, just exit early
            if (-d > dist[cur]) continue;
            //for every neighbour
            for (auto& edge: graph[cur]){
                //better
                //we have to overwrite the data as the shortest path has completely changed
                if (dist[cur] + edge.s < dist[edge.f]){
                    pq.push({-dist[cur] - edge.s, edge.f});
                    dist[edge.f] = dist[cur] + edge.s;
                    ways[edge.f] = ways[cur];
                    mn_len[edge.f] = mn_len[cur] + 1;
                    mx_len[edge.f] = mx_len[cur] + 1;
                }
                //equal
                //if equal, we can combine data instead of overwriting
                else if (dist[cur] + edge.s == dist[edge.f]){
                    //add ways and modulo
                    ways[edge.f] += ways[cur];
                    ways[edge.f] %= MOD;
                    mn_len[edge.f] = std::min(mn_len[edge.f], mn_len[cur] + 1);
                    mx_len[edge.f] = std::max(mx_len[edge.f], mx_len[cur] + 1);
                }
            }
        }

        std::cout << dist[n] << ' ' << ways[n] << ' ' << mn_len[n] << ' ' << mx_len[n];
        
    }
    
    return 0;
    
}