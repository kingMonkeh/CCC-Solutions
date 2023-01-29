/*

2004 S3 - Spreadsheet

Difficulty: Medium

This question isn't too difficult, just very time consuming to implement.

Notice that the spreadsheet is only 10 x 9 therefore it suffices to brute force fill in the spreadsheet repeatedly.

1. Create two spreadsheets, one that stores the actual values and the other that stores the instructions
2. Iterate over the integer spreadsheet, if a value is undefined, attempt to solve for it. If you can't skip over it temporarily.
3. Keep repeating step 2 until no change is made after a full traversal. This means you've solved it to the best of your ability. Output the spreadsheet.

*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <map>

#define UNDEFINED -999999999 //Placeholder value indicating this cell is undefined
#define SOLVED "." //In the instructions spreadsheet, filler value

int main(){

    std::vector<std::vector<int>> actual_spreadsheet (10, std::vector<int> (9, UNDEFINED)); //Store actual integer values to perform operations
    std::vector<std::vector<std::string>> theoretical_spreadsheet (10, std::vector<std::string> (9, SOLVED)); //Store the string instructions

    //I will be converting the instructions into something much easier to traverse, I will be ignoring addition signs thus creating a string that consists of pairs of integers.
    //Eg. A1 -> 01, A1+A2+A3 -> 010203
    std::map<char, char> letterstonum;
    letterstonum['A'] = '0';
    letterstonum['B'] = '1';
    letterstonum['C'] = '2';
    letterstonum['D'] = '3';
    letterstonum['E'] = '4';
    letterstonum['F'] = '5';
    letterstonum['G'] = '6';
    letterstonum['H'] = '7';
    letterstonum['I'] = '8';
    letterstonum['J'] = '9';

    std::string value; //Store the given string
    for (int i = 0; i < 10; i++){

        for (int j = 0; j < 9; j++){

            std::cin >> value;

            //If the first letter of the string is a number, we know it's not an instruction
            if (std::isdigit(value[0])){
                actual_spreadsheet[i][j] = std::stoi(value);
                theoretical_spreadsheet[i][j] = SOLVED;
            }
            
            else{
                
                //Translate the string
                std::string translated;

                for (int k = 0; k < value.length(); k++){

                    //View the string as batches of 3, the first character will be the letter, the second is a number and the last is a +
                    if (k % 3 == 0){
                        translated += letterstonum[value[k]];
                    }

                    else if (k % 3 == 1){
                        translated += value[k];
                    }

                }

                theoretical_spreadsheet[i][j] = translated;

            }

        }
        
    }

    bool global_updated = true; //Indicates something in the spreadsheet was updated after that traversal
    bool updated = false; //Indicates that when solving for a single cell, it is possible or not
    while (global_updated){

        global_updated = false;

        //For each row
        for (int i = 0; i < 10; i++){

            //For each column
            for (int j = 0; j < 9; j++){

                //If that cell is undefined
                if (actual_spreadsheet[i][j] == UNDEFINED){

                    //After translation, our instructions are now pairs of integers
                    int row, column, sum = 0; //Pair row and column

                    //For each character in string
                    for (int k = 0; k < theoretical_spreadsheet[i][j].length(); k++){

                        //The first number in the pair eg the row
                        if (k % 2 == 0){
                            row = theoretical_spreadsheet[i][j][k] - '0'; //We're performing this based on ASCII codes, '0' has code 48, minusing our char by '0' returns its int value
                        }

                        //The second number in the pair eg the column
                        else{
                            column = theoretical_spreadsheet[i][j][k] - '0' - 1; //-1 due to 1 indexing of the column input

                            //We know that the second number of each pair signals the end of that instruction/cell, attempt to figure out if the cell is defined
                            if (actual_spreadsheet[row][column] != UNDEFINED){
                                sum += actual_spreadsheet[row][column];
                                updated = true; //Possible
                            }
                            
                            //Instruction cell is undefined
                            else{
                                updated = false; //Not possible to solve
                                break;
                            }

                        }

                    }

                    //If possible aka all instruction cells are defined
                    if (updated == true){
                        actual_spreadsheet[i][j] = sum;
                        global_updated = true; //Something was changed, search again to see if something is solvable with the new information
                    }

                }

            }

        }
        
    }
    
    //Output spreadsheet
    for (int i = 0; i < 10; i++){

        for (int j = 0; j < 9; j++){

            if (actual_spreadsheet[i][j] == UNDEFINED){
                std::cout << '*' << ' ';
            }

            else{
                std::cout << actual_spreadsheet[i][j] << ' ';
            }

        }

        std::cout << '\n';

    }

    return 0;

}