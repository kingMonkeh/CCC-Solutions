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
    
        int n, m;
        std::cin >> n >> m;

        std::vector<vi> graph (n + 1);
        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vi ans (n + 1, 0);
        for (int i = 1; i <= n; i++){
            if (ans[i] == 0){
                std::queue<int> q;
                q.push(i);
                ans[i] = 1;
                while (!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for (auto& f: graph[cur]){
                        if (ans[f] == ans[cur]){
                            std::cout << "IMPOSSIBLE";
                            return 0;
                        }
                        else if (ans[f] == 0){
                            if (ans[cur] == 1){
                                ans[f] = 2;
                            }
                            else ans[f] = 1;
                            q.push(f);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
        
    }
    
    return 0;
    
}