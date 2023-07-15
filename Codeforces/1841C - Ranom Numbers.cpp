#include <bits/stdc++.h>

const int INF = 1e9;
int value [5] = {1, 10, 100, 1000, 10000}; //Map value
int dp [2][5][2]; //dp[current][biggest so far][changed yet]

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::string ranom;
        std::cin >> ranom;
        std::reverse(ranom.begin(), ranom.end()); //Reverse string
        int cur = 0;
        for (int j = 0; j < 5; j++){
            dp[!cur][j][0] = dp[!cur][j][1] = -INF;
        }
        dp[!cur][0][0] = 0; //Base case, no changes applied yet, we say the biggest value is 'A' because although there is no value after the last letter technically, all values will be positive with 'A' to the right of them, so 'A' is the most accurate letter to start as the base

        //Iterate through
        for (auto c: ranom){
            int x = c - 'A';
            //Set default value for turn
            for (int j = 0; j < 5; j++){
                dp[cur][j][0] = dp[cur][j][1] = -INF;
            }
            //For each max before change
            for (int j = 0; j < 5; j++){
                //If already changed or not
                for (int change = 0; change < 2; change++){
                    //What to change current letter to next
                    for (int next = 0; next < 5; next++){
                        int new_j = std::max(j, next); //Find new biggest value 
                        int changed = change + (x != next); //If x == next, you didn't really change anything
                        //You've only changed at max once
                        if (changed < 2){
                            //If this is bigger or equal to max
                            if (next >= j){
                                //Must take max, multiple changes can still have the same j value. i.e. j = 4, next = 1,2,3,4 all have the same new_j value
                                dp[cur][new_j][changed] = std::max(dp[cur][new_j][changed], dp[!cur][j][change] + value[next]);
                            }
                            //If less, than you subtract
                            else{
                                dp[cur][new_j][changed] = std::max(dp[cur][new_j][changed], dp[!cur][j][change] - value[next]);
                            }
                        }
                    }
                }
            }
            cur = !cur; //Swap turns
        }
        int ans = -INF; //Remember sum can be negative
        for (int j = 0; j < 5; j++){
            ans = std::max(ans, std::max(dp[!cur][j][0], dp[!cur][j][1]));
        }
        std::cout << ans << '\n';
    }
    return 0;
}