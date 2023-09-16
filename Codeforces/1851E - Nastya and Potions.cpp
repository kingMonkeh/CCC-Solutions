#include <bits/stdc++.h>

std::vector<std::vector<int>> graph;
std::vector<long long> c;
std::vector<long long> DP;

long long dfs (int cur){

    if (DP[cur] != -1){
        return DP[cur];
    }

    long long mix_cost = graph[cur].size() > 0 ? 0 : INT_MAX;
    for (int& req: graph[cur]) mix_cost += dfs(req);

    DP[cur] = std::min(c[cur], mix_cost);

    return DP[cur];
    
}

int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {
 
        int n, k;
        std::cin >> n >> k;

        graph.resize(n + 1);
        c.resize(n + 1);
        DP.resize(n + 1, -1);
        for (int i = 1; i <= n; i++) std::cin >> c[i];
        for (int i = 0; i < k; i++){
            int ind;
            std::cin >> ind;
            c[ind] = 0;
        }

        for (int i = 1; i <= n; i++){
            int m;
            std::cin >> m;
            while (m--){
                int e;
                std::cin >> e;
                graph[i].push_back(e);
            }
        }

        for (int i = 1; i <= n; i++){
            if (DP[i] == -1){
                dfs(i);
            }
            std::cout << DP[i] << ' ';
        } std::cout << '\n';

        graph.clear();
        c.clear();
        DP.clear();
        
    }
 
    return 0;
    
}