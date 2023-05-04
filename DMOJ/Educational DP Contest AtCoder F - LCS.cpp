/*

Very cool DP problem, note that i suck at DP
Basically like DP[i][j], tells us the longest subsequence we can make using the first i letters from string s, and the first j letters in string t

Logic:
If s[i] == t[j]{
   DP[i][j] = DP[i - 1][j - 1]
   //Aka the two strings before you added this new matching letter  
}
else{
    //current = max(if we used 1 less letter in string s, if we used 1 less letter in string t)
    //Idea is that we're not gaining any more length, but we still have to add the letter, therefore we take the max between the two
    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1])
}

Note that this only generates the length
To actually get the subsequence itself,
We have to trace this path

Notice that when s[i] == t[j]
We take from our top left neighbour
Therefore, we keep another array which points to the neighbour that we took from
If the previous neighbour was diagonal, that means we used this letter, add it to our string

*/

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

int DP[3001][3001];
int prev[3001][3001];

int main(){
    std::string s, t;
    std::cin >> s >> t;
    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < t.length(); j++){
            if (s[i] == t[j]){
                DP[i + 1][j + 1] = DP[i][j] + 1;
                prev[i + 1][j + 1] = 3001 * i + j;
            }
            else{
                DP[i + 1][j + 1] = std::max(DP[i][j + 1], DP[i + 1][j]);
                if (DP[i + 1][j] >= DP[i][j + 1]){
                    prev[i + 1][j + 1] = 3001 * (i + 1) + j;
                }
                else{
                    prev[i + 1][j + 1] = 3001 * i + j + 1;
                }
            }
        }
    }
    std::string LCS = "";
    int currentRow = s.length(), currentCol = t.length();
    while (true){
        int previous = prev[currentRow][currentCol];
        int prevRow = previous / 3001;
        int prevCol = previous % 3001;
        if (prevRow == currentRow - 1 && prevCol == currentCol - 1){
            LCS = s[currentRow - 1] + LCS; 
        }
        currentRow = prevRow;
        currentCol = prevCol;
        if (currentCol == 0){
            break;
        }
    }
    //std::cout << DP[s.length()][t.length()];
    std::cout << LCS << '\n';
}