#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

/*



*/

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::string s;
        std::cin >> s;

        std::map<char, int> cnt;
        for (char& c: s){
            cnt[c]++;
        }

        //if odd
        std::string s1 = "";
        if (s.size() % 2 == 1){
            int odd = 0;
            char mid;
            for (auto& c: cnt){
                if (c.second % 2 == 1){
                    odd++;
                    mid = c.first;
                    c.second--;
                }
                int half = c.second / 2;
                while (c.second > half){
                    s1 += c.first;
                    c.second--;
                }
            }
            if (odd != 1){
                std::cout << "NO SOLUTION\n";
                return 0;
            }
            std::cout << s1 << mid;
            for (int i = s1.size() - 1; i >= 0; i--) std::cout << s1[i];
        }
        else{
            int odd = 0;
            for (auto& c: cnt){
                if (c.second % 2 == 1){
                    odd++;
                    c.second--;
                }
                int half = c.second / 2;
                while (c.second > half){
                    s1 += c.first;
                    c.second--;
                }
            }
            if (odd != 0){
                std::cout << "NO SOLUTION\n";
                return 0;
            }
            std::cout << s1;
            for (int i = s1.size() - 1; i >= 0; i--) std::cout << s1[i];
        }

        
        
    }

    return 0;
    
}