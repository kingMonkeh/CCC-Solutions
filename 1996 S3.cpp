/*

1996 S3 - Pattern Generator

Difficulty: Easy

For this problem, there's 2 main ways of solving it.

You either make use of the trick or you solve it via recursion. This file contains the trick, the other file contains the recursion solution.

The trick is simple, to generate all bit patterns.
Find the last occurence of the substring "10", swap them and the for the right side of the string from the substring "10", reverse it.

For example, imagine you start with 1001.

Last occurence of "10" is at the start. So you swap them.

Now you have 0101, this isn't completely correct yet, since now we need to reverse the right side after the "10" we had swapped.

Reversing the right side, we get 0110, which is correct.

*/

#include <iostream>
#include <string>

int main(){

    int numOfTests;
    std::cin >> numOfTests;

    for (int i = 0; i < numOfTests; i++){

        std::string pattern = ""; //Start with blank
        int n, k;

        std::cin >> n >> k;

        //Initialize the beginning string, we will use the trick afterward to obtain all other strings
        for (int j = 0; j < k; j++){
            pattern += '1';
        }

        for (int j = k; j < n; j++){
            pattern += '0';
        }

        std::cout << "The bit patterns are" << '\n' << pattern << '\n'; //Print first pattern

        while (true){

            std::size_t onezero = pattern.rfind("10"); //Position of substring "10"

            //If no occurence of "10"
            if (onezero == std::string::npos){
                break;
            }

            //Swap characters
            char backup = pattern[onezero];
            pattern[onezero] = pattern[onezero + 1];
            pattern[onezero + 1] = backup;

            //Find right side
            std::string right_side = pattern.substr(onezero + 2, n - onezero + 2);
            std::string right_side_reversed;

            //Reverse right side
            for (auto r_it = right_side.rbegin(); r_it != right_side.rend(); r_it++){
                right_side_reversed += *r_it;
            }

            //Remove old right side and add the reversed one
            pattern.erase(pattern.begin() + onezero + 2, pattern.end());
            pattern += right_side_reversed;

            //Print out the pattern
            std::cout << pattern << '\n';

        }

        //To avoid presentation error, only print out new line on all cases except for the last
        if (i < numOfTests - 1){
            std::cout << '\n';
        }
        
    }

    return 0;

}