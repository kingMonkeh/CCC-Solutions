#include <bits/stdc++.h>

/*

f(i) = 1 * f(i - 1) + 1 * f(i - 2)
f(i) = 2 * f(i - 2) + 1 * f(i - 3)
f(i) = 3 * f(i - 3) + 2 * f(i - 4)
f(i) = 5 * f(i - 4) + 3 * f(i - 5)
... Notice that the coefficients follow fibbonacci sequence as well

If n is term k in the sequence
We can continue this until we find the coefficients of f(0) and f(1)
Note that if n is unrestricted, in theory we would have to compute the first 1 billion fibonacci numbers

But since n is limited to 200 000, k at max is 29
Therefore very easy to precompute

Afterwards we will fix f(0), and see if they're is a corresponding f(1) that satisfies the equation

O(n) time complexity


*/

int main() {
    
	std::ios::sync_with_stdio(false);

    std::vector<int> fib (29);
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < 29; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    int tests;
    std::cin >> tests;
    while (tests--){
        
		int n, k;
        std::cin >> n >> k;

        if (k > 29){
            std::cout << 0 << '\n';
        }

        else{
            int ans = 0;
            int x1 = fib[k - 1], x2 = fib[k - 2];
            for (int i = 0; i <= n; i++){
                int c = x2 * i;
                if ((n - c) % x1 == 0 && (n - c) / x1 >= i){
                    ans++;
                }
            }
            std::cout << ans << '\n';
        }
        
	}
}