/*

2006 S3 - Tin Can Telephone

Difficulty: Medium/Hard

Required Knowledge: Geometry + Linear Systems

This question is quite challenging, I'd made it half way through but then I got stuck so I was forced to read a solution.

Here's the general idea of how it works.

You can view each building as a collection of lines. So as one line intersects with the line formed by Romy and Jules, then this building is blocking the path.
Another important thing to note is that if you're inside of a building, the line is not blocked even if you're on the wall of the building.

Therefore, to determine intersection of two lines, we will be solving linear systems. All variables in a linear system can be represented in terms of the other variables. I will leave this for you to prove.

However there's one type of line that we must watch out for.
That is vertical lines since they have an undefined slope due to division by 0.

Theres 4 cases that we must observe:
1. Both lines are parallel and are vertical
2. Both lines are parallel but not vertical
3. Both lines are not parallel and one is vertical
4. Both lines are not parallel and there's no vertical lines

*/


#include <iostream>
#define UNDEFINED 9999999 //UNDEFINED is what I will be calling the slope of a vertical line

//Check if the number is in between boundaryA and boundaryB
bool inRange (double number, double boundaryA, double boundaryB){

    return (number >= boundaryA && number <= boundaryB) || (number <= boundaryA && number >= boundaryB);

}

bool blocking(double RomyX, double RomyY, double JulesX, double JulesY, double cornerA_x, double cornerA_y, double cornerB_x, double cornerB_y){

    //y = mx + b, slope variable is obvious, b variable is bRomyJules 
    double SlopeRomyJules, bRomyJules;

    //If Vertical
    if (RomyX == JulesX){
        SlopeRomyJules = UNDEFINED;
        bRomyJules = 0;
    }

    //Otherwise
    else{
        SlopeRomyJules = (RomyY - JulesY) / (RomyX - JulesX);
        bRomyJules = RomyY - (SlopeRomyJules * RomyX);
    }

    //The side of the building
    double CornerA_CornerB_Slope, bCornerA_CornerB;

    //If vertical
    if (cornerA_x == cornerB_x){
        CornerA_CornerB_Slope = UNDEFINED;
        bCornerA_CornerB = 0;
    }

    //If angled
    else{
        CornerA_CornerB_Slope = (cornerA_y - cornerB_y) / (cornerA_x - cornerB_x);
        bCornerA_CornerB = cornerA_y - (CornerA_CornerB_Slope * cornerA_x);
    }

    //If both lines are parallel
    if (SlopeRomyJules == CornerA_CornerB_Slope){

        //If both lines are angled

        if (SlopeRomyJules != UNDEFINED && CornerA_CornerB_Slope != UNDEFINED){

            return (bRomyJules == bCornerA_CornerB) && (inRange(cornerA_x, RomyX, JulesX) || inRange(cornerB_x, RomyX, JulesX));

        }

        //If both lines are vertical

        else{

            return (RomyX == cornerA_x) && (inRange(cornerA_y, RomyY, JulesY) || inRange(cornerB_y, RomyY, JulesY));

        }

    }

    //Lines are not parallel
    else{

        double pointOfIntersectionX, pointOfIntersectionY;
        
        //If both lines are angled

        if (SlopeRomyJules != UNDEFINED && CornerA_CornerB_Slope != UNDEFINED){

            pointOfIntersectionX = (bCornerA_CornerB - bRomyJules) / (SlopeRomyJules - CornerA_CornerB_Slope);
            pointOfIntersectionY = (SlopeRomyJules * pointOfIntersectionX) + bRomyJules;

            return inRange(pointOfIntersectionX, RomyX, JulesX) && inRange(pointOfIntersectionY, RomyY, JulesY) && inRange(pointOfIntersectionX, cornerA_x, cornerB_x) && inRange(pointOfIntersectionY, cornerA_y, cornerB_y);

        }

        //If one line is vertical and the other is angled

        else{

            double pointOfIntersectionX, pointOfIntersectionY;

            //Romy and Jules create a vertical line
            if (SlopeRomyJules == UNDEFINED){

                pointOfIntersectionX = RomyX;
                pointOfIntersectionY = (CornerA_CornerB_Slope * pointOfIntersectionX) + bCornerA_CornerB;

            }

            //The two other points create a vertical line
            else{

                pointOfIntersectionX = cornerA_x;
                pointOfIntersectionY = (SlopeRomyJules * pointOfIntersectionX) + bRomyJules;

            }

            return inRange(pointOfIntersectionX, RomyX, JulesX) && inRange(pointOfIntersectionY, RomyY, JulesY) && inRange(pointOfIntersectionX, cornerA_x, cornerB_x) && inRange(pointOfIntersectionY, cornerA_y, cornerB_y);

        }

    }

}

int main(){

    int RomyX, RomyY, JulesX, JulesY, numberOfShapes;
    std::cin >> RomyX >> RomyY >> JulesX >> JulesY >> numberOfShapes;

    int intersectedBuildings = 0;

    for (int i = 0; i < numberOfShapes; i++){

        int numberOfCorners;
        //CornerA just represents one end of the line, cornerB represents the other end of the line
        double cornerA_x, cornerA_y, cornerB_x, cornerB_y, firstCornerX, firstCornerY;
        bool blocked = false; //If the building is blocking
        std::cin >> numberOfCorners >> cornerA_x >> cornerA_y; //Take in the first point of the building
        //Keep a copy of the first point since when we make it to the last point, we must still check if the line formed by the last point and the first point intersect
        firstCornerX = cornerA_x; 
        firstCornerY = cornerA_y;

        //We can check each line on the go since the question states that points are inputted in clockwise or counterclockwise order
        //numberOfCorners - 1 since we've already taken in the first point
        for (int j = 0; j < numberOfCorners - 1; j++){

            std::cin >> cornerB_x >> cornerB_y; //Next point
            blocked = blocked || blocking(RomyX, RomyY, JulesX, JulesY, cornerA_x, cornerA_y, cornerB_x, cornerB_y); //Check, remember only one line needs to intersect
            //Set next point to current point
            cornerA_x = cornerB_x; 
            cornerA_y = cornerB_y;
            
        }

        blocked = blocked || blocking(RomyX, RomyY, JulesX, JulesY, cornerA_x, cornerA_y, firstCornerX, firstCornerY); //Last point to first point

        if (blocked){
            intersectedBuildings++;
        }

    }

    std::cout << intersectedBuildings;

    return 0;

}