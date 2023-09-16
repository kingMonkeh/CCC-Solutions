#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

/*

trailing zeros

n = _____0000
we can seperate this as _____ * 10^p for some p

we prime factorize 10 to determine that 10 = 5 * 2
if we prime factorize n! and let the number of fives and twos = 5^f and 2^t
the answer is min(f, t)

we notice however that f <= t always since 5 > 2

we now just count the # of times 5 can be factored out from n! using binary search

*/

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        int fives = 0;
        int cur = 1;
        while (cur * 5 <= n){
            cur *= 5;
            int l = 0, r = 1e9;
            while (r - l > 1){
                int mid = (l + r) / 2;
                if (cur * mid > n) r = mid;
                else l = mid;
            }
            fives += l;
        }

        std::cout << fives;
        
    }

    return 0;
    
}