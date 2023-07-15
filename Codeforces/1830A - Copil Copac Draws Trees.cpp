#include <bits/stdc++.h>

/*

dp problem, like actually this time

let dp[i] tell us the total number of readings required to draw vertex i
let id[i] tell us which edge activated vertex i, based on the user input

we notice that given an edge {u, v}
if (id[v] > id[u]) aka it comes after the edge that activated 
then we can also activate v as well in the same reading
therefore dp[v] = dp[u]

else
we must perform another reading before being able to activate v
therefore dp[v] = dp[u] + 1

in all cases however
id[v] = edge index

*/

int DP[200001], id[200001];
std::vector<std::vector<std::pair<int, int>>> graph;

void dfs (int cur){

    for (auto& edge: graph[cur]){
        //if not visited
        if (DP[edge.first] == 0){
            //edge comes before the one that activated cur
            //we must do anotehr reading
            if (edge.second < id[cur]){
                DP[edge.first] = DP[cur] + 1;
            }
            //we can do it in teh same reading
            else{
                DP[edge.first] = DP[cur];
            }
            id[edge.first] = edge.second; //set edge
            dfs(edge.first); //dfs further
        }
    }
    
}

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        graph.resize(n + 1);
        for (int i = 0; i <= n; i++) DP[i] = id[i] = 0;

        for (int i = 0; i < n - 1; i++){
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back({v, i}); //maintain dest and edge index
            graph[v].push_back({u, i});
        }

        DP[1] = 1; //base case
        dfs(1);
            
        int ans = 0; 
        for (int i = 1; i <= n; i++) ans = std::max(ans, DP[i]); //take max
        
        std::cout << ans << '\n';

        graph.clear();
        
    }

    return 0;
    
}