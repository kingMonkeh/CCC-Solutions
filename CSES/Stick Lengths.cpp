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

    vi p (n);
    for (int i = 0; i < n; i++){
        std::cin >> p[i];
    }

    std::sort(p.begin(), p.end());

    int mid = n / 2, mid2 = n / 2 + 1;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) c1 += llabs(p[mid] - p[i]);
    for (int i = 0; i < n; i++) c2 += llabs(p[mid2] - p[i]);

    std::cout << std::min(c1, c2);
        
    return 0;
    
}