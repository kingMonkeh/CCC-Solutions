#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::string s = "";
        for (int i = 0; i < n; i++) s += "BAN";

        int m = ceil(n / 2.0);
        std::cout << m << '\n';
        for (int i = 0, ind1 = 0, ind2 = 3 * n - 1; i < m; i++, ind1 += 3, ind2 -= 3){
            std::cout << ind1 + 1 << ' ' << ind2 + 1 << '\n';
        }

        
    }
    
    return 0;
    
}