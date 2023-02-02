/*

2002 J5/S3 - Blindfold

Difficulty: Easy or Hard depending on what judge you're using

For the CCC data, m can be no larger than 50, so this question is very easy to brute force. For DMOJ added test cases where m = 30 000, the question becomes extremely difficult

CCC - 15/15
DMOJ 100/150

General idea, try every position in the backyard that is not a cell, then try with all 4 starting directions and simulate Colin's movement.

*/

#include <iostream>
#include <vector>
#include <string>

int main(){

    int r, c;
    std::cin >> r >> c;

    std::vector<std::string> backyard (r); //Store backyard

    //Fill in backyard
    for (int i = 0; i < r; i++){
        std::cin >> backyard[i];
    }

    int m;
    std::cin >> m;

    std::string instructions; //Storing instructions as string
    
    for (int i = 0; i < m; i++){

        char instruction;
        std::cin >> instruction;
        instructions += instruction;

    }

    std::vector<char> directions {'N', 'S', 'E', 'W'};
    int colinx, coliny; //colinx is Colin's x position, coliny is Colin's y position

    //For every row
    for (int i = 0; i < r; i++){

        coliny = i;

        //for every column
        for (int j = 0; j < c; j++){

            colinx = j;

            //If obstacle skip
            if (backyard[coliny][colinx] == 'X'){
                continue;
            }

            //For all 4 starting directions
            for (char d: directions){

                char direction = d;
                int possible = 0; //Determine if it's possible to perform this set of instructions, eg possible = 0 if we walk out of bounds or hit an obstacle

                //For each instruction
                for (int k = 0; k < instructions.length(); k++){

                    //Forwards
                    if (instructions[k] == 'F'){

                        possible++;

                        //North
                        if (direction == 'N'){

                            coliny -= 1;

                            //If out of range or obstacle is hit
                            if (coliny < 0 || backyard[coliny][colinx] == 'X'){
                                possible = 0;
                                break;
                            }

                        }

                        //South
                        else if (direction == 'S'){

                            coliny += 1;

                            //If out of range or obstacle is hit
                            if (coliny == r || backyard[coliny][colinx] == 'X'){
                                possible = 0;
                                break;
                            }

                        }

                        //West
                        else if (direction == 'W'){

                            colinx -= 1;

                            //If out of range or obstacle is hit
                            if (colinx < 0 || backyard[coliny][colinx] == 'X'){
                                possible = 0;
                                break;
                            }

                        }

                        //East
                        else if (direction == 'E'){

                            colinx += 1;

                            //If out of range or obstacle is hit
                            if (colinx == c || backyard[coliny][colinx] == 'X'){
                                possible = 0;
                                break;
                            }

                        }

                    }

                    //Swap directions
                    else if (instructions[k] == 'L'){

                        if (direction == 'N'){
                            direction = 'W';
                        }

                        else if (direction == 'W'){
                            direction = 'S';
                        }

                        else if (direction == 'S'){
                            direction = 'E';
                        }

                        else{
                            direction = 'N';
                        }

                    }

                    //Swap directions
                    else{

                        if (direction == 'N'){
                            direction = 'E';
                        }

                        else if (direction == 'E'){
                            direction = 'S';
                        }

                        else if (direction == 'S'){
                            direction = 'W';
                        }

                        else{
                            direction = 'N';
                        }

                    }

                }

                //If instructions are possible, mark as a final position
                if (possible > 0){
                    backyard[coliny][colinx] = '*';
                }
                
                //Reset coliny and colinx for the next possible starting direction
                coliny = i;
                colinx = j;

            }

        }

    }

    //Output new backyard
    for (std::string line: backyard){
        std::cout << line << '\n';
    }

    return 0;

}