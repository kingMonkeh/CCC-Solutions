#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

const int MOD = 1e9 + 7;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int DP [1000001];

signed main (){

    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n, x;
        std::cin >> n >> x;

        vi coins (n);
        for (int i = 0; i < n; i++) std::cin >> coins[i];

        for (int i = 0; i <= 1e6; i++) DP[i] = inf;
        DP[0] = 0;

        for (int i = 0; i < x; i++){
            if (DP[i] != inf){
                for (int j = 0; j < n; j++){
                    if (i + coins[j] <= x){
                        DP[i + coins[j]] = std::min(DP[i + coins[j]], DP[i] + 1);
                    }
                }
            }
        }
        
        std::cout << (DP[x] == inf ? -1 : DP[x]) << '\n';
        
    }
    
    return 0;
    
}