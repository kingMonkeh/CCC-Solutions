#include <bits/stdc++.h>

/*

Recursive dfs from node 1
Work bottom up
Apples[node] = sum of apples[children nodes]

*/

std::vector<std::vector<int>> graph;
long long apples [200001];

void dfs(int cur, int prev){
    //Child node that is not root
    if (cur != 1 && graph[cur].size() == 1){
        apples[cur] = 1;
    }
    for (auto child: graph[cur]){
        if (child != prev){
            dfs(child, cur);
            apples[cur] += apples[child];
        }
    }
}

int main (){ 
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        graph.clear();
        graph.resize(n + 1);
        memset(apples, 0, sizeof(apples));
        for (int i = 0; i < n - 1; i++){
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, -1);
        int q;
        std::cin >> q;
        for (int i = 0; i < q; i++){
            int x, y;
            std::cin >> x >> y;
            std::cout << apples[x] * apples[y] << '\n';
        }
    }
    return 0;
}