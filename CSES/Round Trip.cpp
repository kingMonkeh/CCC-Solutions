#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
 
#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
 
const int MOD = 1e9 + 7;
 
signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;
 
        std::vector<vi> graph (n + 1);
        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
 
        vi part1, part2;
        vi dist (n + 1, 0), par (n + 1);
        for (int i = 1; i <= n; i++){
            //if unvisited
            if (dist[i] == 0){
                //do bfs
                std::queue<int> q;
                q.push(i);
                dist[i] = 1;
                while (!q.empty()){
                    int cur = q.front();
                    q.pop();
                    //for all adjacent
                    for (auto& f: graph[cur]){
                        //if already visited cell, then cycle is found
                        //backtrack path
                        if (dist[f] > 1 && f != par[cur]){
                            //two pointer
                            //p1 is the already visited node, p2 is the cur node which can also visit the already visited node
                            int p1 = f, p2 = cur;
                            part2.push_back(f);
                            //make sure they are the same level
                            while (dist[p2] > dist[p1]){
                                part2.push_back(p2);
                                p2 = par[p2];
                            }
                            while (dist[p1] > dist[p2]){
                                part1.push_back(p1);
                                p1 = par[p1];
                            }
                            //go down until they meet the same root again
                            while (par[p1] != par[p2]){
                                part1.push_back(p1);
                                part2.push_back(p2);
                                p1 = par[p1];
                                p2 = par[p2];
                            }
                            part1.push_back(p1);
                            part2.push_back(p2);
                            part1.push_back(par[p1]);
                            std::cout << part1.size() + part2.size() << '\n';
                            for (int i = 0; i < part1.size(); i++) std::cout << part1[i] << ' ';
                            for (int i = part2.size() - 1; i >= 0; i--) std::cout << part2[i] << ' ';
                            return 0;
                        } 
                        //continue bfs
                        else if (dist[f] == 0){
                            dist[f] = dist[cur] + 1;
                            par[f] = cur;
                            q.push(f);
                        }
                    }
                }
            }
        }
 
        std::cout << "IMPOSSIBLE";
        
    }
    
    return 0;
    
}
