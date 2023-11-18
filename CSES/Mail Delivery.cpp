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

Eulerian Circuit

*/

std::vector<std::pair<int, int>> graph [100001];

int deg [100001] = {0}, vis [200001] = {0};

std::vector<int> circuit;

void dfs (int cur){

    while(!graph[cur].empty()){
        auto edge = graph[cur].back();
        graph[cur].pop_back();
        if (!vis[edge.s]){
            vis[edge.s] = true;
            dfs(edge.f);
        }
    }

    circuit.push_back(cur);
    
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

        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back({b, i}); //edge of form {dest, id of edge}
            graph[b].push_back({a, i});
            deg[a]++;
            deg[b]++;
        }

        //for a eulerian circuit to exist, all nodes must have an even degree
        for (int i = 1; i <= n; i++){
            if (deg[i] % 2 != 0){
                std::cout << "IMPOSSIBLE";
                return 0;
            }
        }

        dfs(1);

        if (circuit.size() != m + 1){
            std::cout << "IMPOSSIBLE";
        }
        else{
            for (auto& a: circuit) std::cout << a << ' ';
        }
        
    }
    
    return 0;
    
}