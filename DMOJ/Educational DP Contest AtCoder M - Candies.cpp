#include <bits/stdc++.h>

//Modular arithmetic stuff, i dont really know how it works, i just do it
const int MOD = 1e9 + 7;

int add(int i, int j) {
	if ((i += j) >= MOD)
		i -= MOD;
	return i;
}

int sub(int i, int j) {
	if ((i -= j) < 0)
		i += MOD;
	return i;
}

int N, K;
//Let DP[i][j] tell us the amount of ways to distribute candy to the first i children using j candy
//Transition kinda monkey, DP[i][j] = sum(DP[i - 1][j] + DP[i - 1][j - 1] + DP[i - 1][j - 2] ... + DP[i - 1][j - a[i]])
//We notice that this would required O(N * K^2) time to calculate manually, so we reduce this to O(N * K) using prefix sum array
long long DP [100][100001];
//Maintain 2 prefix sums, one for the previous DP[i - 1] values, and create one for DP[i]
long long prefix [2][100002];
int a [100];

int main(){

    memset(DP, 0, sizeof(DP));
    memset(prefix, 0, sizeof(prefix));
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) std::cin >> a[i];

    int turn = 0; //Keep track of which prefix array we are reading from, !turn will be the one we're current creating
    prefix[turn][0] = 0;
    for (int i = 0; i <= K; i++){
        DP[0][i] = i <= a[0] ? 1 : 0; //Base case, 1 person, i candies, answer is 1 since no candies can be leftover
        prefix[turn][i + 1] = prefix[turn][i] + DP[0][i]; //Create initial prefix sum array
    }

    for (int i = 1; i < N; i++){
        prefix[!turn][0] = 0;
        for (int j = 0; j <= K; j++){
            //Get sum
            DP[i][j] = sub(prefix[turn][j + 1], prefix[turn][std::max(0, j - a[i])]);
            prefix[!turn][j + 1] = add(prefix[!turn][j], DP[i][j]); //Update prefix
        }
        turn = !turn; //Swap prefix sum arrays
    }

    std::cout << DP[N - 1][K] % MOD << '\n';
    
    return 0;
    
}