#include <bits/stdc++.h>

/*

Observations: 

The value of a is extremely small, this is a hint that our answer should have to relate to it

We notice that we can use Kadane's maximal subarray algorithm to solve the problem, let's see how we can reduce our problem to it

Let mx represent the max element of the subarray, aka the element that Bob would end up removing
Any a[i] > mx, would not be in the subarray since Bob would have removed that element instead

Therefore, we try every mx value in the range 0 --> 30 and perform Kadane's algorithm each time

For every a[i] > mx, we set to -inf to ensure that the algorithm does not consider it as an optimal subarray

*/

const long long inf = 1e9;

int main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<long long> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        long long ans = 0;
        for (int mx = 0; mx < 31; mx++){
            long long val = a[0] > mx ? -inf : a[0];
            long long cur = val, best = val;
            for (int i = 1; i < n; i++){
                val = a[i] > mx ? -inf : a[i];
                cur = std::max(cur + val, val);
                best = std::max(best, cur);
            }
            ans = std::max(ans, best - mx); //remember that we have to take out mx after we sum them up
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}