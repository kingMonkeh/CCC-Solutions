/*

Remember that you can answer with any value so long as it passes the criteria
Therefore for the  missing number in a row
All numbers in that row must contain the 1's found in the bit of that unknown number since bitwise and requires both numbers that have 1 as the bit
Therefore, the unknown value must be the bitwise or operator of all items in that row

*/

#include <iostream>

int main(){
    int N;
    std::cin >> N;
    int matrix [N][N];
    int code [N];
    for (int i = 0; i < N; i++){
        int a = 0;
        for (int j = 0; j < N; j++){
            std::cin >> matrix[i][j];
            if (j == i){
                continue;
            }
            a = a | matrix[i][j];
        }
        std::cout << a << ' ';
    }
    return 0;
}