/*

https://www.youtube.com/watch?v=JmQugCTIVgA
very helpful video to watch, to help understand

basically let dp[i] tell us max balls we can remove from the subarray starting at index 0 --> i

lets say a[i] has the color red for now
we have two choices when iterating through
either we dont remove the segment containing the red
dp[i] = dp[i - 1]

or we do indeed remove a segment containing red
lets assume there exists an index j such that a[j] = a[i] and j < i
when we remove the segment from j --> i
we remove j - i + 1 balls, in addition all the balls we had removed before the segment [j, i] are also apart of our total

therefore
dp[i] = j - i + 1 + dp[j - 1]
for all possible values of j

this begs the question however, what is the optimal value of j we should be using?
lets start out by rearranging the formula

dp[i] = i + 1 + (dp[j - 1] - j)
i have not added or removed anything, just rearranged
since i + 1 is constant, we notice that we must maximize the value of (dp[j - 1] - j)

therefore, lets create a map which takes the color as a key
we'll say map[color] = dp[j - 1] - j, where a[j] = color.

updating map is quite simple
map[color] = max(map[color], dp[j - 1] - j)

with all this, we can now write our solution
base case dp[0] = 0, you cant remove anything with just 1 element in the array

*/


#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        int DP [n];
        std::map<int, int> optimalSeg; //our map
        for (int i = 0; i < n; i++){
            int color;
            std::cin >> color;
            if (i == 0) DP[i] = 0; //base case
            else{
                DP[i] = DP[i - 1]; //Don't take out segment
                //Take out optimal segment if it exists
                if (optimalSeg.count(color)){
                    DP[i] = std::max(DP[i], i + 1 + optimalSeg[color]);
                }
            }
            //creating the segment for the first time
            if (optimalSeg.count(color) == 0){
                optimalSeg[color] = i == 0 ? 0 : DP[i - 1] - i; //watch out for out of bounds index
            }
            else{
                optimalSeg[color] = std::max(optimalSeg[color], DP[i - 1] - i);
            }
        }

        std::cout << DP[n - 1] << '\n';
        
    }
    
    return 0;
    
}