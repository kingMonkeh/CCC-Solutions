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

strongly connected components

kosaraju algorithm

tarjan also works

*/

std::vector<vi> graph, rgraph;
vi vis, kingdom;
std::stack<int> s;

void dfs1 (int cur){

    vis[cur] = true;

    for (auto& adj: graph[cur]){
        if (!vis[adj]) dfs1(adj);
    }

    s.push(cur);

}

void dfs2 (int cur, int k){

    vis[cur] = true;
    kingdom[cur] = k;
    
    for (auto& adj: rgraph[cur]){
        if (!vis[adj]) dfs2(adj, k);
    }

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

        graph.resize(n + 1);
        rgraph.resize(n + 1);

        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            rgraph[b].push_back(a);
        }

        kingdom.resize(n + 1);
        vis.resize(n + 1, false);

        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                dfs1(i);
            }
        }

        /*
        while (!s.empty()){
            std::cout << s.top() << ' ';
            s.pop();
        }
        */

        for (int i = 1; i <= n; i++) vis[i] = false;

        int k = 1;
        while (!s.empty()){
            if (vis[s.top()]){
                s.pop();
                continue;
            }
            int cur = s.top();
            dfs2(cur, k);
            k++;
        }

        std::cout << --k << '\n';
        for (int i = 1; i <= n; i++) std::cout << kingdom[i] << ' ';
        
    }
    
    return 0;
    
}