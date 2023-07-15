#include <bits/stdc++.h>

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        int ans = 0;
        int l = 0, r = n - 1;
        //make pairs (max element, min element)
        while (l < r){
            ans += a[r] - a[l];
            l++; r--;
        }
        std::cout << ans << '\n';
    }
    return 0;
}