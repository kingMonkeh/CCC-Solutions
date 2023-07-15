#include <bits/stdc++.h>

/*

Let DP[i] be the max length path obtainable starting from node i

if node i has parent node j
then DP[j] = DP[i] + 1

Basically just dfs from every node if you havent visited this node already

*/

std::vector<int> graph [100001];
std::vector<bool> vis (100001, false);
int DP [100001];

void dfs (int cur){

    DP[cur] = 0;
    vis[cur] = true;
    
    for (auto adj: graph[cur]){
        if (!vis[adj]) dfs(adj);
        DP[cur] = std::max(DP[cur], DP[adj] + 1);
    }
    
}

int main(){

    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++){
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i = 1; i <= N; i++){
        dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        ans = std::max(ans, DP[i]);
    }

    std::cout << ans << '\n';
    
    return 0;
    
}