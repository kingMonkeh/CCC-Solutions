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

signed main (){
 
    std::ios_base::sync_with_stdio(false);
   
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
   
        int n, m;
        std::cin >> n >> m;

        std::vector<vi> graph (n + 1);
        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vi dist (n + 1, -1), vis (n + 1, 0);
        std::vector<int> par (n + 1);
        std::queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (auto& dest: graph[cur]){
                if (!vis[dest]){
                    vis[dest] = 1;
                    dist[dest] = dist[cur] + 1;
                    par[dest] = cur;
                    q.push(dest);
                }
            }
        }

        if (dist[n] == -1){
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }

        std::stack<int> s;
        s.push(n);
        int pos = n;
        while (pos != 1){
            s.push(par[pos]);
            pos = par[pos];
        }

        std::cout << s.size() << '\n';
        while (s.size()){
            std::cout << s.top() << ' ';
            s.pop();
        }
       
    }
   
    return 0;
   
}
