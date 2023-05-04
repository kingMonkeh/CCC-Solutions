/*

Basic map problem, just use map
Greedily pick the items
aka sort their prices least to greatest
Keep taking from least to greatest until you have enough

*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

int main(){
    int T;
    std::cin >> T;
    while (T--){
        std::map<std::string, std::vector<std::pair<int, int>>> items;
        int N;
        std::cin >> N;
        for (int i = 0; i < N; i++){
            int M;
            std::cin >> M;
            for (int j = 0; j < M; j++){
                std::string item;
                std::cin >> item;
                int price, quantity;
                std::cin >> price >> quantity;
                items[item].push_back(std::make_pair(price, quantity));
            }
        }
        int K, totalCost = 0;
        std::cin >> K;
        for (int i = 0; i < K; i++){
            std::string item;
            std::cin >> item;
            int required;
            std::cin >> required;
            std::sort(items[item].begin(), items[item].end());
            while (required){
                for (int j = 0; j < items[item].size(); j++){
                    if (items[item][j].second <= required){
                        totalCost += items[item][j].first * items[item][j].second;
                        required -= items[item][j].second;
                    }
                    else{
                        totalCost += items[item][j].first * required;
                        required = 0;
                        break;
                    }
                }
            }
        }
        std::cout << totalCost << '\n';
    }
    return 0;
}