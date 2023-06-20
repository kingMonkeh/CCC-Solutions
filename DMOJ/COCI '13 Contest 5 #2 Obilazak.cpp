/*

could also be done recursively, doesn't really matter

*/

#include <iostream>
#include <vector>

int main (){
    int K;
    std::cin >> K;
    int total = 1 << K;
    int houses [total];
    for (int i = 1; i <= total; i++){
        std::cin >> houses[i];
    }
    std::vector<int> levels [K];
    int cur_level = K - 1;
    int left = 1, jump = 2;
    for (int i = 0; i < K; i++){
        for (int j = left; j <= total; j += jump){
            levels[cur_level].push_back(houses[j]);
        }
        left = left << 1;
        jump = jump << 1;
        cur_level--;
    }
    for (int i = 0; i < K; i++){
        for (int& node: levels[i]){
            std::cout << node << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}