#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <cstring>

int main(){
    int N;
    std::cin >> N;
    std::vector<int> scores (N);
    for (int i = 0; i < N; i++){
        std::cin >> scores[i];
    }
    std::sort(scores.begin(), scores.end()); //sort increasing
    int H = 0;
    for (int i = 0; i < N; i++){
        //remember citations can be equal to or GREATER than H
        //if (elements remaining including current > current)
        if (N - i >= scores[i]){
            H = std::max(H, scores[i]);
        }
        //Once this is no longer the case, then the max is the remaining elements
        else{
            H = std::max(H, N - i);
            break;
        }
    }
    std::cout << H << '\n';
    return 0;
}