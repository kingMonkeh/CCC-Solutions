/*

1998 S3 - Mars Rover

Difficulty: Easy (Just very time consuming to implement)

This problem is quite simple. Imagine a cartesian plane with the lander at (0, 0), now simulate the rover's movement across the plane.

Key realization, regardless of what way the rover moves, it's minimum distance back to the lander is the horizontal distance from the lander + the vertical distance from the lander since it can only move in 4 directions. You can test this yourself.

Meaning you will only ever need 2 move commands and however many rotations required to achieve these move commands.

There are 8 possibilites to where the rover can end.
1. Top left quadrant
2. Top right quadrant
3. Bottom left quadrant
4. Bottom right quadrant
5. Positive X Axis
6. Negative X Axis
7. Positive Y Axis
8. Negative Y Axis

From each of the position, you must also consider 4 possible ending directions of the rover.

In total, 32 possibilites, very time consuming to implement

*/

#include <iostream>

int main(){

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++){

        //startX, startY for lander, roverX, roverY for rover
        int startX = 0, startY = 0, roverX = 0, roverY = 0, direction = 0;
        int instruction, distance; //I will be storing direction in the form of degrees, 0 is north, 90 is east, etc.

        while (true){

            std::cin >> instruction;

            //End of excursion
            if (instruction == 0){
                break;
            }

            //Move
            if (instruction == 1){

                std::cin >> distance;

                if (direction == 0){
                    roverY += distance;
                }

                else if (direction == 90){
                    roverX += distance;
                }

                else if (direction == 180){
                    roverY -= distance;
                }

                else{
                    roverX -= distance;
                }

            }

            //Turn right
            else if (instruction == 2){

                direction += 90;
                direction %= 360;

            }

            //Turn left
            else{

                direction += 270; //Going left 90 is the same thing as going right 270
                direction %= 360;

            }

        }

        //Output distance
        std::cout << "Distance is " << std::abs(roverX) + std::abs(roverY) << '\n';

        /*
        
        Way too many if statements, not gonna comment them all.
        General idea, determine which 2 directions you need to face, figure out which is closest from the starting direction, go to that one first, then go to the other afterward.

        */

        //Top Left Quadrant
        if (roverX < startX && roverY > startY){

            if (direction == 0){
                std::cout << 2 << '\n' << 1 << '\n' << startX - roverX << '\n' << 2 << '\n' << 1 << '\n' << roverY << '\n';
            }

            else if (direction == 90){
                std::cout << 1 << '\n' << startX - roverX << '\n' << 2 << '\n' << 1 << '\n' << roverY << '\n';
            }

            else if (direction == 180){
                std::cout << 1 << '\n' << roverY << '\n' << 3 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

            else{
                std::cout << 3 << '\n' << 1 << '\n' << roverY << '\n' << 3 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

        }

        //Top Right Quadrant
        if (roverX > startX && roverY > startY){

            if (direction == 0){
                std::cout << 3 << '\n' << 1 << '\n' << roverX << '\n' << 3 << '\n' << 1 << '\n' << roverY << '\n';
            }

            else if (direction == 90){
                std::cout << 2 << '\n' << 1 << '\n' << roverY << '\n' << 2 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else if (direction == 180){
                std::cout << 1 << '\n' << roverY << '\n' << 2 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else{
                std::cout << 1 << '\n' << roverX << '\n' << 3 << '\n' << 1 << '\n' << roverY << '\n';
            }

        }

        //Bottom Right Quadrant
        if (roverX > startX && roverY < startY){

            if (direction == 0){
                std::cout << 1 << '\n' << startY - roverY << '\n' << 3 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else if (direction == 90){
                std::cout << 3 << '\n' << 1 << '\n' << startY - roverY << '\n' << 3 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else if (direction == 180){
                std::cout << 2 << '\n' << 1 << '\n' << roverX << '\n' << 2 << '\n' << 1 << '\n' << startY - roverY << '\n' ;
            }

            else{
                std::cout << 1 << '\n' << roverX << '\n' << 2 << '\n' << 1 << '\n' << startY - roverY << '\n';
            }

        }

        //Bottom Left Quadrant
        if (roverX < startX && roverY < startY){

            if (direction == 0){
                std::cout << 1 << '\n' << startY - roverY << '\n' << 2 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

            else if (direction == 90){
                std::cout << 1 << '\n' << startX - roverX << '\n' << 3 << '\n' << 1 << '\n' << startY - roverY << '\n';
            }

            else if (direction == 180){
                std::cout << 3 << '\n' << 1 << '\n' << startX - roverX << '\n' << 3 << '\n' << 1 << '\n' << startY - roverY << '\n';
            }

            else{
                std::cout << 2 << '\n' << 1 << '\n' << startY - roverY << '\n' << 2 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

        }

        //Positive Y Axis
        if (roverX == startX && roverY > startY){
            
            if (direction == 0){
                std::cout << 2 << '\n' << 2 << '\n' << 1 << '\n' << roverY << '\n';
            }

            else if (direction == 90){
                std::cout << 2 << '\n' << 1 << '\n' << roverY << '\n';
            }

            else if (direction == 180){
                std::cout << 1 << '\n' << roverY << '\n';
            }

            else{
                std::cout << 3 << '\n' << 1 << '\n' << roverY << '\n';
            }

        }

        //Negative Y Axis

        if (roverX == startX && roverY < startY){
            
            if (direction == 0){
                std::cout << 1 << '\n' << startY - roverY << '\n';
            }

            else if (direction == 90){
                std::cout << 3 << '\n' << 1 << '\n' << startY - roverY << '\n';
            }

            else if (direction == 180){
                std::cout << 2 << '\n' << 2 << '\n' << 1 << '\n' << startY - roverY << '\n';
            }

            else{
                std::cout << 2 << '\n' << 1 << '\n' << startY - roverY << '\n';
            }

        }

        //Positive X Axis

        if (roverX > startX && roverY == startY){
            
            if (direction == 0){
                std::cout << 3 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else if (direction == 90){
                std::cout << 2 << '\n' << 2 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else if (direction == 180){
                std::cout << 2 << '\n' << 1 << '\n' << roverX << '\n';
            }

            else{
                std::cout << 1 << '\n' << roverX << '\n';
            }

        }

        //Negative X Axis

        if (roverX < startX && roverY == startY){
            
            if (direction == 0){
                std::cout << 2 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

            else if (direction == 90){
                std::cout << 1 << '\n' << startX - roverX << '\n';
                
            }

            else if (direction == 180){
                std::cout << 3 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

            else{
                std::cout << 2 << '\n' << 2 << '\n' << 1 << '\n' << startX - roverX << '\n';
            }

        }

    }

    return 0;

}