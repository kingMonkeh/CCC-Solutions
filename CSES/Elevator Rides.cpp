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

//2^20 possibilities
int n, x;
vi w;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> n >> x;

        w.resize(n);
        for (int i = 0; i < n; i++) std::cin >> w[i];

        pii DP [1 << n];
        DP[0] = {1, 0}; //rides, sum
                
        //For every subset
        for (int s = 1; s < (1 << n); s++){
            DP[s] = {n, 0};
            for (int p = 0; p < n; p++){
                //if this person is active in the subset
                if (s & (1 << p)){
                    //to obtain the current subset, you could have added the current person to a near identical subset with the only difference being the current person is not activated in that subset
                    //make copy of prev state
                    auto prev = DP[s ^ (1 << p)];
                    if (prev.s + w[p] <= x){
                        prev.s += w[p];
                    }
                    else{
                        prev.f++;
                        prev.s = w[p];
                    }
                    DP[s] = std::min(DP[s], prev);
                }
            }
        }

        std::cout << DP[(1 << n) - 1].f << '\n';
        
    }
    
    return 0;
    
}