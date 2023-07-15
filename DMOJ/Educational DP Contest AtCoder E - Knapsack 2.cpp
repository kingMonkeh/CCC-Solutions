#include <bits/stdc++.h>

/*

let DP[i][j] tell us the minimum weight required to get j value, using the first i items
0/1 knapsack style, either you choose to take or not take
if value of item is greater than what your j value, you can't take

take min between take and no take
memoize

*/

int N, W;
std::vector<std::pair<int, int>> items;
std::vector<std::vector<long long>> DP (101, std::vector<long long> (100001, LLONG_MAX));

long long solve (int item, int value){

    if (DP[item][value] != LLONG_MAX){
        return DP[item][value];
    }

    long long ans;
    if (item == 0){
        if (value == 0) ans = 0;
        else ans = INT_MAX;
    }
    else if (items[item].second > value){
        ans = solve(item - 1, value); //don't take
    }
    else{
        long long take = items[item].first + solve(item - 1, value - items[item].second); //take
        long long noTake = solve(item - 1, value);
        ans = std::min(take, noTake); //don't take
    }

    DP[item][value] = ans;
    return ans;
    
}

int main (){

    std::cin >> N >> W;
    items.resize(N + 1);
    int max_val = 0;
    for (int i = 1; i <= N; i++){
        std::cin >> items[i].first >> items[i].second;
        max_val += items[i].second;
    }

    //Try every possible value
    for (int i = max_val; i >= 0; i--){
        solve(N, i); //Solve for DP[N][val], aka min weight to get value i, using all the items
        if (DP[N][i] <= W){
            std::cout << i << '\n';
            break;
        }
    }
    
    return 0;
    
}