#include <bits/stdc++.h>

int N;
int a [3000];
long long DP [3000][3000]; //Let DP[i][j] tell us the max score that Taro can obtain from segment l --> r

//Pretend that we're playing as Taro
long long solve (int l, int r){

    //Game finished
    //There are no more numbers to take, therefore you can only add 0 to your score
    if (l > r){
        return 0;
    }

    //Lookup
    if (DP[l][r] != -1) return DP[l][r];

    //We must take min, since Jiro will always attempt to play optimally and maximize Y
    //Take from left
    //After we take from left, either Jiro will take from right, or from left again
    long long takeLeft = a[l] + std::min(solve(l + 1, r - 1), solve(l + 2, r));
    //Take from right
    //After we take from right, either Jiro takes from left, or from right again
    long long takeRight = a[r] + std::min(solve(l + 1, r - 1), solve(l, r - 2));

    //Jiro's optimal plays will decrease our number a bit
    //But still, Taro will be trying to maximize his score so we take max
    return DP[l][r] = std::max(takeLeft, takeRight);
    
}

int main (){

    memset(DP, -1, sizeof(DP));
    long long sum = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
        sum += a[i];
    }

    long long X = solve(0, N - 1);
    long long Y = sum - X; //Jiro would have all the stones that Taro didn't take

    std::cout << X - Y << '\n';
    
    return 0;
    
}