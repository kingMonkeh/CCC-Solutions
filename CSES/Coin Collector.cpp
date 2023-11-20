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

Idea:

We're trying to maximize a value, this hints at DP

But you can only use DP on Directed Acyclic Graphs

For this reason, if we group the nodes into their own Strongly Connected Components
And then form the graph of the components.

Then a Directed Acyclic Graph is formed, that DP can be performed upon
Since every node in a SCC can reach all the others, then we can say that the value of an SCC is the sum of all the coins in each of its rooms.

*/

int k [100001], vis[100001], id[100001], sccvalue[100001], DP[100001];
vi graph [100001], rgraph[100001], SCC_graph[100001];
vi comp;
std::stack<int> s;

void dfs1 (int cur){
    vis[cur] = true;
    for (auto& adj: graph[cur]){
        if (!vis[adj]) dfs1(adj);
    }
    s.push(cur);
}

void dfs2 (int cur){
    vis[cur] = true;
    comp.push_back(cur);
    for (auto& adj: rgraph[cur]){
        if (!vis[adj]) dfs2(adj);
    }
}

int dfs3 (int cur){
    if (DP[cur] != -1) return DP[cur];
    int mx = 0;
    for (auto& adj: SCC_graph[cur]){
        mx = std::max(mx, dfs3(adj));
    }
    return DP[cur] = mx + sccvalue[cur];
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        for (int i = 1; i <= n; i++) std::cin >> k[i];

        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            rgraph[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) vis[i] = false;
        for (int i = 1; i <= n; i++){
            if (!vis[i]) dfs1(i);
        }

        //Form SCC
        for (int i = 1; i <= n; i++) vis[i] = false;
        int cur_scc = 1;
        while (!s.empty()){
            int cur = s.top();
            s.pop();
            if (vis[cur]) continue;
            dfs2(cur);
            for (auto& a: comp){
                id[a] = cur_scc;
                sccvalue[cur_scc] += k[a];
            }
            cur_scc++;
            comp.clear();
        }

        //Create DAG of SCC
        for (int i = 1; i <= n; i++){
            for (auto& adj: graph[i]){
                if (id[i] != id[adj]){
                    SCC_graph[id[i]].push_back(id[adj]);
                }
            }
        }

        //DP DFS
        int ans = 0;
        for (int i = 1; i <= n; i++) DP[i] = -1;
        for (int i = 1; i < cur_scc; i++){
            if (DP[i] == -1) ans = std::max(ans, dfs3(i)); 
        }

        std::cout << ans;
        
    }
    
    return 0;
    
}