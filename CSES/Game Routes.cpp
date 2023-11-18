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

topological sort

dfs dp

*/

std::vector<vi> graph;
vi DP;

int dfs (int cur){

    if (DP[cur] != -1) return DP[cur];

    if (graph[cur].empty()) return DP[cur] = 0;

    DP[cur] = 0;
    for (auto& adj: graph[cur]){
        DP[cur] += dfs(adj);
        DP[cur] %= MOD;
    } 

    return DP[cur];
    
}

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
            int a, b;
            std::cin >> a >> b;
            graph[b].push_back(a);
        }

        DP.resize(n + 1, -1);
        DP[1] = 1;
        std::cout << dfs(n);
        
    }
    
    return 0;
    
}