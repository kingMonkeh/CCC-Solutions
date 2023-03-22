/*

2004 S4 - Space Turtle

Difficulty: Medium/Hard

This problem very annoying 3-D geometry problem

Basically, you just imagine that the turtle is the origin and that everything revolves around the turtles perspective
So when the turtle moves, you don't actually move the turtle, instead you move the shell in reference to the turtle

When the turtle changes directions, you can imagine this as it rotating all of its axes
Now, all you have to do is just update the shells position accordingly within this new set of axes

Notice that the minimum distance is perpendicular to the shell, but sometimes the turtle doesnt actually move enough for an intersection to occur
So instead, we'd just use the endpoint of his movement
We know if he passes the shell or not if the shells coordinate is 0 at some point

If you're still confused, I highly recommend you check out the solution on mmhs since mine is based off of theirs

I also recommend that you try simulating the rotation of axes, using 3 pencils and some objects to represent the shell

*/

#include <iostream>
#include <math.h>
#include <iomanip>

int main(){

    double turtlex, turtley, turtlez;
    std::cin >> turtlex >> turtley >> turtlez;

    double shellx, shelly, shellz;
    std::cin >> shellx >> shelly >> shellz;

    //Make turtle the origin
    shellx -= turtlex;
    shelly -= turtley;
    shellz -= turtlez;

    //Pythagorean theorem 3-D, imagine doing PT on 2-D plane to get base of triangle, then just do it again using this found base + height
    double shortest_distance = shellx * shellx + shelly * shelly + shellz * shellz;

    while (true){

        double dist;
        char dir;
        std::cin >> dist >> dir;

        double tempx = shellx - dist;

        //Turtle passes by the island
        if (shellx * tempx < 0){
            if (shelly * shelly + shellz * shellz < shortest_distance){
                shortest_distance = shelly * shelly + shellz * shellz;
            }
        }

        //Turtle does not pass the shell, use endpoints
        else{
            if (tempx * tempx + shelly * shelly + shellz * shellz < shortest_distance){
                shortest_distance = tempx * tempx + shelly * shelly + shellz * shellz;
            }
        }

        shellx = tempx;

        if (dir == 'L'){
            shellx = shelly;
            shelly = -tempx;
        }

        if (dir == 'R'){
            shellx = -shelly;
            shelly = tempx;
        }

        if (dir == 'U'){
            shellx = shellz;
            shellz = -tempx;
        }

        if (dir == 'D'){
            shellx = -shellz;
            shellz = tempx;
        }

        if (dir == 'E') break; //End of adventure

    }

    double answer = std::sqrt(shortest_distance);

    std::cout << std::fixed << std::setprecision(2) << answer;

    return 0;

}