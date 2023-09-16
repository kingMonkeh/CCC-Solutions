#include <bits/stdc++.h>

/*

Simple observation
we can try all values of k
we note however that if we choose the absolute minimum aka k^2 + k + 1 = n
we will have to iterate until k = 10^9 which is too much
therefore we will only precompute for k^3 + k^2 + k + 1 <= 10^18
here the max value of k = 10^6 which is doable

we can easily take care of cases where the polynomial is k^2 + k + 1
via finding the roots of the quadratic and checking that they're valid integers

if n < 7, its not possible because minimum snowflakes is 7 when k = 2

*/

long long limit = 1e18;
std::map<long long, int> nums;

int main(){

    //calculate all possible values for k + k^2 + k^3...
    for (int k = 2; k <= 1000000; k++){
        long long base = k + 1;
        long long term = 1LL * k * k; //k^ p
        for (int p = 2; p <= 60 && base <= limit; p++){
            if (base + term >= limit) break;
            base += term;
            nums[base] = true;
            if (term > 1e18 / k) break; //you will overflow if you continue
            term *= k;
        }
    }

    int tests;
    std::cin >> tests;
    while (tests--){
        long long n;
        std::cin >> n;
        if (n < 7){
            std::cout << "NO\n";
            continue;
        }
        //Find roots of quadratic, k^2 + k + 1 = n
        //dont use quadratic formula, too imprecise, instead use citardauq formula 
        long double a = 1, b = 1, c = 1 - n;
        long double root1 = 2 * c / (-b + sqrt(1 - 4 * c));
        long double root2 = 2 * c / (-b - sqrt(1 - 4 * c));
        if ((root1 > 1 && (long double) floor(root1) == root1) || (root2 > 1 && (long double) floor(root2) == root2)){
            std::cout << "YES\n";
        }
        else if (nums[n]){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
    
    return 0;
    
}