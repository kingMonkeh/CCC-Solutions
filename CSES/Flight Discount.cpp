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

dijkstra lmao 

method 1:

path consist of cities 1 --> A --> B --> n
where A and B are connected by an edge

do dijkstras twice
one with source from city 1
other with source from city n

afterward, try using coupon on every edge
cost is dist[1 --> A] + floor(cost(A, B) / 2) + dist[B --> n]

method 2
maintain one additional state in dijkstra which tells us if we have used the coupon yet

dist[i][2]
where dist[i][0] = dist to city i without using coupon
dist[i][1] = dist to city i having used coupon already

*/

int dist [100001], distN [100001];

struct cmp{
    bool operator ()(int& x, int& y){
        return dist[x] > dist[y];
    }
};

struct cmp2{
    bool operator ()(int& x, int& y){
        return distN[x] > distN[y];
    }
};

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<pii>> graph (n + 1), graph2 (n + 1);
        
        for (int i = 0; i < m; i++){
            int a, b, c;
            std::cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph2[b].push_back({a, c});
        }

        for (int i = 1; i <= n; i++){
            dist[i] = inf;
            distN[i] = inf;
        }
        
        //std::priority_queue<int, vi, cmp> pq;
        std::priority_queue<pii> pq;
        //pq.push(1);
        pq.push({0, 1});
        dist[1] = 0;

        /*
        while (!pq.empty()){
            int cur = pq.top();
            pq.pop();
            for (auto& edge: graph[cur]){
                if (dist[cur] + edge.s < dist[edge.f]){
                    dist[edge.f] = dist[cur] + edge.s;
                    pq.push(edge.f);
                }
            }
        }
        */

        while (!pq.empty()){
            pii cur_pos = pq.top();
            pq.pop();
            if (-cur_pos.f > dist[cur_pos.s]) continue;
            int cur = cur_pos.s;
            for (auto& edge: graph[cur]){
                if (dist[cur] + edge.s < dist[edge.f]){
                    pq.push({-(dist[cur] + edge.s), edge.f});
                    dist[edge.f] = dist[cur] + edge.s;
                }
            }
        }

        //std::priority_queue<int, vi, cmp2> pq2;
        std::priority_queue<pii> pq2;
        //pq2.push(n);
        pq2.push({0, n});
        distN[n] = 0;

        /*
        while (!pq2.empty()){
            int cur = pq2.top();
            pq2.pop();
            for (auto& edge: graph2[cur]){
                if (distN[cur] + edge.s < distN[edge.f]){
                    distN[edge.f] = distN[cur] + edge.s;
                    pq2.push(edge.f);
                }
            }
        }
        */

        while (!pq2.empty()){
            pii cur_pos = pq2.top();
            pq2.pop();
            if (-cur_pos.f > distN[cur_pos.s]) continue;
            int cur = cur_pos.s;
            for (auto& edge: graph2[cur]){
                if (distN[cur] + edge.s < distN[edge.f]){
                    pq2.push({-(distN[cur] + edge.s), edge.f});
                    distN[edge.f] = distN[cur] + edge.s;
                }
            }
        }

        int ans = inf;
        for (int i = 1; i < n; i++){
            for (auto& edge: graph[i]){
                if (dist[i] == inf || distN[edge.f] == inf) continue;
                ans = std::min(ans, dist[i] + edge.s / 2 + distN[edge.f]);
            }
        }

        std::cout << ans << '\n';

    }
    
    return 0;
    
}