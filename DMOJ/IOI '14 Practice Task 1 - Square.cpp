/*

Main notes:
DP[i][j] tells us the biggest square with bottom right corner at grid[i][j]

Logic: We will examine top left, top and left nodes to determine the value of DP

If either is bad material, max size = 1

else
DP[i][j] = min (top left, top, left) + 1

Default top row and left column with 1's since theyre on the edge

*/

#include <iostream>
#include <string.h>
#include <algorithm>

int grid[1000][1000], DP[1000][1000];

int main(){
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cin >> grid[i][j];
        }
    }
    int largest = 1, count = 0;
    for (int i = 0; i < n; i++){
        if (grid[i][0] != 0){
            DP[i][0] = 1;
            count++;
        }
        if (grid[0][i] != 0){
            DP[0][i] = 1;
            count++;
        }
    }
    if (grid[0][0] == 1){
        count--;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if (grid[i][j] == 0){
                continue;
            }
            else if (grid[i - 1][j - 1] != 0 && grid[i - 1][j] != 0 && grid[i][j - 1] != 0){
                int smallest = 21474838;
                smallest = std::min(smallest, DP[i - 1][j - 1]);
                smallest = std::min(smallest, DP[i - 1][j]);
                smallest = std::min(smallest, DP[i][j - 1]);
                DP[i][j] = smallest + 1;
                if (DP[i][j] > largest){
                    largest = DP[i][j];
                    count = 1;
                }
                else if (DP[i][j] == largest){
                    count++;
                }
            }
            else{
                DP[i][j] = 1;
                if (largest == 1){
                    count++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << DP[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << largest * count << '\n';
    return 0;
}