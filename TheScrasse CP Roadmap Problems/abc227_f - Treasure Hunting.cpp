#include<bits/stdc++.h>

int H, W, K;
long long A [35][35], DP [35][35][65]; //DP[row][col][# of ints >= kth so far]
long long ans = LONG_LONG_MAX;

void solve (int kth, int origr, int origc){

    //memset
    for (int i = 0; i < 35; i++) for (int j = 0; j < 35; j++) for (int k = 0; k < 65; k++) DP[i][j][k] = (long long) INT_MAX * 100;

    //base case, the first square, aka where we start
    //if > kth, we have to include, since we must start here
    if (A[1][1] > kth) DP[1][1][1] = A[1][1];
    else DP[1][1][0] = 0;

    //special case, the kth largest square is the starting square, in this case its impossible to have 0 terms >= kth started already while standing on the starting square
    if (origr == 1 && origc == 1){
        DP[1][1][1] = A[1][1];
        DP[1][1][0] = LONG_LONG_MAX;
    }

    //Now we just traverse the grid, and do some normal DP
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            for (int k = 0; k <= K; k++){
                if (DP[i][j][k] == LONG_LONG_MAX) continue; //special case mentioned earlier
                //If we can go down
                if (i + 1 <= H){
                    //if downwards, the element is >= kth and may be apart of our sum
                    if (A[i + 1][j] >= kth){
                        if (A[i + 1][j] >= kth){
                            //either keep its path, or change to cur path + element
                            DP[i + 1][j][k + 1] = std::min(DP[i + 1][j][k + 1], DP[i][j][k] + A[i + 1][j]);
                        }
                        //you could also choose to just not take that square as well
                        if (A[i + 1][j] == kth){
                            DP[i + 1][j][k] = std::min(DP[i + 1][j][k], DP[i][j][k]);
                        }
                    }
                    else{
                        DP[i + 1][j][k] = std::min(DP[i + 1][j][k], DP[i][j][k]);
                    }
                }
                //if we can go right
                if (j + 1 <= W){
                    if (A[i][j + 1] >= kth){
                        if (A[i][j + 1] >= kth){
                            DP[i][j + 1][k + 1] = std::min(DP[i][j + 1][k + 1], DP[i][j][k] + A[i][j + 1]);
                        }
                        if (A[i][j + 1] == kth){
                            DP[i][j + 1][k] = std::min(DP[i][j + 1][k], DP[i][j][k]);
                        }
                    }
                    else{
                        DP[i][j + 1][k] = std::min(DP[i][j + 1][k], DP[i][j][k]);
                    }
                }
            }
        }
    }

    ans = std::min(ans, DP[H][W][K]);
    
}

int main (){

    std::cin >> H >> W >> K;

    for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) std::cin >> A[i][j];

    //Idea: For every square, let's say that this square, is the Kth largest integer of the path
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            solve (A[i][j], i, j);
        }
    }

    std::cout << ans << '\n';
    
    return 0;
    
}