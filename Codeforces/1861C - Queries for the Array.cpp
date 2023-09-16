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

signed main (){

    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){
        
        std::string s;
        std::cin >> s;

        bool ans = true;
        //good = prefix that is sorted, bad = prefix that is not sorted (maybe we can't confirm)
        int cnt = 0, good = 0, bad = inf;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '+'){
                cnt++;
            }
            else if (s[i] == '-'){
                cnt--;
                good = std::min(good, cnt);
                //if cur < amount that is bad, then we've cleared the bad
                if (cnt < bad){
                    bad = inf;
                }
            }
            else if (s[i] == '0'){
                //if we're less than what is guranteed to be good, we can't possibly be not sorted
                if (cnt <= good || cnt < 2){
                    ans = false;
                    break;
                }
                bad = std::min(bad, cnt);
            }
            else{
                //if we know atleast bad numbers are not sorted, if our cur is greater, than guranteed to not be sorted
                if (bad <= cnt){
                    ans = false;
                    break;
                }
                good = std::max(good, cnt);
            }
        }

        std::cout << (ans ? "YES\n" : "NO\n");
        
    }
    
    return 0;
    
}