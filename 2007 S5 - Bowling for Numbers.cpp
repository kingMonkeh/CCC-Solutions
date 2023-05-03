/*

2007 S5 - Bowling for Numbers

Difficulty: Medium/Hard

This is a DP problem. Basically we will create a 2-D DP array
where DP[i][j] tells us the max amount we can obtain if we use i bowling balls
And we're limited to the pins from index j to the end of the line

To speed things up, we notice that we should precompute the total for each chunk
Since this value is reused a lot, let blocks[i] tell us the total for the block starting at index i with width w

We will now work backwards, starting with 1 bowling ball and working our way up
We will iterate from the right to the left with the following logic

dp[i][j] = max(dp[i - 1][j + w] + blocks[j], dp[i][j + 1])
In simple terms, this is the logic

If we have i balls and we're limited from index j to the end
We can either choose to throw the ball at index j and knock over its block,
We then add this to the previous state in which given 1 less ball and limited to the pins from j + w to the end

However, this may not always be optimal, which is why we compare it to dp[i][j + 1]
Which represents if we don't throw the ball and just use the optimal amount that can be gained from using the same amount of balls
but from index j + 1 to end

Note that theres an edge case, that is when we're at the end of the line (index j >= #total pins - width of 1 block)
Here there's no more blocks we can access, therefore we just set it as the value of its block

*/

#include <iostream>
#include <algorithm>
#include <string.h>

int n, k, w;
int dp[501][30000];
int blocks [30000];

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

        //Precompute chunks
        blocks[0] = 0;
        for (int i = 0; i < w; i++){
            blocks[0] += pins[i];
        }

        //Use rolling window, aka remove leftmost add right most
        for (int i = 1; i < n; i++){
            blocks[i] = blocks[i - 1] - pins[i - 1];
            if (i + w - 1 < n){
                blocks[i] += pins[i + w - 1];
            }
        }

        //Memset dp
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= k; i++){
            for (int j = n - 1; j >= 0; j--){
                //Edge case, we're at the end of the line
                if (j >= n - w){
                    dp[i][j] = blocks[j];
                }
                //Otherwise, the usual logic
                else{
                    dp[i][j] = std::max(dp[i - 1][j + w] + blocks[j], dp[i][j + 1]);
                }
            }
        }

        //Answer is found at dp[k][0] since we've used all k balls and we're viewing the max from index 0 to the end of the line
        std::cout << dp[k][0] << '\n';
        
    }
    
    return 0;
    
}