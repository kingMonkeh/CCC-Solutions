#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    std::map<int, std::vector<std::pair<int, int>>> coupons;
    for (int i = 0; i < N; i++){
        std::pair<int, int> coupon;
        std::cin >> coupon.first >> coupon.second;
        int V = coupon.first + coupon.second;
        coupons[V].push_back(coupon);
    }
    long long best = 0;
    //For each group of coupons
    for (auto& group: coupons){
        //std::cout << group.first << '\n';
        //Sort descending, since you would want to take the max amount of keyboards as possible, and then fill the rest with monitors
        std::sort(group.second.begin(), group.second.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){
            return a.first > b.first;
        });
        /*
        for (auto& p: group.second){
            std::cout << "{" << p.first << ", " << p.second << "} ";
        } std::cout << '\n';
        */
        //Basically, take some amount of K's, then the rest must be M's
        std::vector<long long> prefixSum (group.second.size() + 1); //K's
        std::vector<long long> revPrefix (group.second.size() + 1); //M's
        long long counter = 0, revCounter = 0;
        for (int i = 0; i < group.second.size(); i++){
            counter += group.second[i].first;
            revCounter += group.second[group.second.size() - 1 - i].second;
            prefixSum[i] = counter;
            revPrefix[i] = revCounter;
        }
        /*
        for (int i = 0; i < group.second.size(); i++) std::cout << prefixSum[i] << ' ';
        std::cout << '\n';
        for (int i = 0; i < group.second.size(); i++) std::cout << revPrefix[i] << ' ';
        std::cout << '\n';
        */
        //Compare max
        for (int i = 0; i < group.second.size() - 1; i++){
            best = std::max(best, std::min(prefixSum[i], revPrefix[group.second.size() - 2 - i]));
        }
    }
    std::cout << best;
    return 0;
}