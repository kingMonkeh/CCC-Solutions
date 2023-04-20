/*

2009 S5 - Wireless
Difficulty: Medium/Hard

Idea is pretty simple, for every circle
Just iterate over every integer point contained within that circle and increment it by the bitrate
The only problem with this is that its pretty slow
To speed this up, notice that when we're incrementing
We're basically just performing range update queries on each row of the circle
Because of this, we can just use a difference array to keep track of all the updates and then apply them all at the end

*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>

int main(){
    
    int rows, cols, circles;
    std::cin >> rows >> cols >> circles;

    //grid[i][j] initially serves as a difference array that only keeps track of the updates
    //However as we apply the changes, grid[i][j] will tell us the bitrate that coffee shop at (j, i) experiences
    int grid [rows][1 + cols + 2];
    memset(grid, 0, sizeof(grid));

    //For each circle
    for (int i = 0; i < circles; i++){
        int row, col, r, b;
        //Notice that they input col first and then row
        std::cin >> col >> row >> r >> b;
        col--; row = rows - row; //Change it so that we have 0 indexing, I like to view the grid as 2-D array
        //For every row, aka top down
        for (int i = std::max(0, row - r); i <= std::min(rows - 1, row + r); i++){
            int actualRow = abs(row - i); //The current row, relative to the center of the circle which is viewed as row 0
            int dist = floor(sqrt(r * r - actualRow * actualRow)); //By pythagorean theorem, the x coord of the furthest point on this row is r^2 - actualRow^2
            int left = std::max(0, col - dist); //Get leftmost point of row
            int right = std::min(cols, col + dist); //Get rightmost point of row
            //Add to difference array
            grid[i][left + 1] += b; 
            grid[i][right + 2] -= b; 
        }
    }

    //Time to apply the updates and check for max as well as shops
    int max = 0, shops = 0;
    //For each row
    for (int i = 0; i < rows; i++){
        //Iterate through difference array
        for (int j = 1; j <= cols; j++){
            //Apply update
            grid[i][j] += grid[i][j - 1];
            //If the bitrate experienced is more than max, update max, reset shops
            if (grid[i][j] > max){
                max = grid[i][j];
                shops = 1;
            }   
            //Otherwise, if its equal to max, then add a shop
            else if (grid[i][j] == max){
                shops++;
            }
        }
    }

    //Output answer
    std::cout << max << '\n' << shops;
    return 0;
    
}