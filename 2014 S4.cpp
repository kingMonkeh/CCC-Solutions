/*

2014 S4 - Tinted Glass Window

Difficulty: Hard

Basic Idea: 
Start by imaginarily extending all horizontal lines. We will then compress the y axis into horizontal segments formed by these horizontal lines.
Afterward, imaginarily extend all vertical line segments infinitely as well. After doing so, you will have a grid with various segments.

We will now through each column of segments from left to right, adding tint factor as we go.
To determine the tint factor of columns, we will mark the left side of a window as the incoming side in which we will update all horizontal segments that it affects
Then to undo the tint once we've passed the window, we will mark its right side as the outgoing side which once we pass, will decrease the tint factor of all horizontal segments it touches

In each column of segments, we iterate through the horizontal segments top down adding their area if their tint factor is high enough

-----------------
|   |       |   |
|   |       |   |
|---|-----------|
|   |       |   |
|---|-----------|
|   |       |   |
-----------------

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

int main(){

    int N, T;

    std::cin >> N >> T;

    std::vector<std::vector<long long>> verticalLines; //The vertical lines
    //Note that we use set since we don't want duplicate horizontal lengths because then a horizontal segment of height 0 would occur which is impossible
    //We also want them sorted, since we're ordering our segments top to bottom
    std::set<long long> tempHorizontalSegments; //These are the horizontal lines of the rectangles, this set is temporary
    
    for (int i = 0; i < N; i++){

        long long x1, y1, x2, y2, t;
        std::cin >> x1 >> y1 >> x2 >> y2 >> t;

        //Add vertical lines, keep track of their y coords since these will tell us what segment they affect
        verticalLines.push_back({x1, y1, y2, t}); //Incoming side
        verticalLines.push_back({x2, y1, y2, -t}); //Outgoing side, notice that we have negative tint factor

        tempHorizontalSegments.insert(y1);
        tempHorizontalSegments.insert(y2);

    }

    std::vector<long long> horizontalSegments (tempHorizontalSegments.begin(), tempHorizontalSegments.end()); //Copy the set over so that we can use indices
    std::sort(verticalLines.begin(), verticalLines.end()); //Sort vertical lines, we must allow duplicates since each line affects different segments

    //This will map a literal y coordinate to its index, top to bottom, this will allow us to access horizontal segments within a certain range of y coords
    std::map<long long, long long> yCoordToLineNum;
    for (int i = 0; i < horizontalSegments.size(); i++){
        yCoordToLineNum[horizontalSegments[i]] = i;
    }

    //Our compressed y axis, compressedYaxis[0] is the block between yCoordToLineNum[0] and yCoordToLineNum[1]
    //The actual value being stored however is the tint factor of this block
    std::vector<long long> compressedYaxis (horizontalSegments.size() - 1, 0);

    long long goodArea = 0; //Our answer

    //For each vertical line
    for (int i = 0; i < verticalLines.size(); i++){

        //Update all horizontal segments that it affects
        for (int j = yCoordToLineNum[verticalLines[i][1]]; j < yCoordToLineNum[verticalLines[i][2]]; j++){
            compressedYaxis[j] += verticalLines[i][3];
        }

        //For each horizontal block
        for (int j = 0; j < compressedYaxis.size(); j++){
            
            //If the tint factor is high enough
            if (compressedYaxis[j] >= T){
                //Add the area, height * width
                goodArea += std::abs(horizontalSegments[j] - horizontalSegments[j + 1]) * std::abs(verticalLines[i][0] - verticalLines[i + 1][0]);
            }

        }

    }

    std::cout << goodArea;

    return 0;

}