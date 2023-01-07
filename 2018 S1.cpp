/*

2018 S1 - Voronoi Villages

Difficulty: Easy

Key Idea:
It's always optimal to go for the midpoint between two villages when determining neighbourhood boundaries.
Order the input and then solve for each boundary size. Store items in set so that they're ordered automatically, this will make accessing elements a bit more difficult.

*/

#include <set>
#include <iostream>
#include <iomanip>

int main(){

    int N;
    std::cin >> N;

    std::set<int> villages; //Stores village locations
    for (int i = 0; i < N; i++){
        int pos;
        std::cin >> pos;

        villages.insert(pos);
    }

    auto it = villages.begin(); //Since the leftmost village actually has infinite size, we ignore it and instead go to the second village
    it++;

    std::set<double> size; //Storing sizes

    auto end = villages.end(); //Since the rightmost village also has infinite size, we also want to ignore calculating it
    end--;

    for (it; it != villages.end(); it++){

        if (it != end){

            double left, right;

            double village2 = *it; //Current village
            it--;
            double village1 = *it; //Village to the left of current village
            it++;
            it++;
            double village3 = *it; //Village to the right of current village
            it--;

            //Calculate left and right
            left = (village2 - village1) / 2;
            right = (village3 - village2) / 2;

            //Add neighbourhood size to set
            size.insert(left + right);

        }

        else break;

    }

    //Output min, use std::fixed and std::setprecision to ensure 1 decimal place.
    std::cout << std::fixed << std::setprecision(1) << *size.begin();

    return 0;
}