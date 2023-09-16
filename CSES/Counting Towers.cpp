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

int DP [1000001][2]; //1 if not fused, 2 if fused

//                                      _  _
// dp[i][1] = last blocks are separate | || |
//                                   _ _
// dp[i][2] = last blocks are fused |   |
    
// transition:
//              _  _    _  _    _  _    _  _     _ _
//  _  _       | || |  |_|| |  | ||_|  |_||_|   |_|_|
// | || | =>   | || |, | || |, | || |, | || |,  |   |
//              _ _    _ _    _ _ 
//  _ _        |   |  |_ _|  |_ _|
// |   |  =>   |   |, | | |, |   |

signed main (){
 
    std::ios_base::sync_with_stdio(false);

    DP[1][0] = 1, DP[1][1] = 1;
    for (int i = 2; i <= 1000000; i++){
        DP[i][0] = (4 * DP[i - 1][0] % MOD + DP[i - 1][1]) % MOD;
        DP[i][1] = (DP[i - 1][0] + 2 * DP[i - 1][1] % MOD) % MOD;
    }
    
    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){
        
        int n;
        std::cin >> n;

        std::cout << (DP[n][0] + DP[n][1]) % MOD << '\n';
        
    }
    
    return 0;
    
}