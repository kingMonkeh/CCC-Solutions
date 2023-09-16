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

    vi x (n);
    for (int i = 0; i < n; i++){
        std::cin >> x[i];
    }

    std::sort(x.begin(), x.end());

    int sum = 0;
    for (int i = 0; i < n; i++){
        if (sum + 1 < x[i]){
            break;
        }
        sum += x[i];
    }

    std::cout << sum + 1 << '\n';
        
    return 0;
    
}
