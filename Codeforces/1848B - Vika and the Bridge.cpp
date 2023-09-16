/*

greedy idea:

for each color, find the max dist between any two planks of that color

now we want to choose the color that has the smallest max dist
basically to reduce the max distance, we just want to place the plank in the middle
this cuts the distance in half

now compare this to the second biggest distance and take the max of the 2 now

this is your answer

*/

#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n, k;
        std::cin >> n >> k;

        std::vector<std::pair<int, int>> max_dist (k + 1, {0, 0});
        std::vector<std::vector<int>> planks (k + 1);
        for (int i = 0; i < n; i++){
            int color;
            std::cin >> color;
            planks[color].push_back(i);
            if (planks[color].size() == 1){
                max_dist[color].first = i;
            }
            else{
                int dist = i - planks[color][(int) planks[color].size() - 2] - 1;
                if (dist >= max_dist[color].first){
                    max_dist[color].second = max_dist[color].first;
                    max_dist[color].first = dist;
                }
                else if (dist > max_dist[color].second){
                    max_dist[color].second = dist;
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i <= k; i++){
            if (!planks[i].empty()){
                int dist = n - planks[i][(int) planks[i].size() - 1] - 1;
                if (dist >= max_dist[i].first){
                    max_dist[i].second = max_dist[i].first;
                    max_dist[i].first = dist;
                }
                else if (dist > max_dist[i].second){
                    max_dist[i].second = dist;
                }
                ans = std::min(ans, std::max(max_dist[i].first / 2, max_dist[i].second));
            }
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}