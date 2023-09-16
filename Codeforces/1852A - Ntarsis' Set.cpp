/*

initially the answer is 1, since no changes have been applied

now lets think about simulating these deletions
let x be our current answer

we notice that a[i] only begin to affect our x once x surpasses a[i]
otherwise x is only affected by all a[j] such that a[j] <= x

therefore every day, x will increase by j elements such that a[j] <= x
however at the same time that we increase x, its possible now that some a[i] which was originally greater than x
becomes less than or equal to x
a[i] <= x + j

*/

#include <bits/stdc++.h>

int main() {
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {
        
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        long long ans = 1, i = 0;
        while(k--){
            //check all i that will impact
            while (i < n && a[i] <= ans + i){
                i++;
            }
            ans += i;
        }

        std::cout << ans << '\n';
        
    }

    return 0;
    
}