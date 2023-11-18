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

/*

basic dijkstra's

*/

const int MOD = 1e9 + 7;

vi dist;

struct cmp{
    bool operator ()(int& x, int& y){
        return dist[x] > dist[y];
    }
};

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<pii>> graph (n + 1);

        for (int i = 0; i < m; i++){
            int a, b, c;
            std::cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }

        dist.resize(n + 1, inf);
        
        std::priority_queue<int, vi, cmp> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()){
            int cur = q.top();
            q.pop();
            for (auto& e: graph[cur]){
                if (dist[e.f] > dist[cur] + e.s){
                    q.push(e.f);
                    dist[e.f] = dist[cur] + e.s;
                }
            }
        }

        for (int i = 1; i <= n; i++) std::cout << dist[i] << ' ';
        
    }
    
    return 0;
    
}