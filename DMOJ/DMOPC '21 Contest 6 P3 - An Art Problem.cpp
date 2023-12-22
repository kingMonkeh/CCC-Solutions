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

do a fake dijkstra, easy peasy lemon squeezy

*/

struct pos{
    int dist, color, i, j;
    bool operator()(pos& x, pos& y){
        return x.dist > y.dist;
    }
};

signed main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n, m, k;
        std::cin >> n >> m >> k;

        std::priority_queue<pos, std::vector<pos>, pos> pq;
        
        int grid [n + 2][m + 2], dist[n + 2][m + 2];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                std::cin >> grid[i][j];
                if (grid[i][j] != 0){
                    pos p = {0, grid[i][j], i, j};
                    pq.push(p);
                    dist[i][j] = 0;
                }
                else{
                    dist[i][j] = inf;
                }
            }

        for (int i = 0; i <= n + 1; i++){
            dist[i][0] = -1;
            dist[i][m + 1] = -1;
        }
        for (int i = 0; i <= m + 1; i++){
            dist[0][i] = -1;
            dist[n + 1][i] = -1;
        }

        int up [4] = {-1, 1, 0, 0};
        int side [4] = {0, 0, -1, 1};
        
        while (!pq.empty()){
            pos cur = pq.top();
            pq.pop();
            if (cur.dist > dist[cur.i][cur.j] || cur.dist >= k) continue;
            for (int i = 0; i < 4; i++){
                int ii = cur.i + up[i], jj = cur.j + side[i];
                if (cur.dist + 1 <= dist[ii][jj]){
                    dist[ii][jj] = cur.dist + 1;
                    if (grid[ii][jj] == 0){
                        grid[ii][jj] = cur.color;
                        pq.push({cur.dist + 1, cur.color, ii, jj});
                    }
                    else if (cur.color < grid[ii][jj]){
                        grid[ii][jj] = cur.color;
                        pq.push({cur.dist + 1, cur.color, ii, jj});
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                std::cout << grid[i][j] << ' ';
            } std::cout << '\n';
        }

    }

    return 0;

}