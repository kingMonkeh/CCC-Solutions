#include<bits/stdc++.h>

long long N, K;
std::vector<long long> A;

bool f (long long cycles){
    long long apples = 0;
    for (int i = 0; i < N; i++){
        apples += std::min(cycles, A[i]);
    }
    return apples <= K;
}

int main (){

    std::cin >> N >> K;
    A.resize(N);
    for (auto& a: A) std::cin >> a;

    //Check how many full cycles we can perform
    long long l = 0, r = 1e12 + 1;
    while (r - l > 1){
        long long mid = (l + r) / 2;
        if (f(mid)) l = mid;
        else r = mid;
    }

    //Simulate the majority of cycles
    for (int i = 0; i < N; i++){
        long long eaten = std::min(l, A[i]);
        A[i] -= eaten;
        K -= eaten;
    }

    //Afterward, we have to cover for the partial cycle
    for (int i = 0; K > 0; i++){
        if (A[i] != 0){
            A[i]--;
            K--;
        }
    }

    for (auto& barrel: A) std::cout << barrel << ' ';
    
    return 0;
    
}