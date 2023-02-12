/*

MOCK 2023 J2 - Healthy Schedule

Difficulty: Easy

Simple if statements

*/

#include <iostream>

int main(){

    int S, W;
    std::cin >> S >> W;

    if (W >= 6 && W <= 9 && S >= 20 && S <= 23){

        W += 24; //Add 24 since it's a 24 hour clock, you can imagin 540 degrees around a circle as the same as 180 degrees around the circle.
        int timeBetween = W - S;

        if (timeBetween >= 8 && timeBetween <= 10){
            std::cout << "Healthy" << '\n';
        }

        else{
            std::cout << "Unhealthy" << '\n';
        }

    }

    else{
        std::cout << "Unhealthy" << '\n';
    }

    return 0;

}