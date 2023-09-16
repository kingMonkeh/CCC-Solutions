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

int DP [400000];

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        std::map<int, int> compress;
        
        int a[n], b[n], p[n];
        for (int i = 0; i < n; i++){
            std::cin >> a[i] >> b[i] >> p[i];
            //b[i]++;
            compress[a[i]], compress[b[i]];
        }

        int cnt = 1;
        for (auto& a: compress){
            a.second = cnt;
            cnt++;
        }

        std::vector<std::vector<pii>> projects (cnt);
        for (int i = 0; i < n; i++){
            projects[compress[b[i]]].push_back({compress[a[i]], p[i]});
        }

        //dp[i] = max score you can obtain at day i after compressing days
        int DP [cnt];
        memset(DP, 0, sizeof(DP));
        for (int i = 1; i < cnt; i++){
            DP[i] = DP[i - 1]; //do nothing this day
            //check every proj that ends at this day
            for (auto& proj: projects[i]){
                //we would have had to start at proj.a - 1, since proj.a is the day we start and we can't have any other project active at that time
                DP[i] = std::max(DP[i], DP[proj.f - 1] + proj.s);
            }
        }

        std::cout << DP[cnt - 1] << '\n';
        
    }
    
    return 0;
    
}