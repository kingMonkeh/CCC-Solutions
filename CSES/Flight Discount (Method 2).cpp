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

const int MOD = 1e9 + 7;

struct state{

    int pos, dist, used;

    bool operator < (const state& x) const {
        return this->dist > x.dist;
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
        
        std::vector<vi> dist (n + 1, vi (2, inf));
        dist[1][0] = 0;

        state start;
        start.pos = 1;
        start.dist = 0;
        start.used = 0;
        
        std::priority_queue<state> pq;
        pq.push(start);

        while (!pq.empty()){

            state cur = pq.top();
            pq.pop();

            if (cur.dist != dist[cur.pos][cur.used]){
                continue;
            }

            for (auto& edge: graph[cur.pos]){
                if (dist[cur.pos][cur.used] + edge.s < dist[edge.f][cur.used]){
                    state next;
                    next.pos = edge.f;
                    next.dist = dist[cur.pos][cur.used] + edge.s;
                    next.used = cur.used;
                    dist[edge.f][cur.used] = next.dist;
                    pq.push(next);
                }
                if (!cur.used && dist[cur.pos][cur.used] + edge.s / 2 < dist[edge.f][!cur.used]){
                    state next;
                    next.pos = edge.f;
                    next.dist = dist[cur.pos][cur.used] + edge.s / 2;
                    next.used = !cur.used;
                    dist[edge.f][!cur.used] = next.dist;
                    pq.push(next);
                }
            }
            
        }

        std::cout << dist[n][1] << '\n';

    }
    
    return 0;
    
}