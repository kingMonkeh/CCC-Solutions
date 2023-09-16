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

int DP [501][501];

int solve (int a, int b){

    //note that solve(3, 5) is the same as solve(5, 3)
    if (a > b) std::swap(a, b);

    if (DP[a][b] != -1) return DP[a][b];

    //you cut once = 1 move
    // + solve (new rect 1) + solve (new rect 2)
    
    int ret = inf;
    //try cutting vertically
    for (int i = 1; i < b; i++){
        ret = std::min(ret, 1 + solve(a, b - i) + solve(a, i));
    }
    //try cutting horizontally
    for (int i = 1; i < a; i++){
        ret = std::min(ret, 1 + solve(a - i, b) + solve(i, b));
    }

    return DP[a][b] = ret;
    
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        memset(DP, -1, sizeof(DP));
        //these are already squares, 0 cuts required
        for (int i = 1; i <= 500; i++) DP[i][i] = 0;
        
        int a, b;
        std::cin >> a >> b;

        std::cout << solve(a, b);
        
    }
    
    return 0;
    
}