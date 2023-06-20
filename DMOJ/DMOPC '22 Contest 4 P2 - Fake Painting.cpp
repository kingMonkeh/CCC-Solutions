/*

Basically for cell i, j (a) there's 3 cells that correspond to it:
cell N - i - 1, j  (b)
cell i, M - j - 1 (c)
cell N - i - 1, M - j - 1 (d)

basically a + d = b + c
Cus like imagine a 2x2 chessboard
When you do change, it hits black and white square
Then it swaps them around
But regardless of your next move, youl always hit 1 black square and 1 white square
Therefore they must be equal

For center cell, it just has to be even since 2 * K is even

For center row or center column
Theres only 2 cells to consider
Their sums must be even since K is applied an even amount of times across the two cells

*/

#include <iostream>

int main(){
    int N, M;
    std::cin >> N >> M;
    int orig[N][M], hori[N][M], potential[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cin >> orig[i][j];
            hori[i][M - j - 1] = orig[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cin >> potential[i][j];
        }
    }
    //Try no flip
    for (int i = 0; i < (N + 1) / 2; i++){
        for (int j = 0; j < (M + 1) / 2; j++){
            //Center
            if (i == N / 2 && j == M / 2 && N % 2 == 1 && M % 2 == 1){
                if ((orig[i][j] - potential[i][j]) % 2 != 0){
                    goto HOR;
                }
            }
            //Center row
            else if (i == N / 2 && N % 2 == 1){
                if (((orig[i][j] - potential[i][j]) + (orig[i][M - j - 1] - potential[i][M - j - 1])) % 2 != 0){
                    goto HOR;
                }
            }
            //Center column
            else if (j == M / 2 && M % 2 == 1){
                if (((orig[i][j] - potential[i][j]) + (orig[N - i - 1][j] - potential[N - i - 1][j])) % 2 != 0){
                    goto HOR;
                }
            }
            //Anywhere else
            else{
                if (((orig[i][j] - potential[i][j]) + (orig[N - i - 1][M - j - 1] - potential[N - i - 1][M - j - 1])) != ((orig[i][M - j - 1] - potential[i][M - j - 1]) + (orig[N - i - 1][j] - potential[N - i - 1][j]))){
                    goto HOR;
                }
            }
        }
    }
    std::cout << "YES\n";
    return 0;
    //Try horizontal
    HOR:;
    for (int i = 0; i < (N + 1) / 2; i++){
        for (int j = 0; j < (M + 1) / 2; j++){
            //Center
            if (i == N / 2 && j == M / 2 && N % 2 == 1 && M % 2 == 1){
                if ((hori[i][j] - potential[i][j]) % 2 != 0){
                    goto END;
                }
            }
            //Center row
            else if (i == N / 2 && N % 2 == 1){
                if (((hori[i][j] - potential[i][j]) + (hori[i][M - j - 1] - potential[i][M - j - 1])) % 2 != 0){
                    goto END;
                }
            }
            //Center column
            else if (j == M / 2 && M % 2 == 1){
                if (((hori[i][j] - potential[i][j]) + (hori[N - i - 1][j] - potential[N - i - 1][j])) % 2 != 0){
                    goto END;
                }
            }
            //Anywhere else
            else{
                if (((hori[i][j] - potential[i][j]) + (hori[N - i - 1][M - j - 1] - potential[N - i - 1][M - j - 1])) != ((hori[i][M - j - 1] - potential[i][M - j - 1]) + (hori[N - i - 1][j] - potential[N - i - 1][j]))){
                    goto END;
                }
            }
        }
    }
    std::cout << "YES\n";
    return 0;
    END:;
    std::cout << "NO\n";
    return 0;
}