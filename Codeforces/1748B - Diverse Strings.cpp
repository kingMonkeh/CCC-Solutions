#include <bits/stdc++.h>

/*

uh max size diverse string is only 100 char
10 distinct at max, 10 of each digit = 10 * 10 = 100 chars

Therefore any substring with len > 100, is guranteed to not be diverse
Check only substrings with len <= 100

How to do so efficiently?
Use sliding window technique
Notice that as we slide window, we just decrement front character and add back character
Then we can perform a quick 10 iteration check to determine if diverse or not

*/

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        int ans = 0;
        for (int i = 0; i < 100 && i < n; i++){
            
            //Initialize Window
            int distinct = 0;
            std::map<char, int> occ;
            for (int j = 0; j <= i; j++){
                occ[s[j]]++;
                if (occ[s[j]] == 1) distinct++;
            }

            bool diverse = true;
            for (auto& digit: occ){
                if (digit.second > distinct){
                    diverse = false;
                    break;
                }
            }

            if (diverse) ans++;

            //Slide
            int l = 0, r = i + 1;
            while (r < n){

                //Update window content
                occ[s[l]]--;
                if (occ[s[l]] == 0) distinct--;
                occ[s[r]]++;
                if (occ[s[r]] == 1) distinct++;
                l++; r++;
                
                //Quick check
                bool diverse = true;
                for (auto& digit: occ){
                    if (digit.second > distinct){
                        diverse = false;
                        break;
                    }
                }

                if (diverse) ans++;

            }
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}