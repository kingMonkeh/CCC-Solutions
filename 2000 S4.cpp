/*

2000 S4 - Golf

Topic: Dynamic Programming

Difficulty: Easy/Medium

I've never done dynamic programming before so I had quite a bit of difficulty on this relatively easy problem.

General idea:

Create an array that stores the minimum number of strokes to reach distance i, aka array[i] tells us the min number of strokes to reach i.

Initialize array[0] as 0 to begin.
Afterward attempt to solve for the next distance.

For example, following the sample input.

To solve for array[1], we iterate through each club and subtract its distance from 1, this will tell us the previous position we would've been in if we had used this club previously.
This also indicates whether the current spot is possible because if the previous location is negative, we would have overshot.
We must also watch out for the possibility that this previous location isn't possible either, meaning this location wouldn't be possible either.
We will mark impossible locations with -1.

Afterwards, assuming we've found a valid previous position such as array[0] if we were at array[1] with a club of distance 1.
We must now determine if it will give us the minimum number of strokes, since it's possible it will not.

For this reason we will take the minimum strokes between what was already written at array[i] and the amount of strokes at the previous location + 1.
Obviously, if we've never touched this location before, then this value should be the minimum. To make this happen, we will set a default value of 999999 to all locations to ensure that initial values are taken and values afterward may be taken.

*/

#include <iostream>
#include <vector>

int main(){

    int distance; //Distance to hole
    std::cin >> distance;

    int numOfClubs; //Number of clubs
    std::cin >> numOfClubs;

    std::vector<int> clubs (numOfClubs); //Stores clubs, order doesn't matter

    for (int i = 0; i < numOfClubs; i++){

        std::cin >> clubs[i];

    }

    //strokesTo[i] indicates how many strokes required to reach position i
    std::vector<int> strokesTo (distance + 1, 999999);
    strokesTo[0] = 0;

    //For each distance afterward
    for (int dist = 1; dist <= distance; dist++){

        bool possible = false; //If it's possible to reach this location

        //For each club
        for (int club = 0; club < numOfClubs; club++){

            //Check previous position if we hypothetically used this club
            int previous = dist - clubs[club];

            //If previous position is not negative and is possible
            if (previous >= 0 && strokesTo[previous] >= 0){

                //Take minimum
                strokesTo[dist] = std::min(strokesTo[previous] + 1, strokesTo[dist]);
                possible = true; //Mark possible

            }

        }

        //If impossible
        if (!possible){
            strokesTo[dist] = -1;
        }

    }

    //If it's possible to hit the ball in
    if (strokesTo[distance] > -1){
        std::cout << "Roberta wins in " << strokesTo[distance] << " strokes.";
    }

    //Otherwise, acknowledge defeat
    else{
        std::cout << "Roberta acknowledges defeat.";
    }
    
}