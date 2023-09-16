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

        std::vector<std::string> grid (n);
        for (int i = 0; i < n; i++) std::cin >> grid[i];

        int ans = 0;

        int up [4] = {1, -1, 0, 0};
        int side [4] = {0, 0, -1, 1};
        
        std::queue<pii> q; //row, col
        std::vector<vi> vis (n, vi (m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '.' && !vis[i][j]){
                    ans++;
                    q.push({i, j});
                    while (!q.empty()){
                        pii cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++){
                            if (cur.f + up[k] < n && cur.f + up[k] >= 0 && cur.s + side[k] >= 0 && cur.s + side[k] < m && grid[cur.f + up[k]][cur.s + side[k]] == '.' && !vis[cur.f + up[k]][cur.s + side[k]]){
                                q.push({cur.f + up[k], cur.s + side[k]});
                                vis[cur.f + up[k]][cur.s + side[k]] = 1;
                            }
                        }
                    }
                }
            }
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}