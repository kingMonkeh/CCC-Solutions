#include <bits/stdc++.h>

int main() {
    
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
	while (tests--) {

        std::string s;
        std::cin >> s;

        std::string a = "", b = "";
        for (int i = 0; i < (int) s.length() / 2; i++){
            a += s[i];
        }
        for (int i = (int) s.length() / 2; i < (int) s.length(); i++){
            b += s[i];
        }

        std::cout << (a == b ? "YES\n" : "NO\n");
        
	}
	return 0;
}