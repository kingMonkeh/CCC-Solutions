/*

Difficulty: Medium 

This is my second bitset DP problem, so not that bad this time around

basically let DP[i][j] tell us the total number of ways to make i pairs of men and women 
while having already used the columns within j

that was a bit confusing, let me rephrase that
j is an integer yes, but it is also a bitset,

we notice that once a man chooses a woman, no other man can take that woman
this is equivalent to saying no other man can pick 1 from this column anymore

let j be a bitset representing the N columns of woman
when a bit in j is 1, it means that a man has already taken a woman from that column

We will traverse top down
Our base case is when we've hit the bottom, we've created all the pairs
we just count which ones are valid and return that value

Otherwise we say DP[i][j] = sum(DP[i + 1][a] + DP[i][b] + DP[i][c] + DP[i][d]...)
here, {a, b, c, d} are all bitsets representing the various states that we can take on from row i, state j
depending on which women we choose to pair with the current man

*/

#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int N;
std::vector<std::vector<int>> a;
std::bitset<21> used;
int DP [21][2097152]; //2097152 since there are 2^21 possible states

int solve (int man = 0){

    int ret = 0;

    //Lookup
    if (DP[man][used.to_ulong()] != -1){
        return DP[man][used.to_ulong()];
    }
    
    //Base case, no more traversing, just count what is possible
    if (man == N - 1){
        for (int i = 0; i < N; i++){
            if (a[man][i] == 1 && !used[i]){
                ret++;
            }
        }
        return DP[man][used.to_ulong()] = ret;
    }

    //Toggle states on and off, summation
    for (int i = 0; i < N; i++){
        if (a[man][i] == 1 && !used[i]){
            used[i] = 1; //Toggle used
            ret = (ret % MOD + solve(man + 1) % MOD) % MOD;
            used[i] = 0; //Toggle valid again
        }
    }

    return DP[man][used.to_ulong()] = ret % MOD;
    
}

int main(){

    memset(DP, -1, sizeof(DP));
    std::cin >> N;
    a.resize(N, std::vector<int> (N));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cin >> a[i][j];
        }
    }

    std::cout << solve() << '\n';
    
    return 0;
    
}