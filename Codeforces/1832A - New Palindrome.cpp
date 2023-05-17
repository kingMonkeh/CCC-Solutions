#include <bits/stdc++.h>
 
int main(){
 
    int tests;
    std::cin >> tests;
 
    while (tests--){
 
        int unique = 0;
        int frequency [26];
        memset(frequency, 0, sizeof(frequency));
        std::string s;
        std::cin >> s;
        for (int i = 0; i < s.length(); i++){
            frequency[s[i] - 97]++;
            if (frequency[s[i] - 97] == 2){
                unique++;
            }
        }
 
        if (unique >= 2){
            std::cout << "YES\n";
        }
 
        else{
            std::cout << "NO\n";
        }
            
    }
    
    return 0;
    
}