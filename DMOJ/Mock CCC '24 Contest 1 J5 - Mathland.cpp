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

there are only like 4 configurations of the grid, since its rotated 90 degrees clockwise and repeats every 4 rotations
just do bfs, but we need to differentiate different states

most important things to keep track
current grid, row, column, distance, and step #

*/

char grid [4][800][800];
int dist [4][10][800][800];

struct state{
    int x, i, j, dist, k;
};

signed main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        for (int i = 0; i < 4; i++) for (int z = 0; z < 10; z++) for (int j = 0; j < 800; j++) for (int k = 0; k < 800; k++) dist[i][z][j][k] = inf;

        int n, k;
        std::cin >> n >> k;

        std::vector<pii> ends;

        state start = {0, inf, inf, 0, 0};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                std::cin >> grid[0][i][j];
                if (grid[0][i][j] == 'E'){
                    start.i = i;
                    start.j = j;
                }
                else if (grid[0][i][j] == 'X'){
                    ends.push_back({i, j});
                }
            }
        }

        for (int x = 1; x <= 3; x++){
            for (int i = 0; i < n; i++){
                for (int j = 0, m = n - 1; j < n; j++, m--){
                    grid[x][i][j] = grid[x - 1][m][i];
                    if (grid[x][i][j] == 'X'){
                        ends.push_back({i, j});
                    }
                }
                //std::cout << grid[x][i] << '\n';
            }
            //std::cout << '\n';
        }

        int up [4] = {-1, 1, 0, 0};
        int side [4] = {0, 0, -1, 1};

        std::queue<state> q;
        q.push(start);
        while (!q.empty()){
            state cur = q.front();
            q.pop();
            if (cur.k == k - 1){
                cur.x++;
                cur.x %= 4;
                cur.k = 0;
            }
            else{
                cur.k++;
            }
            for (int i = 0; i < 4; i++){
                int ii = cur.i + up[i], jj = cur.j + side[i];
                if (ii >= 0 && ii < n && jj >= 0 && jj < n && grid[cur.x][ii][jj] != 'W' && dist[cur.x][cur.k][ii][jj] > cur.dist + 1){
                    state next = {cur.x, ii, jj, cur.dist + 1, cur.k};
                    dist[cur.x][cur.k][ii][jj] = next.dist;
                    q.push(next);
                }
            }
        }

        int ans = inf;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 10; j++)
                ans = std::min(ans, dist[i][j][ends[i].f][ends[i].s]);
        }

        std::cout << (ans == inf ? -1 : ans) << '\n';
        
    }

    return 0;

}
