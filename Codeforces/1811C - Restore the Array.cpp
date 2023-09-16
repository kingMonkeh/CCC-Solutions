/*

https://codeforces.com/blog/entry/114788

read editorial for full proof of formula

Mike does very good job

*/

#include <bits/stdc++.h>

int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {

        int n;
        std::cin >> n;
        std::vector<int> b (n - 1);
        for (int i = 0; i < n - 1; i++) std::cin >> b[i];

        std::vector<int> a;
        a.push_back(b[0]);
        for (int i = 0; i < n - 2; i++){
            //this a must satisfy both segments at once, therefore must be min
            a.push_back(std::min(b[i], b[i + 1]));
        }
        a.push_back(b[n - 2]);

        for (auto& x: a) std::cout << x << ' ';
        std::cout << '\n';
        
    }

    return 0;
    
}