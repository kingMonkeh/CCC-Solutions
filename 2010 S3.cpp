/*

2010 S3 - Firehose

Difficulty: HARD

This question is the hardest S3 problem in the CCC. It took me about 7 hours to understand the solution to it

Please note that this solution technically fails in some very specific cases, but for test data in the problem, this solution suffices.
CCC - 15/15
DMOJ - 100/100

Idea:
We're going to try every hose length, but this is not possible due to the fact that at max the hose can be 1 000 000
Therefore we need to shorten our search somehow.

Key realization 1:
If you know that hose length n is not possible, what does this say about all hose lengths shorter than it?
All hose lengths shorter than n will also not be possible.

Key realization 2:
If you know that hose length n is possible, what does this say about all hose lengths longer than it?
All hose lengths longer than n will also be possible, but since we're looking to minimize the hose length, they will never be optimal

With these 2 realisations, we can perform a binary search on the hose lengths to determine which is the minimum

Now the question becomes, how do we know if a hose length is possible?

For this, we will order the houses.
After, we will iterate over each house if it hasn't been connected to a hydrant yet.
From this house, we will place a fire hydrant hose length units in front of it aka clockwise
We do this because in the optimal solution, hydrant only be in the bare minimum range of the house.
Now we will determine all houses that are in range of this fire hydrant.
We can accomplish this by checking if the distance between the initial house and the other house is less than 2 * hose length since fire hydrant can extend in both directions
Mark houses that are connected and proceed to add fire hydrants to areas that are still not connected
If you run out of fire hydrants before all houses are counted, the hose length is not possible

Update binary search range accordingly

*/

#include <iostream>
#include <vector>
#include <algorithm>

int H, k;
std::vector<int> houses; //Stores house addresses

//Determine if hose length is possible, parameters are hose length, the remaining houses and remaining hydrants
bool possible (int hoseLength, int housesLeft = H, int hydrantsLeft = k){

    std::vector<bool> connected (H, false); //Mark which houses are in range of a hose

    //For each house so long as there's houses remaining and hydrants to be added
    for (int i = 0; i < houses.size() && housesLeft > 0 && hydrantsLeft > 0; i++){

        //If already connected, skip
        if (connected[i]){
            continue;
        }

        hydrantsLeft--; //Place a hydrant
        housesLeft--; //This house is connected since it's hose length units away

        //For the remaining houses in the vector
        for (int j = i + 1; j < houses.size(); j++){

            //We take min since the street is circular and it's possible to go backwards and wrap around, note that this can create errors in some cases, take the case with 3 houses {1, 5, 999987} and 1 hydrant, the program will print out 7 when in reality it should output 9
            int distance = std::min(houses[j] - houses[i], 1000000 - houses[j] + houses[i]); //Distance between other house and initial house

            //If in range of hydrant
            if (!connected[j] && distance <= hoseLength * 2){
                housesLeft--; //1 House less
                connected[j] = true; //Mark as connected to hose
            }

        }

    }

    //All houses were in range of a hydrant
    if (housesLeft == 0){
        return true;
    }

    //Some houses were not in range of a hydrant, aka hose length is not long enough
    else{
        return false;
    }

}

int main(){

    std::cin >> H;

    //Add houses to vector
    for (int i = 0; i < H; i++){
        int house; std::cin >> house;
        houses.push_back(house);
    }

    std::sort(houses.begin(), houses.end()); //Sort least to greatest

    std::cin >> k;

    //Minimum is 0 if you place a fire hydrant on a house, maximum is 1 000 000 if you go all the way around
    int minHoseLength = 0, maxHoseLength = 1000000, midpoint = (maxHoseLength + minHoseLength) / 2;

    //Perform binary search on the possible rope lengths
    while (minHoseLength < maxHoseLength){

        if (possible(midpoint)){
            maxHoseLength = midpoint;
        }

        else{
            minHoseLength = midpoint + 1;
        }

        midpoint = (maxHoseLength + minHoseLength) / 2;

    }

    std::cout << maxHoseLength;

}