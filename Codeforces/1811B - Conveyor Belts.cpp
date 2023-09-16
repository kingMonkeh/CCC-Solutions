#include <bits/stdc++.h>

int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {

        int n, x1, y1, x2, y2;
        std::cin >> n >> x1 >> y1 >> x2 >> y2;

        if (x1 > n / 2) x1 = n + 1 - x1;
        if (x2 > n / 2) x2 = n + 1 - x2;
        if (y1 > n / 2) y1 = n + 1 - y1;
        if (y2 > n / 2) y2 = n + 1 - y2;

        int m1, m2;
        if (y1 >= x1) m1 = x1;
        else m1 = y1;
        if (y2 >= x2) m2 = x2;
        else m2 = y2;
        
        std::cout << abs(m1 - m2) << '\n';
        
    }

    return 0;
    
}