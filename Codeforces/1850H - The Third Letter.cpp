/*

Create some weighted edges

think about it like this

lets just start with soldier 1, assume hes at cord 0
then using dfs, we will just assume everyone elses position based off of where soldier 1 is standing
for example if soldier 1 is at camp 0, and soldier 2 must be 2 behind
we'll just say that soldier 2 is at -2
then for all soldiers connected to soldier 2, we will just assume their pos based off of our current assumption

if all the conditions work out
then at the end, everyones position should still work, otherwise someone is not in the correct pos

*/

#include <bits/stdc++.h>
 
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<long long> pos;
 
void dfs (int cur, int prev){
    
    for (auto& edge: graph[cur]){
        if (pos[edge.first] == -INT_MAX && edge.first != prev){
            pos[edge.first] = (long long) pos[cur] + edge.second;
            dfs(edge.first, cur);
        }
    }
    
}
 
int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {
        
        int n, m;
        std::cin >> n >> m;
 
        graph.resize(n + 1);
        pos.resize(n + 1, -INT_MAX);
        std::vector<std::vector<int>> conditions (m);
        
        for (int i = 0; i < m; i++){
            int a, b, d;
            std::cin >> a >> b >> d;
            conditions[i] = {a, b, d};
            graph[a].push_back(std::make_pair(b, -d));
            graph[b].push_back(std::make_pair(a, d));
        }
 
        for (int i = 1; i <= n; i++){
            if (pos[i] == -INT_MAX){
                pos[i] = 0;
                dfs(i, i);
            }
        }
 
        for (auto& cond: conditions){
            if (pos[cond[0]] - pos[cond[1]] != cond[2]){
                std::cout << "NO\n";
                goto nxt;
            }
        }
 
        std::cout << "YES\n";
 
        nxt:;
 
        graph.clear();
        pos.clear();
        
    }
 
    return 0;
    
}