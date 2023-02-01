/*

My attempt at optimizing my solution to pass the DMOJ test cases, it failed horribly

*/

#include <iostream>
#include <vector>
#include <string>

int r, c;
std::vector<std::string> backyard;
std::vector<int> instructions;
int numberOfinstructions;

void walk(int direction, int coliny, int colinx, int instruction_number){

    if (instruction_number == numberOfinstructions){
        backyard[coliny][colinx] = '*';
    }

    else{

        int start; bool blocked = false;

        if (instructions[instruction_number] > 0){

            if (direction == 0){
                start = coliny;
                coliny -= instructions[instruction_number];

                if (coliny >= 0){
                    for (int i = coliny; i < start; i++){
                        if (backyard[i][colinx] == 'X'){
                            blocked = true;
                        }
                    }   
                }
            }

            else if (direction == 180){
                start = coliny;
                coliny += instructions[instruction_number];

                if (coliny < r){
                    for (int i = start; i < coliny; i++){
                        if (backyard[i][colinx] == 'X'){
                            blocked = true;
                        }
                    }   
                }

            }

            else if (direction == 270){
                start = colinx;
                colinx -= instructions[instruction_number];

                if (colinx >= 0){
                    for (int i = colinx; i < start; i++){
                        if (backyard[coliny][i] == 'X'){
                            blocked = true;
                        }
                    }   
                }
                
            }

            else if (direction == 90){
                start = colinx;
                colinx += instructions[instruction_number];

                if (colinx < c){
                    for (int i = start; i < colinx; i++){
                        if (backyard[coliny][i] == 'X'){
                            blocked = true;
                        }
                    }   
                }

            }

        }

        else{

            direction -= instructions[instruction_number];
            direction %= 360;

        }

        instruction_number++;

        if (colinx >= 0 && colinx < c && coliny >= 0 && coliny < r && backyard[coliny][colinx] != 'X' && !blocked){
            walk(direction, coliny, colinx, instruction_number);
        }

    }

    

}

int main(){

    std::cin >> r >> c;

    backyard.resize(r);

    for (int i = 0; i < r; i++){
        std::cin >> backyard[i];
    }

    int m;
    std::cin >> m;
    
    int f_counter = 0, rotate = 0;
    int previous_instruction = 0;
    for (int i = 0; i < m; i++){

        char instruction;
        std::cin >> instruction;

        if (instruction == 'F'){
            f_counter++;

            if (rotate > 0){
                instructions.push_back(-rotate);
                rotate = 0;
            }
            
        }

        else{

            if (f_counter > 0){
                instructions.push_back(f_counter);
                f_counter = 0;
            }

            if (instruction == 'L'){
                
                rotate -= 90;

                if (rotate < 0){
                    rotate = 270;
                }

            }

            else{

                rotate += 90;
                rotate %= 360;

            }

        }

    }

    if (f_counter > 0){
        instructions.push_back(f_counter);
    }

    else if (rotate > 0){
        instructions.push_back(rotate);
    }

    numberOfinstructions = instructions.size();

    std::vector<int> directions {0, 90, 180, 270};
    int colinx, coliny;

    for (int i = 0; i < r; i++){

        coliny = i;

        for (int j = 0; j < c; j++){

            colinx = j;

            if (backyard[coliny][colinx] == 'X'){
                continue;
            }

            for (int d: directions){

                walk(d, coliny, colinx, 0);

            }

        }

    }

    for (std::string line: backyard){
        std::cout << line << '\n';
    }

    return 0;

}