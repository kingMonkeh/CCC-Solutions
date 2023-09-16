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
 
int DP[1000001];
int n, x;
vi c;

/*
int solve (int cur, int mx){

    if (cur == 0) return 1;

    if (DP[cur][mx]) return DP[cur][mx];
    
    int ret = 0;
    for (int i = 0; i < mx; i++){
        if (cur - c[i] >= 0) ret += solve(cur - c[i], i + 1) % MOD;
    }

    return DP[cur][mx] = ret % MOD;
    
}
*/
 
signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
        
        std::cin >> n >> x;

        c.resize(n);
        for (int i = 0; i < n; i++) std::cin >> c[i];

        std::sort(c.begin(), c.end());

        for (int i = 0; i <= x; i++) DP[i] = 0;
        DP[0] = 1;
        
        //sort coins first, this way you gurantee that its always in order
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= x; j++){
                if (j + c[i] <= x){
                    DP[j + c[i]] += DP[j] % MOD;
                    DP[j + c[i]] %= MOD;
                }
                //std::cout << "DP[" << j << "][" << i << "] = " << DP[j][i] << '\n';
                //std::cout << "DP[" << j << "] = " << DP[j] << '\n';
            }
        }

        std::cout << DP[x] << '\n';
        
    }
    
    return 0;
    
}