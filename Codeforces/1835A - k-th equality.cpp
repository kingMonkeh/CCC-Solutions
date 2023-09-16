#include <bits/stdc++.h>

/*

We notice max value for a is 10^6

So we can iterate through every value of a and find the corresponding number of b's and c's

Although there are 3000 test cases, its stated in the problem that at most five cases will have A, B, C >= 3

Therefore this approach is much more efficient in reality than in theory

By fixing a we note 2 equalities which must be satisfied

10^(C - 1) <= a + b < 10^C
10^(B - 1) <= b < 10^B

we can rearrange the first inequality to determine
10^(C - 1) - a <= b < 10^C - a

therefore, we can now calculate the min b value and max b value for a fixed a
then the total equalities for this a = max_b - min_b + 1 (inclusive)

To get the kth equality, we just start from the smallest a values as that would gurantee a lexicographically smallest equation

*/

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int A, B, C;
        long long k;
        std::cin >> A >> B >> C >> k;

        long long equalities = 0; //total amount
        for (int a = pow(10, A - 1); a < pow(10, A); a++){
            int min_b = std::max(pow(10, C - 1) - a, pow(10, B - 1)); //make sure both will be satisfied
            int max_b = std::min(pow(10, C) - a - 1, pow(10, B) - 1);
            if (min_b > max_b) continue; //impossible b value
            equalities += max_b - min_b + 1;
            if (equalities >= k){
                long long b = max_b - (equalities - k);
                std::cout << a << " + " << b << " = " << a + b << '\n';
                break;
            }
        }

        if (equalities < k) std::cout << -1 << '\n';
        
    }
    
    return 0;
    
}