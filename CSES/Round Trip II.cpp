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

topological sort

*/

std::vector<vi> graph;
vi vis, on_stack, cycle;

bool dfs (int cur){

    vis[cur] = on_stack[cur] = true;

    for (auto& adj: graph[cur]){
        //cycle
        if (on_stack[adj]){
            on_stack[cur] = on_stack[adj] = false;
            cycle.push_back(cur);
            return true;
        }
        else if (!vis[adj]){
            if (dfs(adj)){
                //part of the cycle
                if (on_stack[cur]){
                    on_stack[cur] = false;
                    cycle.push_back(cur);
                    return true;
                }
                else{
                    cycle.push_back(cur);
                    return false;
                }
            }
            if (cycle.size()) return false;
        }
    }

    on_stack[cur] = false;
    return false;
    
}

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        vis.resize(n + 1, 0);
        on_stack.resize(n + 1, 0);

        graph.resize(n + 1);
        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
        }

        for (int i = 1; i <= n; i++){
            if (!vis[i] && cycle.empty()) dfs(i);
        }

        if (!cycle.size()) std::cout << "IMPOSSIBLE\n";
        else{
            std::reverse(cycle.begin(), cycle.end());
            std::cout << cycle.size() + 1 << '\n';
            for (auto& u: cycle) std::cout << u << ' ';
            std::cout << cycle[0];
        }

    }
    
    return 0;
    
}