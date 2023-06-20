/*


ahahaha i hate dp
i had right idea of dp, but poor implementation
resulting in tle

dp[i][j] tells us min time to make the word fav given that we're at index i in scary and we've already placed the first j letters of favorite word

*/



#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

int DP [300][300];
int n, m;
std::string scary, fav;
std::vector<int> indexes [26];

int solve (int i, int j){

    //We done
    if (j == m){
        return 0;
    }
    if (DP[i][j] != -1){
        return DP[i][j];
    }

    int ret = 2e9 + 247;
    //efficient way of jumping, if we're at a current letter, we search all other occurences
    for (int& loc: indexes[scary[i] - 'a']){
        //Go left
        if (loc > 0 && scary[loc - 1] == fav[j]){
            // +1 since we go left, + abs(i - loc) to simulate if we jumped to index loc while starting from i
            ret = std::min(ret, solve(loc - 1, j + 1) + 1 + abs(i - loc));
        }
        //Go right
        if (loc < n - 1 && scary[loc + 1] == fav[j]){
            ret = std::min(ret, solve(loc + 1, j + 1) + 1 + abs(i - loc));
        }
    }

    return DP[i][j] = ret;
    
}

int main (){
    memset(DP, -1, sizeof(DP));
    std::cin >> n >> m >> scary >> fav;
    for (int i = 0; i < n; i++){
        indexes[scary[i] - 'a'].push_back(i); //maintain all occurences of each letter
    }
    int ans = 2e9 + 247; //Inf
    for (int i = 0; i < n; i++){
        //Initial place, no time taken
        if (scary[i] == fav[0]){
            ans = std::min(ans, solve(i, 1));
        }
    }
    if (ans == 2e9 + 247){
        std::cout << -1;
    }
    else{
        std::cout << ans;
    }
    return 0;
}