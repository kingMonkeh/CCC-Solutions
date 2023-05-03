/*

2002 S5 - Follow the Bouncing Ball
Difficulty: Hard

The idea is a bit strange,
Essentially you have to continue/project of the first bounce (between the bottom wall and the right wall)
Using a shit ton of trigonometry to prove, you will notice that regardless of how many bounces
Or whatever direction the ball is heading, the change in y for a given x is always the same, regardless.

That is why projecting the line works in this problem, therefore calculate slope and b
Afterward, we will read this line
This line is telling us that after travelling x units horizontally, the ball's total change is y units, not taking account vertical direction

Therefore, we will find values of y using values of x that are multiples of the width of the box
Since these x values are telling us that we are either on the left side or right wall of the box
And the y value would tell us the total rise if we collided with the left or right wall

We will repeat the same process, but substitue values of y that are multiples of the height of the box, and solve for x
This will tell us the total horizontal displacement, after we've either hit the bottom wall, or the top wall

By using modulus, we can determine their actual position on the box, if either is < 5 or (height or width) - actual pos < 5
Then this has hit the corner

Note there's a special edge case in which it directly hits the corner, in which case we will not subtract 1 (you will understand after reading code)

*/

#include <iostream>
#include <math.h>

int main(){

    long double width, height, init, bounce1;
    std::cin >> width >> height >> init >> bounce1;
    long double slope = (bounce1) / (width - init); //Get slope
    long double b = -slope * init; //Get b

    int bounces;

    //i is essentially representing ith multiple of width or height    
    for (int i = 1; i < 1000000; i++){

        long double y = slope * (i * width) + b; //Find total y after traveling width * i distance
        long double x = ((i * height) - b) / slope; //Find total x after travelling height * i distance

        //NOTE: y AND x ARE NOT RELATED IN ANY WAY WHATSOEVER, THEY ARE COMPLETELY INDEPENDENT OF EACH OTHER
        //THEY ARE REPRESENTING 2 COMPLETELY DIFFERENT SCENARIOS

        //Really weird way of doing modulus, you probably could just do modulus, idk why I did this
        long double heights = std::floor(y / height);
        long double widths = std::floor(x / width);

        //Their actual positions, remember these 2 values are not related to one another
        long double actualHeight = y - height * heights;
        long double actualWidth = x - width * widths;
        
        //If we hit the corners of either the left wall or the right
        if (actualHeight < 5 || height - actualHeight < 5){
            //If it did not directly hit corner
            if (height * heights != y){
                //bounces = total times we hit the left and right walls - 1 (because first bounce doesn't count) + total y traversed / height (number of time we hit top and bottom walls)
                bounces = i - 1 + (y / height);
            }
            //If it directly hit corner
            else{
                bounces = i - 1 + (y / height) - 1; //Same logic, but -1 again since we've counted an extra bounce from y/height, which shouldn't be there
            }

            std::cout << bounces;
            return 0;
            
        }

        //If we hit corners of either top or bottom wall
        if (actualWidth < 5 || width - actualWidth < 5){
            //Didn't directly hit corner
            if (width * widths != x){
                //total times we hit top and bottom - 1 + total times we hit left and right walls
                bounces = i - 1 + (x / width);
            }
            //Hit corner
            else{
                bounces = i - 1 + (x / width) - 1;
            }

            std::cout << bounces;
            return 0;
            
        }
        
    }

    std::cout << 0;
    return 0;
    
}