/*

2005 S2 - Mouse Move

Difficulty: Very Easy

No special algorithm, you quite literaly just implement the problem and output the answer

*/

#include <iostream>
#include <utility>

int main(){

    std::pair<int, int> screenDimensions;
    std::cin >> screenDimensions.first >> screenDimensions.second;

    std::pair<int, int> mousePos;
    mousePos.first = 0;
    mousePos.second = 0;

    //Loop until 0, 0 is inputted
    while (true){

        std::pair<int, int> instruction;
        std::cin >> instruction.first >> instruction.second;

        //Input terminated
        if (instruction.first == 0 && instruction.second == 0){
            break;
        }

        //Apply changes to mouse position
        mousePos.first += instruction.first;
        mousePos.second += instruction.second;

        //If too far left
        if (mousePos.first < 0){
            mousePos.first = 0;
        }

        //If too far right
        else if (mousePos.first > screenDimensions.first){
            mousePos.first = screenDimensions.first;
        }

        //If too far down
        if (mousePos.second < 0){
            mousePos.second = 0;
        }

        //If too far up
        else if (mousePos.second > screenDimensions.second){
            mousePos.second = screenDimensions.second;
        }

        //Output answer
        std::cout << mousePos.first << ' ' << mousePos.second << '\n';

    }

    return 0;

}