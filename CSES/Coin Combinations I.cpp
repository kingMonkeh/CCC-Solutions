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

        vi c (n);
        for (int i = 0; i < n; i++) std::cin >> c[i];
 
        for (int i = 0; i <= x; i++) DP[i] = 0;
        DP[0] = 1;
        
        for (int i = 0; i < x; i++){
            if (DP[i]){
                for (int j = 0; j < n; j++){
                    if (i + c[j] <= x) DP[i + c[j]] += DP[i] % MOD;
                }
            }
            
        }
 
        std::cout << DP[x] % MOD << '\n';
        
    }
    
    return 0;
    
}