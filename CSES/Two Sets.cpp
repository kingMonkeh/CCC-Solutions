#include <bits/stdc++.h>

#define int long long

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        if ((n * (n + 1) / 2) % 2 == 1){
            std::cout << "NO\n";
            continue;
        }

        int sum = (n * (n + 1) / 2) / 2;

        int s = 0;
        std::vector<int> s1, s2;
        std::map<int, int> used;
        int num = n;
        while (s < sum){
            if (s + num <= sum){
                s += num;
                used[num] = true;
                s1.push_back(num);
            }
            num--;
        }

        for (int i = 1; i <= n; i++) if (!used[i]) s2.push_back(i);

        std::cout << "YES\n" << s1.size() << '\n';
        for (auto& x: s1) std::cout << x << ' ';
        std::cout << '\n' << s2.size() << '\n';
        for (auto& x: s2) std::cout << x << ' ';
        
    }

    return 0;
    
}