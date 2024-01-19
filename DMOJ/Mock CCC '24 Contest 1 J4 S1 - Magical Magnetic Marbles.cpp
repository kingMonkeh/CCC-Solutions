#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define s second
#define inf LONG_LONG_MAX / 2
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

/*

Idea:

simulate the initial merge

then just count the gaps and their size between 1's
greedily fill in gaps until you cant

edge case: 0 marbles initially and you have > 0 marbles, ans = 1

*/

signed main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n, k;
        std::cin >> n >> k;

        std::vector<int> gap;

        std::string s;
        std::cin >> s;
        bool first = true;
        int f, l;
        for (int i = 0; i < n; i++){
            if (i != n - 1 && s[i] == '1' && s[i + 1] == '1'){
                s[i] = '0';
            }
            if (first && s[i] == '1'){
                f = i;
                first = false;
            }
            if (s[i] == '1') l = i;
        }

        //std::cout << s << '\n';

        int ans = 0;
        int dist = 0;
        for (int i = f; i <= l; i++){
            if (s[i] == '1'){
                if (dist != 0) gap.push_back(dist);
                dist = 0;
                ans++;
            }
            else dist++;
        }

        std::sort(gap.begin(), gap.end());

        for (int i = 0; i < gap.size(); i++){
            //std::cout << gap[i] << ' ';
            if (gap[i] <= k){
                k -= gap[i];
                ans--;
            }
        } //std::cout << '\n';

        if (ans == 0 && k) ans++;

        std::cout << ans << '\n';
        
    }

    return 0;

}
