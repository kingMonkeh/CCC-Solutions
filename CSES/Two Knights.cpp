#include <bits/stdc++.h>

#define int long long

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        for (int i = 1; i <= n; i++){

            int ans = 0;

            if (i == 1) ans = 0;
            else if (i == 2) ans = 12;
            else if (i == 3) ans = 56;
            else if (i == 4) ans = 192;

            int inner_area = (i - 4) * (i - 4), area = i * i;
            if (i - 4 > 0){
                ans += inner_area * (area - 9); //inner square
                ans += 4 * (i - 4) * (area - 7);
                ans += 4 * (i - 4) * (area - 5);
                ans += 4 * (area - 5); //diag corner things
                ans += 8 * (area - 4); //8 side corner things
                ans += 4 * (area - 3); //4 corners
            }

            std::cout << ans / 2 << '\n';
            
        }
        
    }

    return 0;
    
}