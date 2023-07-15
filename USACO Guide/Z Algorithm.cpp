/*
https://personal.utdallas.edu/~besp/demo/John2010/z-algorithm.htm
Very useful site to visualize Z algorithm
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int N;

void Z_algorithm (std::vector<int>& Z, std::string& S){
    int l = 0, r = 0;
    for (int i = 1; i < N; i++){
        //We're in an already searched prefix
        if (i < r){
            Z[i] = std::min(r - i, Z[i - l]);
        }
        //Manual compare
        while (i + Z[i] < N && S[Z[i]] == S[i + Z[i]]){
            Z[i]++;
        }
        //Update segment if necessary
        if (i + Z[i] > r){
            l = i;
            r = l + Z[i];
        }
    }
}

int main (){
    std::string S;
    std::cin >> S;
    N = S.size();
    std::vector<int> Z (N, 0);
    Z_algorithm(Z, S);
    Z[0] = N;
    for (int i = 0; i < N; i++){
        std::cout << Z[i] << ' ';
    }
    return 0;
}