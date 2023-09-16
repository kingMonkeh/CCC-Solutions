#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            s2 += a[i];
        }

        std::sort(a.begin(), a.end());
        long long ans = -llabs(s2);
        for (int i = n - 1; i >= 0; i--){
            s1 += a[i];
            s2 -= a[i];
            ans = std::max(ans, llabs(s1) - llabs(s2));
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}