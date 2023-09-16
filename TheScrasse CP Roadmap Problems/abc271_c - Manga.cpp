//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int N;
        std::cin >> N;

        int sell = 0;
        std::map<int, int> have;
        std::vector<int> books (N);
        for (auto& a: books){
            std::cin >> a;
            if (a > N) sell++; //out of bounds, sell
            else if (have[a]) sell++; //duplicate sell
            else have[a] = true; //keep, new
        }

        int L = 1, R = N + 1;
        while (true){
            while (have[L]) L++;
            while (R != 0 && !have[R]) R--;
            if (sell >= 2){
                sell -= 2;
                have[L] = true;
            }
            else{
                if (L >= R) break;
                have[R] = false;
                sell++;
            }
        }

        std::cout << --L << '\n';
        
    }
    
    return 0;
    
}