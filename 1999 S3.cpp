/*

1999 S3 - Divided Fractals

Difficulty: Easy

For this problem, since there will be at max 5 iterations. You can just generate the actual fractal using recursion and print out the required rows and columns.

Watch out for extra white space and missing new lines that might cause presentation error.

*/

#include <iostream>
#include <vector>

std::vector<std::vector<char>> fractal {{'*'}}; //Base is just a 3^0 * 3^0 grid.

//What this does is create the next iteration.
void iterate(){

    int l = fractal.size(); //Keep track of original fractal size, updated fractal will be 3 times larger
    std::vector<std::vector<char>> fractal_copy = fractal; //Make a copy of the fractal since the bigger fractal is made up of 8 copies of the original
    fractal.clear(); //Clear the original fractal
    fractal.resize(l * 3, std::vector<char> (l * 3)); //Resize it accordingly

    //Fill the new fractal with 9 copies of the original
    for (int i = 0; i < l * 3; i++){

        for (int j = 0; j < l * 3; j++){

           fractal[i][j] = fractal_copy[i % l][j % l];

        }

    }

    //Delete the middle portion
    for (int i = l; i < l * 2; i++){

        for (int j = l; j < l * 2; j++){

            fractal[i][j] = ' ';

        }

    }

}

int main(){

    int d;
    std::cin >> d;

    //For each case
    for (int i = 0; i < d; i++){

        int n; std::cin >> n;

        //Iterate however many times needed
        for (int j = 0; j < n; j++){

            iterate();

        }

        int b, t, l, r;
        std::cin >> b >> t >> l >> r;

        //Print out rows and columns, remember that rows are inputted from bottom up
        for (int j = fractal.size() - t; j < fractal.size() - b + 1; j++){

            //Stop before r - 1, aka the last element in the row because we don't want to output an additonal space
            for (int c = l - 1; c < r - 1; c++){

                std::cout << fractal[j][c] << ' ';

            }
          
            std::cout << fractal[j][r - 1]; //Output value without the extra space
            std::cout << '\n'; //Newline

        }
      
        std::cout << '\n'; //Output a new line after each case

        fractal.clear(); //Clear the fractal
        fractal = {{'*'}}; //Reset it for the next case

    }

    return 0;

}