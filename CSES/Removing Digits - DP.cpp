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

int DP [1000001];

int solve (int x){

    if (DP[x] != -1) return DP[x];

    int ret = LONG_LONG_MAX;
    int temp = x;
    while (temp){
        if (temp % 10 == 0){
            temp /= 10;
            continue;
        }
        ret = std::min(ret, solve(x - temp % 10) + 1);
        temp /= 10;
    }

    return DP[x] = ret;
        
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
        DP[0] = 0;

        std::cout << solve(n) << '\n';
        
    }
    
    return 0;
    
}