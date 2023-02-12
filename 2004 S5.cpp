/*

2004 S5 - Super Plumber

Topics: 2-D Arrays, Dynamic Programming

Difficulty: Medium

This problem is on the easier side for an S5, but nonetheless still requires good understanding of dynamic programming to solve.

General idea:
To solve this problem, we must try every single path. But we must do so in an efficient manner.
Instead of retrying every path 1 by 1, we can actually memoize the information of one column and use it to solve the next.
The reason this memoize works is because from every square, you can go to the right, and from there, you can go all the way up or all the way down.

Initialize a 2-D array that stores the max money you can get while on the way to position[row][column]
Set up the start point, maxMoney[m - 1][0], to the value there.

Start with column 1 (furthest to the left). From this column, you can only go up without going right. Update maxMoney accordingly.
Afterwards, iterate through the remaining columns.

For each column, go through the rows, for each row, determine if you could've gotten here by going right from the previous column.
If you can, try going all the way up from this square, and then try going all the way down until an obstacle is met or you go out of bounds.
Update maxMoney accordingly only when the money from that path is greater than what's already there.

Output maxMoney[m - 1][n - 1] which is where our answer will be found.

*/

#include <iostream>
#include <vector>
#include <string>

int main(){

    std::vector<std::vector<int>> grid; //Actual grid
    std::vector<std::vector<int>> money; //money[i][j] tells us max money that can be obtained on the way to grid[i][j]

    //For each test case
    while (true){

        int m, n;
        std::cin >> m >> n;

        //End of input
        if (m == 0 && n == 0){
            break;
        }

        //Resize accordingly
        grid.resize(m, std::vector<int> (n));
        money.resize(m, std::vector<int> (n, -1)); //Fill with -1 to mark a position as unreachable

        //I will be converting the characters to numbers, -1 indicates obstacle, 0 indicates open space and (1, 2, 3...) will be represented by their actual number
        for (int i = 0; i < m; i++){
            std::string row;
            std::cin >> row;

            for (int j = 0; j < n; j++){

                //Open
                if (row[j] == '.'){
                    grid[i][j] = 0;
                }

                //Obstacle
                else if (row[j] == '*'){
                    grid[i][j] = -1;
                }

                //Actual number
                else{
                    grid[i][j] = row[j] - '0'; //Minus by ASCII code
                }

            }
        }

        //Start position
        money[m - 1][0] = grid[m - 1][0];

        //First column, go up only
        for (int row = m - 2; row >= 0; row--){

            //If no obstacle
            if (grid[row][0] != -1){
                money[row][0] = money[row + 1][0] + grid[row][0]; //Money at current spot is equal to money at previous spot + this spot
            }

            else{
                break;
            }

        }

        //For the remaining columns
        for (int col = 1; col < n; col++){

            //Going down
            for (int row = 0; row < m; row++){

                //If it was possible to reach this square by going right from the previous column
                if (money[row][col - 1] != -1){

                    int previousMoney = money[row][col - 1]; //Previous money indicates the money that is earned on this path with this starting square, it's initial value is the amount of the square on the left because you would have just came from that square
                    
                    //Starting from this square, for the remaining rows below it
                    for (int rowFromRow = row; rowFromRow < m; rowFromRow++){

                        //If no obstacle
                        if (grid[rowFromRow][col] != -1){

                            previousMoney += grid[rowFromRow][col]; //Update money
                            money[rowFromRow][col] = std::max(money[rowFromRow][col], previousMoney); //Update only if the money earned on this path is greater than that of other paths

                        }

                        else{

                            break;

                        }

                    }

                }

            }

            //Going up

            for (int row = m - 1; row >= 0; row--){
                
                if (money[row][col - 1] != -1){

                    int previousMoney = money[row][col - 1];
                    
                    //From this square, and all the squares above it
                    for (int rowFromRow = row; rowFromRow >= 0; rowFromRow--){

                        //No obstacle
                        if (grid[rowFromRow][col] != -1){

                            previousMoney += grid[rowFromRow][col];
                            money[rowFromRow][col] = std::max(money[rowFromRow][col], previousMoney); //Remember, take max only

                        }

                        else{
                            break;
                        }

                    }

                }

            }

        }

        std::cout << money[m - 1][n - 1] << '\n'; //Output answer

        grid.clear(); money.clear(); //REMEMBER TO CLEAR VECTOR, YOU WILL GET UGLY ERRORS IF YOU DON'T

    }

    return 0;

}