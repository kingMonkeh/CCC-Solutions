#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

/*

let x = # of 2 coin left 1 coin right, y = # of 1 coin left 2 coin right

a = 2x + y, b = x + 2y

2a = 4x + 2y

2a - b = 3x, (2a - b) / 3 = x

y = a - 2x

*/

signed main (){

    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){

        int a, b;
        std::cin >> a >> b;

        double x = (2 * a - b) / 3.0;
        double y = a - 2.0 * x;

        if (ceil(x) != x || ceil(y) != y || x < 0 || y < 0){
            std::cout << "NO\n";
        }
        else std::cout << "YES\n";
        
    }

    return 0;
    
}