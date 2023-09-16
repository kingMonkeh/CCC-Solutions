//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

std::map<long long, long long> DP;

long long f (long long k){
    if (DP[k]) return DP[k];
    return DP[k] = (k == 0 ? 1 : f(k / 2) + f(k / 3));
}

int main(){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        long long N;
        std::cin >> N;
        std::cout << f(N) << '\n';
        
    }
    
    return 0;
    
}