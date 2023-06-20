#include <iostream>
#include <string>
#include <algorithm>

int N, K;
std::string students [1000];

int maxmin = 0;
std::string key = "";
void solve (){
    if (key.length() == K){
        int minscore = 9999;
        for (int i = 0; i < N; i++){
            int score = 0;
            for (int j = 0; j < K; j++){
                if (key[j] == students[i][j]) score++;
            }
            minscore = std::min(minscore, score);
        }
        maxmin = std::max(maxmin, minscore);
    }
    else{
        key += 'T';
        solve();
        key.pop_back();
        key += 'F';
        solve();
        key.pop_back();
    }
}

int main(){
    std::cin >> N >> K;
    for (int i = 0; i < N; i++){
        std::cin >> students[i];
    }
    solve();
    std::cout << maxmin << '\n';
    return 0;
}