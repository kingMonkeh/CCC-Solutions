#include <bits/stdc++.h>

/*

Binary search on the total # of projects one can complete

Let x be the # of projects we want to complete
Notice that for any given office

At max only min(A[i], x) employees will actually be able to partake in a project if we want to make exactly x projects

Let sum the be the sum of min(A[i], x) for all 1 <= i <= N

if sum >= K * x, then we can complete x projects, otherwise, no

*/

long long N, K;
long long A [200000];
bool f (long long x){
    unsigned long long sum = 0;
    for (int i = 0; i < N; i++) sum += std::min(A[i], x);
    unsigned long long req = (unsigned long long) K * x;
    return sum >= req;
}

int main (){

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) std::cin >> A[i];

    long long l = 0, r = 1e18 + 1;
    while (r - l > 1){
        long long mid = (l + r) / 2;
        if (f(mid)) l = mid;
        else r = mid;
    }

    std::cout << l << '\n';
    
    return 0;
    
}