#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

//type 0 = arrive, 1 = leave
struct event{
    int time, type;
    bool operator < (event& x) {return time < x.time;}
};

signed main (){

    int n;
    std::cin >> n;

    std::vector<event> c (n * 2);
    for (int i = 0; i < 2 * n; i++){
        std::cin >> c[i].time;
        c[i].type = i & 1 ? 1 : 0;
    }

    std::sort(c.begin(), c.end());

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < 2 * n; i++){
        if (c[i].type == 0) cur++;
        else cur--;
        ans = std::max(ans, cur);
    }

    std::cout << ans << '\n';
        
    return 0;
    
}