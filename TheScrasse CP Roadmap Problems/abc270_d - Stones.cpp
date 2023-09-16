#include<bits/stdc++.h>

/*

Greedy solution actually suboptimal

Imagine 
N = 10
A = {1, 3, 4}, greedy pick gives us ans = 5, correct = 6

Instead we do exhaustive search using DP

Let DP[N] tell us the total amount Takahashi can get with N stones remaining

We iterate through every stone combination of Takahashi and Aoki
And take min, since we must recall that Aoki is also trying to maximize his score

Take max of all mins

*/

int N, K;
std::vector<int> A (100);
int DP [10001];

int solve (int n){

    //Base case, 0 stone left, there's nothing to take
    if (n == 0) return 0;

    if (DP[n] != -1) return DP[n];

    int& ret = DP[n] = 0;
    //For every stone takahashi can take
    for (int i = 0; i < K; i++){
        bool change = false;
        int temp = INT_MAX, solo;
        //For every stone Aoki can take
        for (int j = 0; j < K; j++){
            if (n - A[i] - A[j] >= 0){
                //take min since, Aoki is trying to max his score as well
                temp = std::min(temp, A[i] + solve(n - A[i] - A[j]));
                change = true;
            }
            //special case, takahashi can win in one move, preventing Aoki from making a move
            if (n - A[i] == 0){
                temp = A[i];
                change = true;
                break;
            }
        }
        //Take max of the min
        if (change) ret = std::max(ret, temp);
    }

    return ret;
    
}

int main (){

    
    std::cin >> N >> K;
    
    for (auto& a: A) std::cin >> a;

    memset(DP, -1, sizeof(DP));

    std::cout << solve(N) << '\n';
    
    return 0;
    
}