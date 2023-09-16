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

        pii start, end;
        std::vector<std::vector<char>> grid (n, std::vector<char> (m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                std::cin >> grid[i][j];
                if (grid[i][j] == 'A'){
                    start = {i, j};
                }
                else if (grid[i][j] == 'B'){
                    end = {i, j};
                }
            }
        }

        int up [4] = {-1, 1, 0, 0};
        int side [4] = {0, 0, -1, 1};
        std::string way = "UDLR";
        
        std::queue<pii> q; //row, col
        std::vector<vi> vis (n, vi (m, 0)), dist (n, vi (m));
        //keep track of parent node and what dir was taken
        std::vector<std::vector<std::pair<pii, char>>> dir (n, std::vector<std::pair<pii, char>> (m));

        //init
        q.push(start);
        dist[start.f][start.s] = 0;
        vis[start.f][start.s] = 1;

        //bfs
        while (!q.empty()){
            pii cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k++){
                if (cur.f + up[k] < n && cur.f + up[k] >= 0 && cur.s + side[k] >= 0 && cur.s + side[k] < m && grid[cur.f + up[k]][cur.s + side[k]] != '#' && !vis[cur.f + up[k]][cur.s + side[k]]){
                    q.push({cur.f + up[k], cur.s + side[k]});
                    vis[cur.f + up[k]][cur.s + side[k]] = 1;
                    dist[cur.f + up[k]][cur.s + side[k]] = dist[cur.f][cur.s] + 1;
                    dir[cur.f + up[k]][cur.s + side[k]].s = way[k];
                    dir[cur.f + up[k]][cur.s + side[k]].f = cur;
                }
            }
        }

        if (!vis[end.f][end.s]){
            std::cout << "NO";
            return 0;
        }

        std::cout << "YES\n" << dist[end.f][end.s] << '\n';

        std::stack<char> direction;
        pii pos = end;
        //backtrack using parent node info
        while (pos != start){
            direction.push(dir[pos.f][pos.s].s);
            pos = dir[pos.f][pos.s].f;
        }

        //output the new direction set 
        while (!direction.empty()){
            std::cout << direction.top();
            direction.pop();
        }
        
    }
    
    return 0;
    
}