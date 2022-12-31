/*

Difficulty: Easy

Ad Hoc Problem

There's no fancy algorithm for this problem. You quite literaly just input the information given into the formula for the area of a trapezoid and sum up the areas.
Things that would be important to know for solving this question:
Formula for area of a trapezoid
For loops, while loops could be used as well.

Only thing to watch out for if you're using C++ is when you cout very large numbers, they may be in scientific notation, to prevent this, use std::fixed

*/

#include <iostream>
#include <vector>

int main(){

    int N;

    std::cin >> N;

    //Collect heights of fences
    std::vector<double> heights (N + 1);

    for (int i = 0; i <= N; i++){

        std::cin >> heights[i];

    }

    //Collect bases/widths of fences
    std::vector<double> widths (N);

    for (int i = 0; i < N; i++){

        std::cin >> widths[i];

    }

    double areaSum = 0, trapezoidArea;

    //Calculate area of the fences
    for (int i = 0; i < N; i++){

        trapezoidArea = (heights[i] + heights[i + 1]) / 2 * widths[i];
        areaSum += trapezoidArea;

    }

    //To prevent scientific notation
    std::cout << std::fixed << areaSum;

    return 0;
}