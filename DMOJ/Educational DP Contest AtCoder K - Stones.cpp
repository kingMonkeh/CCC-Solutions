#include <bits/stdc++.h>

/*

Very similar problem to CCC problem "Nukit", using DP approach

Idea is to view the game as a choice tree
When the game has reached a point where no move can be made, we view this as a losing position, return false.
If some amount of stones was removed from a certain state of the game, causing the losing position above, we consider this to be a winning position
Since there exists a some value in A, that we can remove from K, that will lead us to a winning position

However, we now ask the question, what happens if we make a move that causes a winning position?
By logic, if we make a move that creates a winning position, then this move must be a losing position, as we've just given the opponent a chance to play a winning move

Therefore we now create a cycle of winning and losing position
A win causes a loss which causes a win...

Therefore we let DP[i] tell us whether the position in which we possess i stones is a winning or losing position
We will view everything in terms of Taro's turn for the sake of simplicity

*/

int N, K;
int smallest = INT_MAX;
std::vector<int> A;
int DP [100001];

int solve (int stones){

    //You can't pull any stone
    if (stones < smallest) return 0;

    if (DP[stones] != -1) return DP[stones];

    int& ret = DP[stones] = 0;
    for (int i = 0; i < N; i++){
        //If you can take out A[i] stones
        if (A[i] <= stones)
            ret = ret | !solve(stones - A[i]); //We say !solve(), since we return false for losing, therefore this position must be the opposite
    }

    return ret;
    
}

int main(){

    memset(DP, -1, sizeof(DP));
    std::cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++){
        std::cin >> A[i];
        smallest = std::min(smallest, A[i]);
    }

    solve(K);

    //Since Taro goes first, then if DP[K] is a winning position, then Taro can win the game
    if (DP[K] == 1) std::cout << "First\n";
    else std::cout << "Second\n";
    
    return 0;

}