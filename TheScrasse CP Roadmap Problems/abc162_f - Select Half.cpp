#include <bits/stdc++.h>

/*

Observations: 

*/

long long A [200001], prefixodd [200001], DP [200001];

int main (){

    int N;
    std::cin >> N;
    
    for (int i = 1; i <= N; i++){
        std::cin >> A[i];
        if (i & 1) prefixodd[i] = i > 1 ? prefixodd[i - 2] + A[i] : A[i];
    }

    
    for (int i = 2; i <= N; i++){
        //if odd
        if (i & 1){
            //You take this or you don't take if you took the previous even
            DP[i] = std::max(DP[i - 2] + A[i], DP[i - 1]);
        }
        //if even
        else{
            //take this, or you reset it if the prefix of odd index terms is better choice, then you can continue again
            DP[i] = std::max(DP[i - 2] + A[i], prefixodd[i - 1]);
        }
    }

    std::cout << DP[N] << '\n';
    
    return 0;
    
}