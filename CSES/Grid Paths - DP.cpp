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

int DP [1001][1001];

std::vector<std::vector<char>> grid;

//work backwards
int solve (int r, int c){

    if (DP[r][c] != -1) return DP[r][c];

    int ret = 0;
    //go up
    ret += solve(r - 1, c) % MOD;
    //go left
    ret += solve(r, c - 1) % MOD;

    return DP[r][c] = ret % MOD;
        
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
        
        int n;
        std::cin >> n;

        memset(DP, -1, sizeof(DP));

        DP[1][1] = 1;

        grid.resize(n + 1, std::vector<char> (n + 1));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                std::cin >> grid[i][j];
                if (grid[i][j] == '*') DP[i][j] = 0;
            }
        }

        for (int i = 0; i <= n; i++){
            grid[i][0] = grid[0][i] = '.';
            DP[i][0] = DP[0][i] = 0;
        }

        std::cout << (grid[n][n] == '*' ? 0 : solve(n, n)) << '\n';
        
    }
    
    return 0;
    
}