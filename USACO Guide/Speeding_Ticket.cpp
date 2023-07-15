#include <cstdio>
#include <iostream>
#include <algorithm>

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M;
    std::cin >> N >> M;
    int road [100], bessie [100];
    int ind = 0;
    for (int i = 0; i < N; i++){
        int length, limit;
        std::cin >> length >> limit;
        for (int j = 0; j < length; j++){
            road[ind] = limit;
            ind++;
        }
    }
    ind = 0;
    for (int i = 0; i < M; i++){
        int length, speed;
        std::cin >> length >> speed;
        for (int j = 0; j < length; j++){
            bessie[ind] = speed;
            ind++;
        }
    }
    int ans = 0;
    /*
    for (int i = 0; i < 100; i++){
        std::cout << road[i] << ' ';
    }std::cout << '\n';
    for (int i = 0; i < 100; i++){
        std::cout << bessie[i] << ' ';
    }
    */
    for (int i = 0; i < 100; i++){
        ans = std::max(ans, bessie[i] - road[i]);
    }
    std::cout << ans;
    return 0;
}