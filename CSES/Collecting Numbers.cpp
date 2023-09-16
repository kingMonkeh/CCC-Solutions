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

    std::map<int, int> idx;
    for (int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        idx[x] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++){
        if (idx[i] < idx[i - 1]) ans++;
    }

    std::cout << ans << '\n';
        
    return 0;
    
}