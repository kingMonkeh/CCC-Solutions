#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> x (n);

    for (int i = 0; i < n; i++){
        std::cin >> x[i];
    }

    std::stack<std::pair<int, int>> s;
    s.push({0, 0});
    for (int i = 0; i < n; i++){
        while (s.top().f >= x[i]){
            s.pop();
        }
        std::cout << s.top().s << ' ';
        s.push({x[i], i + 1});
    }
    
    return 0;
    
}