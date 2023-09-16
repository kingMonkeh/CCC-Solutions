#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

signed main (){

    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){
        
        std::string s;
        std::cin >> s;

        std::string state = "";
        bool ans = true, change = false, change2 = false;
        int cnt = 0, plus = 0, minus = 0;
        for (int i = 0; i < s.size(); i++){
            if (minus > plus) change2 = true;
            if (s[i] == '+'){
                cnt++;
                plus++;
                change = true;
            }
            else if (s[i] == '-'){
                cnt--;
                minus++;
            }
            else if (s[i] == '0'){
                if (cnt < 2){
                    ans = false;
                    break;
                }
                if (!state.empty() && s[i] != state.back() && !change){
                    ans = false;
                    break;
                }
                plus = 0, minus = 0, change2 = false;
                state += s[i];
            }
            else{
                change = false;
                if (!state.empty() && s[i] != state.back() && !change2){
                    ans = false;
                    break;
                }
                state += s[i];
            }
        }

        std::cout << (ans ? "YES\n" : "NO\n");
        
    }
    
    return 0;
    
}