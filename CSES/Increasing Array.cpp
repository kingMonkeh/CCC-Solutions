#include <bits/stdc++.h>

#define int long long

signed main (){

    int n;
    std::cin >> n;

    int x [n];
    for (int i = 0; i < n; i++) std::cin >> x[i];

    int curmx = x[0], ans = 0;
    for (int i = 0; i < n; i++){
        if (x[i] > curmx){
            curmx = x[i];
        }
        else{
            ans += curmx - x[i];
        }
    }

    std::cout << ans;
    
    return 0;
    
}