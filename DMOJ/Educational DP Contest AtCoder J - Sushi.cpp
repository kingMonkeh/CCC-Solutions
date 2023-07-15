#include <bits/stdc++.h>

/*

Expected Value DP

Observation 1:
It does not matter the order of the plates

2 1 1 2
and 2 2 1 1
have the exact same answer, since all dishes have an equal chance of being chosen

Therefore, what's really important to keep track of is the # of plates with 1 sushi (a), # of plates with 2 sushis (b), 
# of plates with 3 sushis (c) as well as # of plates with 0 sushi (d)
This would lead us to DP[a][b][c][d], which is O(N^4), which is too big

We notice we dont have to keep track of one of the # of plates
since we can solve for it using N - a - b - c = # of plates with 0 sushis
thus reducing it to O(N^3) which is possible

Let DP[a][b][c] tell us the # of expected moves required to eat all sushi given a plates with 1 sushi, b plates with 2 sushi and c plates with 3 sushi

Base case: DP[0][0][0] = 0, you've eaten all the sushis, no more moves need to be made

Else,
Let t be the # of plates that have at least 1 sushi on them
DP[a][b][c] = N/t + a/t * DP[a - 1][b][c] + b/t * DP[a + 1][b - 1][c] + c/t * DP[a][b + 1][c - 1]

Explanation:
First off, for our change in states, if we eat a sushi from a plate of 2, then that plate becomes a plate of 1, hence b - 1, a + 1

The expected number of moves before we make before picking a plate that has at least 1 sushi on it, aka # of moves where we pick plate with 0 sushi
is the geometric series of (1 - (t/N))^n, 0 <= n <= inf
which can be simplified to N/t

Afterward, we just calculate the expected value between the plates that do have sushis on them
Using their probabilities as weights and # of expected moves to calculate the value
Watch this video on Khan Academy if you're a bit confused
https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:prob-comb/x9e81a4f98389efdf:expected-value/v/expected-value-of-a-discrete-random-variable

Other useful sources if you're stuck
https://www.youtube.com/watch?v=1HiJ332iZQU (well explained)
https://neppramod.wordpress.com/2019/12/05/j-sushi-educational-dp/ (nice math bit)

*/

int N;
int count [4] = {0, 0, 0, 0}; //count[i] tells us how many dishes there are with i sushis on them
double DP [301][301][301]; //dp[a][b][c] tells us number of expected moves required to eat all sushi given a plates with 1 sushi, b plates with 2 sushis and c plates with 3 sushis

double solve (int a, int b, int c){

    //Base case, no sushi, therefore 0 moves required
    if (a == 0 && b == 0 && c == 0) return 0;

    if (DP[a][b][c] != -1) return DP[a][b][c];

    double ret = N;
    if (a) ret += a * solve(a - 1, b, c);
    if (b) ret += b * solve(a + 1, b - 1, c);
    if (c) ret += c * solve(a, b + 1, c - 1);

    return DP[a][b][c] = ret / (a + b + c); //Here I factored out 1/t from the entire expression
    
}

int main (){

    std::cin >> N;
    for (int i = 0; i < N; i++){
        int dish; std::cin >> dish;
        count[dish]++;
    }

    for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) for (int k = 0; k <= N; k++) DP[i][j][k] = -1;

    double ans = solve(count[1], count[2], count[3]);

    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
    
    return 0;
    
}