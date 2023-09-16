#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

struct movie{
    int a, b;
    bool operator < (movie& x) {return b < x.b;}
};

signed main (){

    int n;
    std::cin >> n;

    std::vector<movie> m (n);
    for (int i = 0; i < n; i++){
        std::cin >> m[i].a >> m[i].b;
    }

    std::sort(m.begin(), m.end());

    int ans = 0;
    int last = 0;
    for (int i = 0; i < n; i++){
        if (m[i].b > last && m[i].a >= last){
            last = m[i].b;
            ans++;
        }
    }

    std::cout << ans << '\n';
        
    return 0;
    
}