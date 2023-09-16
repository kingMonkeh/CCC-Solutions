/*

It makes greedy sense to increase the discount up to a certain point before continuously applying it

*/


#include <bits/stdc++.h>

//If you cycle 2 4 8 6, you're increasing by 20 each cycle, it takes 4 moves to cycle
long long f (long long& x, long long& s, long long k){
    return (s + 20 * x) * (k - 4 * x);
}

int main(){

    std::ios_base::sync_with_stdio(false);

    int tests;
    std::cin >> tests;
    while (tests--){

        long long s, k;
        std::cin >> s >> k;

        long long ans = s * k;

        //Manually go through until its either 2, or 0, or we run out of k
        while (k > 0 && s % 10 != 0 && s % 10 != 2){
            k--;
            s += s % 10;
            ans = std::max(ans, s * k);
        }

        //Your last digit is zero, you can't increase your discount, therefore just apply it for the remaining k moves you can make
        if (s % 10 == 0){
            std::cout << ans << '\n';
            continue;
        }

        //Basically we notice the digits cycle 2, 4, 8, 6 repeatedly
        //So you would basically just repeat this over and over and over
        //And then choose to stop at some digit, since we've fixed the digit to 2 initially
        //If we wanted to end at 4, we can manually add 4 to s, and then our final digit would be 4, afterwards we keep cycling until we reach 4, its the same as starting from 2, cycling to 2 and going to 4
        //2, ..., 2, 4 is the same as 2, 4, ..., 4
        int endDigit [4] = {2, 4, 8, 6};
        //End digit that we stop at, meaning not including yet
        for (int endDig = 0; endDig < 4; endDig++) if (endDig <= k){

            //Since we're doing batches of 4, we can do at max (k - endDig) / 4 cycles
            long long l = 0, r = (k - endDig) / 4;

            //Perform ternary search
            //We can ternary search since the f(x) is quadratic, meaning it increases up to a certain point and then always will decrease
            while (r - l > 3){
                long long m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                if (f(m1, s, k - endDig) < f(m2, s, k - endDig)) l = m1;
                else r = m2;
            }

            for (long long x = l; x <= r; x++){
                ans = std::max(ans, f(x, s, k - endDig));
            }

            s += endDigit[endDig];
            
        }

        std::cout << ans << '\n';
        
    }

    return 0;
    
}