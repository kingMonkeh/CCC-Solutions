/*

Slightly more complex 0-1 Knapsack problem, in addition to weight (the food), you also have to consider time

Basically exact same logic, just with the extra constraint of time

DP[i][j][k] tells us max value from first i restaurants, j timeLeft, k room left in stomach

*/

#include <iostream>
#include <vector>
#include <algorithm>

int DP[151][301][101];
std::vector<int> restaurants [151];

int solve(int restaurant, int timeLeft, int stomachLeft){

    if (DP[restaurant][timeLeft][stomachLeft] != -1){
        return DP[restaurant][timeLeft][stomachLeft];
    }
    
    int ans;
    
    //Base case, we can't continue
    if (restaurant == 0 || timeLeft == 0 || stomachLeft == 0){
        ans = 0;
    }
    else if (restaurants[restaurant][1] > timeLeft || restaurants[restaurant][2] > stomachLeft){
        ans = solve(restaurant - 1, timeLeft, stomachLeft);
    }
    else{
        int eat = restaurants[restaurant][0] + solve(restaurant - 1, timeLeft - restaurants[restaurant][1], stomachLeft - restaurants[restaurant][2]);
        int noEat = solve(restaurant - 1, timeLeft, stomachLeft);
        ans = std::max(eat, noEat);
    }

    DP[restaurant][timeLeft][stomachLeft] = ans;
    return ans;
    
}

int main(){
    for (int i = 0; i <= 150; i++){
        for (int j = 0; j <= 300; j++){
            for (int k = 0; k <= 100; k++){
                DP[i][j][k] = -1;
            }
        }
    }
    int M, U, R; //mins, stomach, restaurants
    std::cin >> M >> U >> R;
    for (int i = 1; i <= R; i++){
        int V, T, F; //value, time, food/weight
        std::cin >> V >> T >> F;
        restaurants[i] = {V, T, F};
    }
    std::cout << solve(R, M, U);
    return 0;
}