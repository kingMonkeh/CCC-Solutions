/*

CCCHK 2015 S3 - Symmetric Cross

Difficulty: Easy

Idea is quite simple, since the matrix is quite small, it suffices to try creating a cross at every point.

To determine the maximum potential size of the cross, it's the minimum of its maximum lengths, north south east west since it should be able to go this length in all those directions.

To determine the actual length of the symmetric cross at a center, we will iterate 1 in each direction.
In a symmetric cross, all 4 of these values must be the same for the cross to remain the same after rotating by 90.
Therefore, we just need to check if the values are the same, if they're not, we store the max length of the symmetric cross with that center.
Afterwards, output the largest cross. Recall that there will only be one cross with the max size as stated in the question.

*/

#include <iostream>
#include <vector>
#include <map>

int main(){

    int R, C;
    std::cin >> R >> C;

    //Take in matrix
    std::vector<std::vector<int>> matrix (R, std::vector<int> (C));

    for (int i = 0; i < R; i++){

        for (int j = 0; j < C; j++){

            std::cin >> matrix[i][j];

        }

    }

    std::map<int, std::pair<int, int>> cross_sizes; //Map cross sizes, cross_sizes[i] = the center with symmetric cross length i

    int centerx, centery; //Store x and y values of center, this is unnecessary and you could've used i and j, but for readability I will be using these
    for (int i = 0; i < R; i++){

        centery = i;

        for (int j = 0; j < C; j++){

            centerx = j;

            //Get max length in each direction before going out of the matrix
            int topHeight = centery, bottomHeight = R - centery - 1, leftLength = centerx, rightLength = C - centerx - 1;
            //Obtain the maximum length of the symmetric cross by taking the min of these values
            int max = std::min(std::min(topHeight, bottomHeight), std::min(leftLength, rightLength));

            int possible = 0; //Symmetric cross length

            //For as far as we can go while still possibly being symmetrical
            for (int k = 1; k <= max; k++){

                //Check if left is equal to top
                if (matrix[centery][centerx - k] != matrix[centery - k][centerx]){
                    break;
                }

                //If top is equal to right
                if (matrix[centery - k][centerx] != matrix[centery][centerx + k]){
                    break;
                }

                //If right is equal to bottom
                if (matrix[centery][centerx + k] != matrix[centery + k][centerx]){
                    break;
                }

                //If bottom is equal to left
                if (matrix[centery + k][centerx] != matrix[centery][centerx - k]){
                    break;
                }

                //Note that you could've combined these if statements into 1

                possible++; //If they're all equal, add to symmetric cross length

            }

            //Add values to map
            std::pair<int, int> coords = std::make_pair(centery + 1, centerx + 1);
            cross_sizes[possible] = coords;
            possible = 0; //Reset length for next center

        }

    }

    //Maps are ordered by key, therefore last key in map will be largest possible symmetric cross length which has coordinates as value
    std::cout << cross_sizes.rbegin() -> first << ' ' << cross_sizes.rbegin() -> second.first << ' ' << cross_sizes.rbegin() -> second.second;

    return 0;

}