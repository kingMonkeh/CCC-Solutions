/*

2005 S3 - Quantum Operations

Difficulty: Medium

For this problem, there's no special algorithm, you quite litearly just implement the situation

Multiplying the matrices will require decent knowledge of array manipulation

As for checking the min/max values and the rows as well as the columns
It suffices to search linearly with 2 for loops since the final matrice will be 1024x1024 at most

*/

#include <iostream>
#include <vector>
#include <set>

int main(){
    
    int N;
    
    std::cin >> N;
    
    //Matrix 1 will represent the first/original matrix, Matrix 2 will the matrix we're multiplying by
    std::vector<std::vector<int>> matrix1;
    std::vector<std::vector<int>> matrix2;
    
    int matrix1_height, matrix1_width, matrix2_height, matrix2_width;
    
    //Get matrix 1
    //I will be creating the first matrix on its own. There's no gurantee that there's going to be at least 2 matrices
    
    std::cin >> matrix1_height >> matrix1_width;
    
    matrix1.resize(matrix1_height, std::vector<int> (matrix1_width)); //Resize to prevent having to repeatedly resize the vector with push back
    
    for (int i = 0; i < matrix1_height; i++){
        
        for (int j = 0; j < matrix1_width; j++){
            
            std::cin >> matrix1[i][j];
            
        }
        
    }

    //For the additional matrices if they exist
    
    //N - 1 since we've already done the first matrix
    for (int n = 0; n < N - 1; n++){
        
        //Get next matrix
        
        std::cin >> matrix2_height >> matrix2_width;
    
        matrix2.clear(); //Very important to clear the vector before using it again. Forgetting to do so will result in some really wonky errors like invalid pointer or munchunk
        matrix2.resize(matrix2_height, std::vector<int> (matrix2_width));
        
        //Obtain the next matrix values
        for (int i = 0; i < matrix2_height; i++){
            
            for (int j = 0; j < matrix2_width; j++){
                
                std::cin >> matrix2[i][j];
                
            }
            
        }
        
        //Multiply the matrices
    
        std::vector<std::vector<int>> matrix1_copy = matrix1; //I will be changing matrix1's values directly, therefore I need a copy of it before it was changed to perform multiplication
        
        matrix1.clear(); //REMEMBER TO CLEAR MEMORY BEFORE USING
        matrix1.resize(matrix1_height * matrix2_height, std::vector<int> (matrix1_width * matrix2_width));
        
        //To multiply them I will be using 4 for loops, the first 2 for loops correspond to the value of matrix1 whereas the other 2 for loops correspond to the values of the second matrix
        for (int i = 0; i < matrix1_height; i++){
            
            for (int j = 0; j < matrix1_width; j++){
                
                for (int y = 0; y < matrix2_height; y++){
                    
                    for (int x = 0; x < matrix2_width; x++){
                        
                        //I can't really prove to you this formula. But intuitively it makes sense. A value in matrix1 at i, j will be transformed to position i * matrix2_height + the current row number in matrix 2, j + matrix1 width + the current column number in matrix 2
                        matrix1[i * matrix2_height + y][j * matrix2_width + x] = matrix1_copy[i][j] * matrix2[y][x];
                        
                    }
                    
                }
                
            }
            
        }
        
        matrix1_height *= matrix2_height; //Remember to adjust the height and width values so that you can resize the vector correctly later
        matrix1_width *= matrix2_width;
        
    }

    //Finding the min/max element, row sum and column sum
    //Remember that set is always ordered, so naturally if we just insert everything into a set, the minimum will be the first element and the maximum will be the last element
    std::set<int> elements;
    std::set<int> rowSums;
    std::set<int> colSums;

    int rowSum = 0, colSum = 0;

    //Find row sums and elements in the final matrix
    for (int i = 0; i < matrix1_height; i++){

        for (int j = 0; j < matrix1_width; j++){

            elements.insert(matrix1[i][j]);
            rowSum += matrix1[i][j];

        }

        rowSums.insert(rowSum);
        rowSum = 0; //Clean up, prepare for the next row

    }

    //Find the column sums
    for (int j = 0; j < matrix1_width; j++){

        for (int i = 0; i < matrix1_height; i++){

            colSum += matrix1[i][j];

        }

        colSums.insert(colSum);
        colSum = 0; //Clean up, prepare for next column

    }

    //Output the answer
    std::cout << *elements.rbegin() << '\n' << *elements.begin() << '\n' << *rowSums.rbegin() << '\n' << *rowSums.begin() << '\n' << *colSums.rbegin() << '\n' << *colSums.begin();

    return 0;
    
}

