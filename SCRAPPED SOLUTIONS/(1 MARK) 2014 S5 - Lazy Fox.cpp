#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <math.h>

#define xDiff points[i].first - points[curPoint].first
#define yDiff points[i].second - points[curPoint].second

int N;
std::vector<std::pair<int, int>> points;
std::map<std::pair<int, int>, int> DP;

int solve(int maxDist = 2147483647, int curPoint = 0, int treats = 0){

    if (DP[{curPoint, maxDist}]){
        DP[{curPoint, maxDist}] = std::max(DP[{curPoint, maxDist}], treats);
        return DP[{curPoint, maxDist}];
    }

    int max = treats;

    for (int i = 1; i <= N; i++){
        if (i == curPoint) continue;
        int dist = (xDiff) * (xDiff) + (yDiff) * (yDiff);
        if (dist < maxDist){
            max = std::max(max, solve(dist, i, treats + 1));
        }
    }

    DP[{curPoint, maxDist}] = max;
    return max;

}

int main(){

    
    std::cin >> N;

    points.resize(N + 1);

    points[0] = {0, 0};

    for (int i = 1; i <= N; i++){
        int x, y;
        std::cin >> x >> y;
        points[i] = std::make_pair(x, y);
    }

    std::cout << solve() << '\n';

    return 0;

}