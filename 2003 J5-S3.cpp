/*

2003 J5/S3 - Floor Plan

Difficulty: Easy

Problem Type: Graph Theory

To determine the area of each room, I will be using recursion. 
Essentially, I drop the index of the first empty space I encounter in that room, afterwards from the square, I will check up, down, left, right for other squares and call the same function again.
In each call, I will increase the area of the room by 1 and change the value of the square to 'c', meaning counted. This way, I do not count the same square twice.

I then put area of each room into a multiset to allow duplicates, but to also make sure it's ordered since we must fill from greatest to least.
Afterwards, we just calculate how many rooms we can fill and how much is leftover.

*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

std::vector<std::vector<char>> floor_plan; //Represents the actual floor plan
int rooms = 0; //Represents how many rooms can be filled
int flooring, r, c; //Input variables
int room_area = 0; //Area of a room, this number will be reset after calculating the area of a room
std::multiset<int> room_areas; //Multiset containing all room areas

//Find area of a room function
void find_area (int i, int j){

    floor_plan[i][j] = 'c'; //Prevent duplicate counting
    room_area++; //Add area

    //Check UP
    if (i - 1 >= 0 && floor_plan[i - 1][j] == '.'){
        find_area (i - 1, j);
    }

    //Check Right
    if (j + 1 < c && floor_plan[i][j + 1] == '.'){
        find_area (i, j + 1);
    }

    //Check Down
    if (i + 1 < r && floor_plan[i + 1][j] == '.'){
        find_area (i + 1, j);
    }

    //Check Left
    if (j - 1 > 0 && floor_plan[i][j - 1] == '.'){
        find_area (i, j - 1);
    }

}

int main(){

    std::cin >> flooring >> r >> c;

    //Fill in floor plan
    for (int i = 0; i < r; i++){

        std::string row;
        std::cin >> row;

        std::vector<char> floor (c);

        for (int j = 0; j < c; j++){
            floor[j] = row[j];
        }

        floor_plan.push_back(floor);

    }

    //Traverse floor plan, search for empty space indicating a room
    for (int i = 0; i < r; i++){

        for (int j = 0; j < c; j++){

            //If a room is found
            if (floor_plan[i][j] == '.'){
                find_area (i, j); //Find area
                room_areas.insert(room_area); //Add area to set
                room_area = 0; //Reset area to prepare for the next room
            }

        }

    }

    //Determine how many rooms can be filled
    while (true){

        //Traverse multiset in reverse since it's ordered from least to greatest
        for (auto it = room_areas.rbegin(); it != room_areas.rend(); it++){
            
            flooring -= *it;

            //Remember to include 0
            if (flooring >= 0){
                rooms++;
            }

            //If we run out of flooring early
            else{
                flooring += *it;
                break;
            }

        }

        break;

    }

    //Outputting our answer, very important that we follow format correctly, if there's 1 room we must print out "room", otherwise "rooms"

    std::cout << rooms;

    if (rooms > 1 || rooms == 0){
        std::cout << " rooms, ";
    } 

    else{
        std::cout << " room, ";
    }

    std::cout << flooring << " square metre(s) left over";

    return 0;

}