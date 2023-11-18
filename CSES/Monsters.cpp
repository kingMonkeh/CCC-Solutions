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

/*

note that we cannot go to a square if a monster can reach that square before us
mathematically if the distance between us to a square is greater than that of a monsters, we cannot go to that square since the monster can spawn kill us

therefore, bfs from every monster to determine the dist of the closest monster to every square

afterward we can perform a second bfs as the player and use our logic from earlier to avoid getting hit by monsters

to track path we can maintain parent vector and backtrack

*/

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        std::queue<pii> q;
        std::vector<vi> monster_dist (n + 2, vi (m + 2, inf));
        std::vector<vi> dist (n + 2, vi (m + 2, -1));
        std::vector<std::vector<std::pair<pii, char>>> par (n + 2, std::vector<std::pair<pii, char>> (m + 2));

        pii start;
        std::vector<std::vector<char>> grid (n + 2, std::vector<char> (m + 2, '#'));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                std::cin >> grid[i][j];
                if (grid[i][j] == 'M'){
                    q.push({i, j});
                    monster_dist[i][j] = 0;
                }
                else if (grid[i][j] == 'A'){
                    start = {i, j};
                    dist[i][j] = 0;
                }
            }
        }

        char dir [4] = {'U', 'D', 'L', 'R'};
        int y [4] = {-1, 1, 0, 0};
        int x [4] = {0, 0, -1, 1};
        while (!q.empty()){
            pii cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++){
                if (monster_dist[cur.f + y[i]][cur.s + x[i]] == inf && grid[cur.f + y[i]][cur.s + x[i]] == '.'){
                    q.push({cur.f + y[i], cur.s + x[i]});
                    monster_dist[cur.f + y[i]][cur.s + x[i]] = monster_dist[cur.f][cur.s] + 1;
                }
            }
        }

        q.push(start);
        while (!q.empty()){
            pii cur = q.front();
            q.pop();
            if (cur.f == 1 || cur.f == n || cur.s == 1 || cur.s == m){
                std::stack<char> s;
                pii pos = cur;
                while (pos != start){
                    s.push(par[pos.f][pos.s].s);
                    pos = par[pos.f][pos.s].f;
                }
                std::cout << "YES\n" << s.size() << '\n';
                while (!s.empty()){
                    std::cout << s.top();
                    s.pop();
                }
                return 0;
            }
            for (int i = 0; i < 4; i++){
                if (monster_dist[cur.f + y[i]][cur.s + x[i]] > dist[cur.f][cur.s] + 1 && dist[cur.f + y[i]][cur.s + x[i]] == -1 && grid[cur.f + y[i]][cur.s + x[i]] == '.'){
                    q.push({cur.f + y[i], cur.s + x[i]});
                    dist[cur.f + y[i]][cur.s + x[i]] = dist[cur.f][cur.s] + 1;
                    par[cur.f + y[i]][cur.s + x[i]] = {{cur.f, cur.s}, dir[i]};
                }
            }
        }

        std::cout << "NO\n";
        
    }
    
    return 0;
    
}