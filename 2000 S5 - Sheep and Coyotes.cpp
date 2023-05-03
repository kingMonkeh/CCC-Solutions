/*

2000 S5 - Sheep and Coyotes

Difficulty: Medium

This shit isn't even difficult. It's just that arithmetic with fucking doubles sucks because of floating point imprecision
Moral of the story, use long doubles when performing calculations instead of wasting 8.5 years debugging and raging like me

Credit to MMHS repository
Basic idea:
Basically we look at every sheep,
For each sheep, we compare it to every other sheep
Between two sheep, if you draw a line that connects them,
Then draw the perpendicular bisector to this line
This perpendicular bisector will then split the x axis into 2 halves
the left side tells us that all points on the left side are closer to the left point then the right point
All points on the x axis on the right half are closer to the sheep on the right

Basically, we just update the ranges
If left > right, this sheep is safe, otherwise, if left <= right, this shape may be eaten

*/

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

int main(){
    int totalSheep;
    std::cin >> totalSheep;
    //Sheep coords
    std::pair<long double, long double> sheeps [1000];
    for (int i = 0; i < totalSheep; i++){
        long double x, y;
        std::cin >> x >> y;
        sheeps[i] = std::make_pair(x, y);
    }
    
    //For each sheep
    for (int i = 0; i < totalSheep; i++){
        long double left = 0, right = 1000; //Our range
        //Compare it to every other sheep
        for (int j = 0; j < totalSheep; j++){
            //Don't compare the sheep to itself
            if (i == j){
                continue;
            }
            //If sheeps have same x value, the lower one has a chance of being eaten
            if (sheeps[i].first == sheeps[j].first){
                //If lower, may be eaten
                if (sheeps[i].second < sheeps[j].second){
                    continue;
                }
                //If it's higher, its guranteed to be safe, so just skip to next point
                else{
                    goto nextPoint;
                }
            }
            long double split; //Where the perpendicular bisector intersects the x axis
            //Midpoint between two sheep
            long double midpointX = (sheeps[i].first + sheeps[j].first) / 2;
            long double midpointY = (sheeps[i].second + sheeps[j].second) / 2;
            //If they have the same y coord, the split is just the midpoint between the two
            if (sheeps[i].second == sheeps[j].second){
                split = midpointX;
            }
            //Otherwise you have to do a bit more algebra, not to complex, i leave this part as a math exercise to prove
            else{
                long double inverseSlope = -(sheeps[i].first - sheeps[j].first) / (sheeps[i].second - sheeps[j].second);
                split = -(midpointY - inverseSlope * midpointX) / inverseSlope;
            }
            
            //We now update the range depending on whether the main sheep is on the left or right
            //Sheep 1 is on the left
            if (sheeps[i].first < sheeps[j].first){
                if (right > split){
                    right = split;
                }
            }
            //It's on the right
            else{
                if (split > left){
                    left = split;
                }
            }
        }
        //After all comparisons, if left <= right, this sheep may be eaten
        if (left <= right){
            printf("%s%.2Lf%s%.2Lf%s", "The sheep at (", sheeps[i].first, ", ", sheeps[i].second, ") might be eaten.\n");
        }
        nextPoint:;
    }
}