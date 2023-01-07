/*

2018 J4/S2 - Sunflowers

Difficulty: Easy/Medium
Topics: Ad Hoc, 2-D Arrays

The only difficult part of this question is rotating the grid 90 degrees.

General algorithm:
1. Check if grid is valid
2. If not, rotate the grid
3. Repeat steps 1 to 2 until valid

*/

#include <iostream>
#include <vector>

int N; //Global declaration so I can access it in my functions

//Check if grid is correct, least to greatest from left to right and top to bottom
bool correct (std::vector<std::vector<int>> data){

    //Left to right check
    for (int i = 0; i < N; i++){

        for (int j = 1; j < N; j++){

            if (data[i][j] < data[i][j - 1]){
                return false;
            }

        }

    }

    //Top to bottom check
    for (int j = 0; j < N; j++){

        for (int i = 1; i < N; i++){

            if (data[i][j] < data[i - 1][j]){
                return false;
            }

        }

    }

    return true;

}

//Rotate grid
std::vector<std::vector<int>> rotate (std::vector<std::vector<int>> data){

    std::vector<std::vector<int>> copy = data; //Make a copy, so that changes are seperate

    int jj = 0; //Represent column index that I'm taking from the original grid

    for (int i = 0; i < N; i++){

        int ii = data.size() - 1; //Reoresents the row index that I'm taking from the original grid

        for (int j = 0; j < N; j++){

            copy[i][j] = data[ii][jj];
            ii--;

        }

        jj++;

    }

    return copy;

}

int main(){

    
    std::cin >> N;

    std::vector<std::vector<int>> data (N, std::vector<int> (N));

    //Collect data
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cin >> data[i][j];
        }
    }

    //Rotate until correct
    while (!correct(data)){

        data = rotate(data);

    }

    //Output answer
    for (int i = 0; i < N; i++){

        for (int j = 0; j < N; j++){
            std::cout << data[i][j] << ' ';
        }

        std::cout << std::endl;
    }


    return 0;

}