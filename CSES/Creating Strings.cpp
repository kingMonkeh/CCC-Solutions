#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

std::vector<std::string> ans;
std::string chars;
std::map<char, int> cnt;
void solve (std::string s){

    if (s.length() == chars.size()){
        ans.push_back(s);
        return;
    }
    
    for (char c = 'a'; c <= 'z'; c++){
        if (cnt[c] > 0){
            cnt[c]--;
            solve(s + c);
            cnt[c]++;
        }
    }
    
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> chars;
        for (auto& a: chars) cnt[a]++;
        
        solve ("");

        std::cout << ans.size() << '\n';
        for (auto& s: ans) std::cout << s << '\n';
        
    }

    return 0;
    
}