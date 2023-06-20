/*

Difficulty: Hard
ahahaha
my first bitmask dp problem had to be this one
i hate dp... maybe one day I'll like it

*/

#include <iostream>
#include <bitset>
#include <cstring>

const int max_masks = 3000;
const int MOD = 1000000007;

int R, C;
int DP [2][max_masks]; //DP[current row][mask]
short maskToNum [1 << 22]; //Important to use short, there's not that many valid masks and short helps reduce memory usage
int numToMasks [max_masks];
std::bitset<22> currentLine, nextLine;

//mask is decimal representation of bitset
//uniqueMask denotes the ID of this unique mask
int uniqueMask = 0;
int linkMaskToNum (int mask){
    if (maskToNum[mask] == -1){
        maskToNum[mask] = uniqueMask;
        numToMasks[uniqueMask++] = mask;
    }
    return maskToNum[mask]; //return unique id of this mask
}

//Idea is that when calling this, we have an origin mask
//We attempt to generate all masks that can be made from this origin mask
//Each generated mask can be reached in the amount of ways the origin mask could have been created (initialWays)
void solve (int row, int col, int initialWays){
    //If we've reached the end of the thing
    if (col == C){
        DP[!row][linkMaskToNum(nextLine.to_ulong())] = (DP[!row][linkMaskToNum(nextLine.to_ulong())] + initialWays) % MOD;
        return;
    }
    //Choose to not add a star
    solve (row, col + 1, initialWays);
    //Place star only if there's room
    if (col != 0 && col != C - 1 && currentLine[col] == 0 && nextLine[col - 1] == 0 && nextLine[col] == 0 && nextLine[col + 1] == 0){
        nextLine[col - 1] = 1;
        nextLine[col] = 1;
        nextLine[col + 1] = 1;
        //Recurse deeper, left -> right
        solve (row, col + 1, initialWays);
        //Undo changes
        nextLine[col - 1] = 0;
        nextLine[col] = 0;
        nextLine[col + 1] = 0;
    }
    
}

int main(){
    std::cin >> R >> C;
    memset(maskToNum, -1, sizeof(maskToNum));
    //mask 0 is 000000000000..., aka no stars have been put down yet
    DP[1][linkMaskToNum(0)] = 1; //only one way to have an empty board
    //For each row
    for (int i = 1; i < R; i++){
        //Basically they take turns being 0 and 1
        int cur = i % 2, nxt = !cur;
        //Clear next line DP values for update
        memset(DP[nxt], 0, sizeof(DP[nxt]));
        //For every possible masks that can be formed at this row
        for (int j = 0; j < max_masks; j++){
            if (DP[cur][j]){
                currentLine = std::bitset<22>(numToMasks[j]); //Obtain current line
                //solve (current row, startcol = 0, # of ways to reach prev mask j)
                solve(cur, 0, DP[cur][j]);
            }
        }
    }
    //Add up all the stoofs
    int ans = 0;
    for (int j = 0; j < max_masks; j++){
        ans = (ans + DP[R % 2][j]) % MOD;
    }
    //Subtract 1, since one of the canvases created during our DP
    //is an empty canvas, recall ButaneBot must paint at least one star for a painting to be valid
    std::cout << --ans << '\n';
    return 0;
}