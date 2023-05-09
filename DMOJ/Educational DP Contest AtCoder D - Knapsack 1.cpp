/*

Textbook 0-1 Knapsack problem

Work backwards

DP[i][j] tells us the max value we can get with the items from i to N, with j weight remaining in our sack

*/

#include <iostream>
#include <utility>
#include <algorithm>

long long DP[101][100001];
std::pair<long long, long long> items [101];

long long solve(long long item, long long weightLeft){
    
    if (DP[item][weightLeft] != -1){
        return DP[item][weightLeft];
    }
    
    long long ans;
    
    //End of items or no more weight, then we can't get any more value
    if (item == 0 || weightLeft == 0){
        ans = 0;
    }
    //Item too big for sack, try next item
    else if (items[item].first > weightLeft){
        ans = solve(item - 1, weightLeft);
    }
    //Try taking item (state 1) or not taking (state 0), take max
    else{
        long long take = items[item].second + solve(item - 1, weightLeft - items[item].first);
        long long noTake = solve(item - 1, weightLeft);
        ans = std::max(take, noTake);
    }
    
    DP[item][weightLeft] = ans; //Memoize
    return ans; //Return
    
}

int main(){
    long long N, W;
    std::cin >> N >> W;
    for (int i = 0; i <= 100; i++){
        for (int j = 0; j <= 100000; j++){
            DP[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i++){
        long long w, v;
        std::cin >> w >> v;
        items[i] = {w, v};
    }
    std::cout << solve(N, W);
    return 0;
}