/*

2017 J5/S3 - Nailed It!

Difficulty: Easy/Medium

This question isn't too difficult, it suffices to brute force all possible heights and determine the greatest possible length.

Note that for any height h
A pair of boards that has height h is made up of 2 boards of height i and height - i
Also note that for every possible integer, there's only other integer that will allow it to equal the height.

This will allow us to quickly solve for the max length of the fence given a board height since we can just subtract the minimum of the two corresponding values in a pair

*/

#include <iostream>
#include <vector>
#include <map>

std::map<int, int> lengths; //Stores the frequency of each wood length since there can be duplicate boards, key represents board length, value represents number of boards of that length

//Function that returns max length of fence if we choose to make all boards height h
int numberOfPossibleBoards (int height){

    int possibleBoards = 0; //Initialize our answer
    std::vector<bool> usedBoards (4001, false); //We don't want to count duplicate pairs since <1, 4> and <4, 1> are the same

    //Loop through all wood lengths less than height since if we go up to height or past it even, there's no corresponding value in the pair that will create the desired height
    for (int i = 1; i < height; i++){

        if (!usedBoards[i]){

            //Imagine we desire a board of height 10 and we have two pieces of wood of length 5, they can be added together
            if (i == height - i){
                possibleBoards += lengths[i] / 2;
                continue;
            }

            //Otherwise, if a pair of distinct values
            possibleBoards += std::min(lengths[i], lengths[height - i]); //If you want a board of length 4 and you have 2 pieces of wood of length 3 and 1 piece of wood of length 1, even though you have multiple pieces of length 3 wood, you only have one piece of length 1 wood, therefore take the minimum
            usedBoards[i] = true;
            usedBoards[height - i] = true;
        }
        
    }

    return possibleBoards;

}

int main(){

    int N;
    
    std::cin >> N;

    //Initialize wood lengths
    for (int i = 1; i <= 2000; i++){
        lengths[i] = 0;
    }

    for (int i = 0; i < N; i++){

        int num;
        std::cin >> num;
        lengths[num]++; //Count frequency

    }

    std::map<int, int> numberOfWays; //Key is the length and the value is the number of possible heights that produce a fence of that length
    
    //Up to 4000 since a piece of wood has max height 2000 and 2 pieces of wood combined produces height 4000
    for (int i = 1; i < 4000; i++){
        numberOfWays[numberOfPossibleBoards(i)]++;
    }

    //Maps are ordered by key, therefore the largest possible length will be at the end of the map
    std::cout << numberOfWays.rbegin()->first << ' ' << numberOfWays.rbegin()->second;

    return 0;

}