/*

DP[i][j] = # of subsequences that can be constructed using the remaining letters
after letter i in string S, with j letters already found in "love";

*/

#include <iostream>
#include <string>

std::string S, love = "love";
int len1, len2 = 4;

long long DP[10001][5];

long long solve(int i, int j){

    if (DP[i][j] != -1){
        return DP[i][j];
    }
    
    long long total = 0;
    
    if (j == 4){
        return 1;
    }

    for (int k = i; k < len1; k++){
        if (S[k] == love[j]){
            total += solve(k + 1, j + 1);
        }
    }

    DP[i][j] = total;
    return total;
    
}

int main(){
    for (int i = 0; i <= 10000; i++){
        for (int j = 0; j <= 4; j++){
            DP[i][j] = -1;
        }
    }
    std::cin >> S;
    len1 = S.length();
    std::cout << solve(0, 0);
    return 0;
}