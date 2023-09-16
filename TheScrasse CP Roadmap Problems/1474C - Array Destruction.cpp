/*

We notice that x can only ever get smaller

And once x is less than an element in array a,
Then you cant remove that element

Therefore, we always want to be greedily remove the biggest element in each operation
From there, we obviously know what the other element will be and check if it exists

*/

#include <bits/stdc++.h>

std::vector<int> solve (int n, std::vector<int>& a, int x){

    std::multiset<int> s;
    for (auto i: a) s.insert(i);

    std::vector<int> ans;
    for (int i = 0; i < n; i++){
        auto big = s.end(); big--;
        int c = x - *big;
        s.erase(big);
        auto i2 = s.find(c);
        if (i2 == s.end()){
            return {};
        }
        ans.push_back(x - c);
        ans.push_back(c);
        x = x - c;
        s.erase(i2);
    }

    return ans;
    
}

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;

        std::vector<int> a (2 * n);
        for (int i = 0; i < 2 * n; i++){
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end(), [](int& x, int& y){
            return x > y;
        });

        for (int i = 1; i < 2 * n; i++){
            std::vector<int> result = solve(n, a, a[0] + a[i]);
            if (result.size()){
                std::cout << "YES\n";
                std::cout << a[0] + a[i] << '\n';
                for (int i = 0; i < n; i++){
                    std::cout << result[2 * i] << ' ' << result[2 * i + 1] << '\n';
                }
                goto nxt;
            }
        }

        std::cout << "NO\n";

        nxt:;
        
    }
    
    return 0;
    
}