#include <bits/stdc++.h>

/*

We notice that the sum of 1 + 2 + 3 + ... + 2n is divisible by n

This means that any series past 2n, we will witness the same modulus pattern making it pointless to check any further

We can now just simulate it

*/

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        long long n, x, p;
        std::cin >> n >> x >> p;
        long long dist = n - x;

        std::string ans = "NO";
        long long sum = 0;
        for (long long i = 1; i <= 2 * n && i <= p; i++){
            sum += i;
            if (((x + sum) % n) == 0){
                ans = "YES";
                break;
            }
        }

        std::cout << ans << '\n';
            
    }
    
    return 0;
    
}