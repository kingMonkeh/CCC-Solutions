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

Idea:

theres only 4 colors
2 options, use a color in our final set, or dont

2^4 possible sets of colors
we can use bitmask to represent active color set

dfs 16 times using each possible set of active colors


*/

int n, m;
int a, b, c, d;
int vis [102][102];
std::vector<vi> graph [102][102];
int ans;

void dfs (int i, int j, int& mask){

    if (i == c && j == d){
        int tot = 0;
        for (int i = 1; i <= 8; i *= 2){
            if (mask & i) tot++;
        }
        ans = std::min(ans, tot);
    }
    
    for (auto& edge: graph[i][j]){
        if (!vis[edge[0]][edge[1]] && edge[2] & mask){
            vis[edge[0]][edge[1]] = true;
            dfs(edge[0], edge[1], mask);
        }
    }
    
}

void comb (int x, int mask){
    if (x == 8){
        if (mask == 0) return;
        for (int i = 0; i < 102; i++) for (int j = 0; j < 102; j++) vis[i][j] = 0;
        vis[a][b] = 1;
        dfs(a, b, mask);
        return;
    }
    x *= 2;
    comb(x, mask | x);
    comb(x, mask);
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> n >> m;

        std::map<int, int> conv;
        conv['P'] = 1;
        conv['C'] = 2;
        conv['Z'] = 4;
        conv['N'] = 8;
        for (int i = 0; i < n; i++){
            std::string colors;
            std::cin >> colors;
            for (int j = 0; j < m - 1; j++){
                graph[i + 1][j + 1].push_back({i + 1, j + 2, conv[colors[j]]});
                graph[i + 1][j + 2].push_back({i + 1, j + 1, conv[colors[j]]});
            }
        }

        for (int i = 0; i < n - 1; i++){
            std::string colors;
            std::cin >> colors;
            for (int j = 0; j < m; j++){
                graph[i + 1][j + 1].push_back({i + 2, j + 1, conv[colors[j]]});
                graph[i + 2][j + 1].push_back({i + 1, j + 1, conv[colors[j]]});
            }
        }

        int q;
        std::cin >> q;

        while (q--){
            ans = 4;
            std::cin >> a >> b >> c >> d;
            comb(1, 0);
            comb(1, 1);
            std::cout << ans << '\n';
        }
        
    }
    
    return 0;
    
}