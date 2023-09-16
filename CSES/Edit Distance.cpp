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

int DP [5001][5001];

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
        
        std::string s1, s2;
        std::cin >> s1 >> s2;

        for (int i = 0; i <= s1.size(); i++) for (int j = 0; j <= s2.size(); j++) DP[i][j] = inf;

        DP[0][0] = 0;

        //DP[i][j] tells us how many moves to change the first i letters of s1 to the first j letters of s2
        for (int i = 0; i <= s1.size(); i++){
            for (int j = 0; j <= s2.size(); j++){
                //note that i'm speaking with 1 indexing
                //we delete s1[i] (one move), we still need to solve DP[i - 1][j]
                if (i)
                    DP[i][j] = std::min(DP[i][j], DP[i - 1][j] + 1);
                //we add s2[j] to the end of s1, for it to line up correctly we need to solve DP[i][j - 1] first
                if (j)
                    DP[i][j] = std::min(DP[i][j], DP[i][j - 1] + 1);
                //replace s1[i] with s2[j], one operation, we still need to solve DP[i - 1][j - 1]
                //note that if theyre the same, we wouldnt actually need to replace them hence 0
                if (i && j)
                    DP[i][j] = std::min(DP[i][j], DP[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
            }
        }

        std::cout << DP[s1.size()][s2.size()] << '\n';
        
    }
    
    return 0;
    
}