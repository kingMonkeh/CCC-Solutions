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

int DP [100000][101];

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
        
        int n, m;
        std::cin >> n >> m;

        vi x (n);
        for (int i = 0; i < n; i++) std::cin >> x[i];
        
        if (x[0] == 0) for (int i = 1; i <= m; i++) DP[0][i] = 1;
        else DP[0][x[0]] = 1;
        
        for (int i = 1; i < n; i++){
            if (x[i] != 0){
                DP[i][x[i]] += DP[i - 1][x[i]] % MOD;
                DP[i][x[i]] += DP[i - 1][x[i] - 1] % MOD;
                DP[i][x[i]] += DP[i - 1][x[i] + 1] % MOD;
                DP[i][x[i]] %= MOD;
            }
            else{
                for (int j = 1; j <= m; j++){
                    DP[i][j] += DP[i - 1][j] % MOD;
                    DP[i][j] += DP[i - 1][j - 1] % MOD;
                    DP[i][j] += DP[i - 1][j + 1] % MOD;
                    DP[i][j] %= MOD;
                }
            }
        }

        int ans = 0;
        if (x[n - 1] == 0) for (int i = 1; i <= m; i++){
            ans += DP[n - 1][i] % MOD;
            ans %= MOD;
        }
        else ans += DP[n - 1][x[n - 1]];

        std::cout << ans;
        
    }
    
    return 0;
    
}