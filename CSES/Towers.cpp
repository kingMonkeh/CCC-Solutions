#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

signed main (){

    int n;
    std::cin >> n;

    int ans = 0;

    std::multiset<int> towers;

    int k;
    std::cin >> k;
    towers.insert(k);
    for (int i = 1; i < n; i++){
        std::cin >> k;
        auto best = towers.lower_bound(k + 1);
        if (best == towers.end()){
            towers.insert(k);
            continue;
        }
        /*
        if (k == *best){
            ans++;
            continue;
        }
        */
        towers.erase(best);
        towers.insert(k);
    }

    std::cout << ans + towers.size() << '\n';
        
    return 0;
    
}