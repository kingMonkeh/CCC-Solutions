#include <iostream>
#include <algorithm>

int n, k, w;
int blocks [30000];
int answer = 0;

void solve(int ballsLeft, int left, int total){

    total += blocks[left];
    
    if (ballsLeft == 0){
        answer = std::max(answer, total);
    }

    else{
        for (int i = left + w; i <= n - ballsLeft * w; i++){
            solve (ballsLeft - 1, i, total);
        }
    }
    
}

int main(){

    int t;
    std::cin >> t;

    while (t--){
   
        std::cin >> n >> k >> w;

        int pins [n]; int total = 0;
        for (int i = 0; i < n; i++){
            std::cin >> pins[i];
            total += pins[i];
        }

        if (k * w >= n){
            std::cout << total << '\n';
            continue;
        }

        blocks[0] = 0;
        for (int i = 0; i < w; i++){
            blocks[0] += pins[i];
        }

        for (int i = 1; i < n; i++){
            blocks[i] = blocks[i - 1] - pins[i - 1];
            if (i + w - 1 < n){
                blocks[i] += pins[i + w - 1];
            }
        }

        //for (auto x: blocks) std::cout << x << ' ';

        for (int i = 0; i <= n - ((k - 1) * w); i++){
            solve(k - 1, i, 0);
        }

        std::cout << answer << '\n';
        answer = 0;
        
    }
    
    return 0;
    
}