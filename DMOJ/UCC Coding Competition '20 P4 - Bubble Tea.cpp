#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

int main(){
    
    int N;
    std::cin >> N;

    int orders[N + 1];
    for (int i = 1; i <= N; i++){
        std::cin >> orders[i];
    }

    std::vector<int> DP (N + 1, 2147483647);
    DP[0] = 0;
    
    for (int i = 1; i <= N; i++){

        if (i - 1 >= 0){
            DP[i] = std::min(DP[i], DP[i - 1] + orders[i]);
        }

        if (i - 2 >= 0){
            std::vector<int> group;
            group.push_back(orders[i]);
            group.push_back(orders[i - 1]);
            std::sort(group.begin(), group.end());
            int cost = group[0] * 0.75 + group[1];
            DP[i] = std::min(DP[i], DP[i - 2] + cost);
        }

        if (i - 3 >= 0){
            std::vector<int> group;
            group.push_back(orders[i]);
            group.push_back(orders[i - 1]);
            group.push_back(orders[i - 2]);
            std::sort(group.begin(), group.end());
            int cost = group[0] * 0.5 + group[1] + group[2];
            DP[i] = std::min(DP[i], DP[i - 3] + cost);
        }
        
    }

    std::cout << DP[N] << '\n';
    return 0;
    
}