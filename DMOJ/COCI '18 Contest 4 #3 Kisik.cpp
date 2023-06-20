#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> houses (N);
    for (int i = 0; i < N; i++){
        int W, H;
        std::cin >> W >> H;
        houses[i] = std::make_pair(H, W); //Height, width
    }
    //Sort increasing height, increasing width
    std::sort(houses.begin(), houses.end());
    //Actual logic
    std::priority_queue<int> widths;
    long long collectiveWidth = 0, ans = 9223372036854775807;
    //Basically, you automatically minimize height by sorting
    //Now, you add each house, once you're at K houses
    //You now have too many houses, you need to get rid of one, which one?
    //The one that takes the most width obviously
    for (int i = 0; i < N; i++){
        widths.push(houses[i].second);
        collectiveWidth += houses[i].second;
        if (i == K - 1){
            ans = std::min(ans, collectiveWidth * houses[i].first);
        }
        if (i >= K){
            collectiveWidth -= widths.top();
            widths.pop();
            ans = std::min(ans, collectiveWidth * houses[i].first);
        }
    }
    std::cout << ans << '\n';
    return 0;
}