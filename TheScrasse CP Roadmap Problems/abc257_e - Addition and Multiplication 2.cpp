#include<bits/stdc++.h>

/*

Observations

1. Logically speaking, we'd want to maximize the number of digits in the number, since more digits = bigger number

2. After we maximize the total # of digits, we should try maximizing the first few digits as we go along

*/

int main (){

    int N;
    std::cin >> N;
    std::vector<int> C (9);
    int cheap = INT_MAX;
    for (int i = 0; i < 9; i++){
        std::cin >> C[i];
        cheap = std::min(cheap, C[i]);
    }

    int maxxdig = N / cheap;
    for (int i = 0; i < maxxdig; i++){
        int bigdig = 0, cost = 0;
        for (int j = 0; j < 9; j++){
            if (N - C[j] >= 0 && ((N - C[j]) / cheap) >= (maxxdig - (i + 1))){
                bigdig = j + 1, cost = C[j];
            }
        }
        std::cout << bigdig;
        N -= cost;
    }
    
    return 0;
    
}