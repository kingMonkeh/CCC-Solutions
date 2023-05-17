/*

Difficulty: Medium/Hard
Had to peek problem type for this one

Its another DP problem.
Question isn't very clear about this but
basically, you have to go left to right on the strings
Meaning you cant say like geese game 3, hawks game 2,
And then say hawks game 3, geese game 2, since you were just at game 3 of geese earlier

Idea here is very similar to longest common subsequence problem in DP
let DP[i][j] tell us the maximum total score we can get using the first i games from geese, and first j games from hawks

If one of the team won and the other lost, and the winning team has more points then
DP[i][j] = DP[i - 1][j - 1] + geese[i] + hawks[j]
Note however, sometimes its not always optimal to take a certain game as we may want to save it for later
For that reason, after calculating this, we take the max between it and the top node and left node

If its not a rivalry game
Then we just take max between top node and left node

*/

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

long long DP[1001][1001];

int main (){
    long long N;
    std::cin >> N;
    memset(DP, 0, sizeof(DP));
    std::string geese, hawks;
    long long g [N], h [N];
    std::cin >> geese;
    for (int i = 0; i < N; i++){
        std::cin >> g[i];
    }
    std::cin >> hawks;
    for (int i = 0; i < N; i++){
        std::cin >> h[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (geese[i] == hawks[j]){
                DP[i + 1][j + 1] = std::max(DP[i][j + 1], DP[i + 1][j]);
            }
            else if (geese[i] == 'W' && hawks[j] == 'L'){
                if (g[i] > h[j]){
                    DP[i + 1][j + 1] = std::max(DP[i][j] + g[i] + h[j], std::max(DP[i][j + 1], DP[i + 1][j]));
                }
                else{
                    DP[i + 1][j + 1] = std::max(DP[i][j + 1], DP[i + 1][j]);;
                }
            }
            else{
                if (h[j] > g[i]){
                    DP[i + 1][j + 1] = std::max(DP[i][j] + g[i] + h[j], std::max(DP[i][j + 1], DP[i + 1][j]));
                }
                else{
                    DP[i + 1][j + 1] = std::max(DP[i][j + 1], DP[i + 1][j]);
                }
            }
        }
    }
    /*
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= N; j++){
            std::cout << DP[i][j] << ' ';
        }
        std::cout << '\n';
    }
    */
    std::cout << DP[N][N];
    return 0;
}