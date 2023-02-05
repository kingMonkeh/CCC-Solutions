/*

1996 S3 - Pattern Generator

This is the recursive solution. Essentially, you add 1's first and 0's after in your recurse.

*/

#include <iostream>
#include <string>

std::string pattern;
int n, k;

//Generate all patterns in descending order. It's very important that you attempt to add 1's first before 0's or else the answer will not be in descending order
//onesRemaining is quite evident, next is the character to be added to the pattern
void generate(int onesRemaining, char next){

    pattern += next; //Update pattern

    //If pattern is complete, print out
    if (pattern.length() == n){
        std::cout << pattern << '\n';
    }

    //If you can still add 1's to the pattern
    if (onesRemaining > 0){
        std::string backup = pattern;
        generate(onesRemaining - 1, '1');
        pattern = backup;
    }

    //If we want to add a zero, we have to make sure that there's still enough room left in the pattern to add the remaining ones.
    if (n - pattern.length() > onesRemaining){
        std::string backup = pattern; //To undo changes afterward
        generate(onesRemaining, '0');
        pattern = backup;
    }
    

}

int main(){

    int numOfTests;
    std::cin >> numOfTests;

    for (int i = 0; i < numOfTests; i++){

        std::cin >> n >> k;

        std::cout << "The bit patterns are" << '\n';

        //If there are ones, since if there is zero 1's, we shouldn't be adding them
        if (k > 0){
            pattern = "";

            generate(k - 1, '1');
        }

        //In the case that the amount of 1's is equal to the length, we shouldn't add 0's
        if (n > k){
            pattern = "";

            generate(k, '0');
        }
        
        //Formatting purpose, avoid presentation error
        if (i < numOfTests - 1){
            std::cout << '\n';
        }

    }

    return 0;

}