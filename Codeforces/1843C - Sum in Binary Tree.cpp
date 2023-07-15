#include <bits/stdc++.h>

/*

Work Backwards
Divide by 2 to reach parent node, property of binary trees

*/

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        long long n;
        std::cin >> n;
        long long ans = 0;
        while (n > 1){
            ans += n;
            n /= 2;
        }
        std::cout << ans + 1 << '\n';
    }
    return 0;
}