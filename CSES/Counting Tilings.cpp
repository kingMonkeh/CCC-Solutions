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

int n, m;
int DP[2][1024];

//bottom up
//imagine the rectangle has width n
//and height of m
//we can just try filling out 1 row at a time since n <= 10
//we go through each row, filling it in using our blocks and updating how the next row is filled

int cur = 0;
void generate (int& row, int& mask, int nxt, int i){

    //we've filled this row, update DP
    if (i == n){
        DP[cur ^ 1][nxt] = (DP[cur ^ 1][nxt] % MOD + DP[cur][mask] % MOD) % MOD;
        return;
    }
    
    //block already here, continue
    if (mask & (1 << i)){
        generate(row, mask, nxt, i + 1);
        return;
    }

    //lay flat block
    if (i < n - 1 && !(mask & (1 << (i + 1)))){
        generate(row, mask, nxt, i + 2);
    }
    
    //lay vertical block
    if (row < m - 1){
        nxt ^= (1 << i);
        generate(row, mask, nxt, i + 1);
    }
    
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> n >> m;

        DP[cur][0] = 1;
        for (int i = 0; i < m; i++, cur ^= 1){
            memset(DP[cur ^ 1], 0, sizeof(DP[cur ^ 1]));
            for (int j = 0; j < (1 << n) - 1; j++){
                if (DP[cur][j]){
                    generate(i, j, 0, 0);
                }
            }
            //special case, this entire row is filled, skip this entire row
            if (DP[cur][(1 << n) - 1]){
                DP[cur ^ 1][0] = (DP[cur ^ 1][0] % MOD + DP[cur][(1 << n) - 1] % MOD) % MOD;
            }
        }

        std::cout << DP[cur][0];
        
    }
    
    return 0;
    
}