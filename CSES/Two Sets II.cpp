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

int DP [501][125251];

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        DP[0][0] = 1;

        int sum = n * (n + 1) / 2;
        if (sum % 2){
            std::cout << 0 << '\n';
            continue;
        }

        sum /= 2;

        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= sum; j++){
                DP[i][j] += DP[i - 1][j];
                DP[i][j] %= MOD;
                if (j - i >= 0){
                    DP[i][j] += DP[i - 1][j - i] % MOD;
                    DP[i][j] %= MOD;
                }
            }
        }

        //take n - 1, this ensures that n is always in the second set
        //meaning no set is counted twice
        std::cout << DP[n - 1][sum] % MOD;
        
    }
    
    return 0;
    
}