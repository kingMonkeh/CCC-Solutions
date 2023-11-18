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

graph is acyclic and directed, DP can be applied

dfs dp

*/

std::vector<vi> graph;
vi DP, par;

int dfs (int cur){

    if (DP[cur] != -1) return DP[cur];

    if (graph[cur].empty()) return DP[cur] = -inf;

    for (auto& adj: graph[cur]){
        if (dfs(adj) + 1 > DP[cur]){
            DP[cur] = dfs(adj) + 1;
            par[cur] = adj;
        }
    } 

    return DP[cur] == -1 ? DP[cur] = -inf : DP[cur];
    
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

        graph.resize(n + 1);
        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[b].push_back(a);
        }

        par.resize(n + 1);
        DP.resize(n + 1, -1);
        DP[1] = 0;
        dfs(n);

        if (DP[n] < 0)
            std::cout << "IMPOSSIBLE\n";
        else{
            vi ans;
            int pos = n;
            while (pos != 1){
                ans.push_back(pos);
                pos = par[pos];
            } ans.push_back(1);
            std::cout << ans.size() << '\n';
            for (int i = ans.size() - 1; i >= 0; i--) std::cout << ans[i] << ' ';
        }
        
    }
    
    return 0;
    
}