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
        
        int n;
        std::cin >> n;

        //greedy: remove mx digit every time

        int ans = 0;
        while (n){
            int temp = n, mx = 0;
            while (temp){
                mx = std::max(mx, temp % 10);
                temp /= 10;
            }
            n = n - mx;
            ans++;
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}