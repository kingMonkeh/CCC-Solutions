#include <bits/stdc++.h>

/*

Find a leaf node
The only node connected to it is a node connected to the root
Iterate through this node, it will be surrounded to all leaf nodes and the root

Skip the leaf nodes and pick the root

x = the number of nodes connected to the root
therefore y = (total nodes - nodes connected to root - root itself) / x

*/

int main(){

    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--){

        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> graph (n + 1);

        for (int i = 0; i < m; i++){
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int root;
        for (int i = 1; i <= n; i++){
            if (graph[i].size() == 1){
                int root2 = graph[i][0];
                for (auto& node: graph[root2]){
                    if (graph[node].size() != 1){
                        root = node;
                        goto nxt;
                    }
                }
            }
        }

        nxt:;
        int x = graph[root].size();
        int y = (n - x - 1) / x;

        std::cout << x << ' ' << y << '\n';
        
            
    }
    
}