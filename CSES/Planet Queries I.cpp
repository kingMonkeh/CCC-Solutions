#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX / 2
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

/*

simple binary lifting

basically let dest [i][j] tell us where we end up
if we start at planet i, and jump pow(2, j) teleporters

time complexity is N log N

*/

const int MAXN = 2e5 + 5;
const int MAXP = 30;
int dest [MAXN][MAXP];

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, q;
        std::cin >> n >> q;
        //std::vector<vi> dest (n + 1, vi (30));
        for (int i = 1; i <= n; i++) std::cin >> dest[i][0];

        for (int i = 1; i < 30; i++){
            for (int j = 1; j <= n; j++){
                dest[j][i] = dest[dest[j][i - 1]][i - 1];
            }
        }

        while (q--){
            int x, k;
            std::cin >> x >> k;
            for (int i = 0; i < 30; i++){
                if (k & (1 << i)) x = dest[x][i];
            }
            std::cout << x << '\n';
        }
        
    }
    
    return 0;
    
}