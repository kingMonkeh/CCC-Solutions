/*

the greater the value you want MEX to return, the more numbers you need to include
very inefficient for large primes
therefore we want to maximize the # of MEX that result in either 2 or 3 cus they're small

We basically plop 2 in the front and 3 in the back
and then you put 1 in the middle
This allows you to maximize the number of MEX with 2 and 3

*/

#include <bits/stdc++.h>
 
int main(){
 
    int tests;
    std::cin >> tests;
    while (tests--){
 
        int n;
        std::cin >> n;
 
        int mid = n / 2;
 
        if (n >= 2) std::cout << 2 << ' ';
        for (int i = 4, ind = 1; i <= n; i++, ind++){
            if (ind == mid){
                std::cout << 1 << ' ';
                i--;
            }
            else
                std::cout << i << ' ';
        }
        if (n <= 4) std::cout << 1 << ' ';
        if (n >= 3) std::cout << 3 << ' ';
 
        std::cout << '\n';
        
    }
 
    return 0;
    
}
