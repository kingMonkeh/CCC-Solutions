/*

2017 S5 - RMT

Difficulty: Very Hard

Basically, we're going to break the stations up into blocks of stations
Each station block can be approximately sqrt(N) length

In each block we want to keep track of the following

The left most and right most station of each line that passes through the block
The total number of people in a block

To query, we iterate through the blocks, if an entire block is covered by the query range
We just add the total people in that block
Otherwise, we'll iterate individually through the people in a single block
Note that at max, there will be 2 blocks that are partially covered by the query range

To run a line, we will just have an array called shift[i]
Which tells us how many times line i has been run
If we want to know how many people are at station j after 3 shifts to the line
then it would be line[i][j - 3] or line[i][j - shift[i]]

But, the harder part now is updating the total people in each block after running a line
Notice that if we run a line, the right most station in a singular block will lose its people
Therefore we subtract that amount
Also notice that amount of people at the station before the leftmost station of a block will be added

*/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2147483647
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>

const int blockLength = 388;

//Block structure
struct block{
    vi left = vi (150001, INF); //left[i] tells us the index of the left most station of line[i] in the current block
    vi right = vi (150001, -1); //right[i] tells us the index of the right most station of line[i] in the current block
    int totalPeople = 0; //total people in this block
};

//Split entire train line, into smaller blocks
std::vector<block> blocks (blockLength + 1);

int main(){

    int N, M, Q;
    std::cin >> N >> M >> Q;

    vi trainToLine (150001); //trainToLine[i] tells us what line, train i is apart of
    for (int i = 1; i <= N; i++){
       std::cin >> trainToLine[i]; 
    }

    vvi lines (150001); //2-D array, lines[i][j] tells us the amount of people originally at station j in line i
    vi posInLine (150001); //posInLine[i] tells us the position of station i in their respective line
    for (int i = 1; i <= N; i++){

        int ppl; std::cin >> ppl;

        //Add people to their respective block
        blocks[i / blockLength].totalPeople += ppl;

        lines[trainToLine[i]].push_back(ppl); //Push people to line

        //Update index of left most station of their line 
        blocks[i / blockLength].left[trainToLine[i]] = std::min(blocks[i / blockLength].left[trainToLine[i]], (int)lines[trainToLine[i]].size() - 1);
        
        //Update rightmost station of the line
        blocks[i / blockLength].right[trainToLine[i]] = (int)lines[trainToLine[i]].size() - 1;

        posInLine[i] = (int) lines[trainToLine[i]].size() - 1; //Set pos in line
        
    }

    vi shift (150001, 0);
    
    //Handle Queries
    while (Q--){

        int option;
        std::cin >> option;

        //Survey
        if (option == 1){
            int left, right;
            std::cin >> left >> right;
            int survey = 0;
            for (int i = left; i <= right; ){

                //Entire block is within survey range
                if (i % blockLength == 0 && i + blockLength - 1 <= right){
                    survey += blocks[i / blockLength].totalPeople;
                    i += blockLength;
                }

                //Block is partially in survey range
                else{
                    //survey += lines[current stations line][current stations pos in their own line - times the line has been run], note that I use % just to deal with negative indices
                    survey += lines[trainToLine[i]][ (posInLine[i] - shift[trainToLine[i]] + (int)lines[trainToLine[i]].size()) % (int)lines[trainToLine[i]].size()];
                    i++;
                }
                
            }

            std::cout << survey << '\n';
            
        }

        //Run line
        else{
            int line;
            std::cin >> line;

            int lineSize = lines[line].size();
            
            shift[line]++;
            shift[line] %= lineSize;

            for (int i = 0; i <= blockLength; i++){

                //If this line has no stations in this block, skip
                if (blocks[i].left[line] == INF){
                    continue;
                }

                //Subtract rightmost station of line
                blocks[i].totalPeople -= lines[line][blocks[i].right[line]];

                //Update what trains are leftmost and rightmost of the current line in each block
                blocks[i].left[line]--; blocks[i].left[line] = (blocks[i].left[line] + lineSize) % lineSize;
                blocks[i].right[line]--; blocks[i].right[line] = (blocks[i].right[line] + lineSize) % lineSize;

                //Add the new station that has entered the block
                blocks[i].totalPeople += lines[line][blocks[i].left[line]];
                
            }
            
        }
        
    }

    return 0;
    
}