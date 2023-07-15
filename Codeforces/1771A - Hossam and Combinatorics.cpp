#include <bits/stdc++.h>

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){
        
        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        int small = a[0], big = a[n - 1];
        int freq1 = 0, freq2 = 0;
        
        if (small == big){
            std::cout << 1LL * n * (n - 1) << '\n';
        }

        else{
            for (int i = 0; i < n && a[i] == small; i++) freq1++;
            for (int i = n - 1; i >= 0 && a[i] == big; i--) freq2++;
            std::cout << 1LL * freq1 * freq2 * 2 << '\n';
        }
        
    }
    
    return 0;
    
}