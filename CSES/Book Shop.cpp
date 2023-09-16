#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

//#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

int DP [1001][100001];
std::vector<pii> books;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
        
        int n, x;
        std::cin >> n >> x;

        memset(DP, 0, sizeof(DP));

        books.resize(n + 1);
        for (int i = 1; i <= n; i++)
            std::cin >> books[i].f;
        for (int i = 1; i <= n; i++)
            std::cin >> books[i].s;

        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= x; j++){
                DP[i][j] = DP[i - 1][j]; // dont take book
                //take only if you have enough money
                if (books[i].f <= j){
                    DP[i][j] = std::max(DP[i][j], DP[i - 1][j - books[i].f] + books[i].s);
                }
            }
        }

        std::cout << DP[n][x];
        
    }
    
    return 0;
    
}