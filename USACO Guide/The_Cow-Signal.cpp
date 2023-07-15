#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> big (std::vector<std::string>& signal, int M, int N, int K){
    std::vector<std::string> bigger (K * M);
    for (int i = 0; i < K * M; i += K){
        for (int j = 0; j < N; j++){
            for (int m = 0; m < K; m++){
                bigger[i] += signal[i / K][j];
            }
        }
        for (int j = i; j < i + K; j++){
            bigger[j] = bigger[i];
        }
    }
    return bigger;
}

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int M, N, K;
    std::cin >> M >> N >> K;
    std::vector<std::string> signal (M);
    for (int i = 0; i < M; i++){
        std::cin >> signal[i];
    }
    signal = big(signal, M, N, K);
    for (int i = 0; i < K * M; i++){
        std::cout << signal[i] << '\n';
    }
    return 0;
}