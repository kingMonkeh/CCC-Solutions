/*

MOCK CCC 2023 S1 - Composite Fibonacci Numbers

Difficulty: Medium

Topics: String Manipulation

This question is much more difficult than what a regular S1 would actually be on the real CCC, still though it was fine.
For this problem since the numbers can only be up to 100000, you can recursively try every combination of numbers and check if they're all fibonacci numbers.

Things to keep in mind that caused me to get wrong answer.
Remeber that composite fibonacci numbers must be the concatation of 2 OR MORE fibonacci numbers, meaning 89, although a fibonacci number, is not a composite fibonacci number since it cannot be made up of 2 or more fibonacci numbers.
Remember that you can reuse fibonacci numbers infinitely, meaning 11111 is a valid number

As you're recursing, watch out for going out of bounds and remember to revert changes if necessary.

For generating the fibonacci sequence, you can also just write a recursive function.

*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> fibonacciseq {"0", "1", "1", "2", "3", "5", "8", "13", "21", "34", "55", "89", "144", "233", "377", "610", "987", "1597", "2584", "4181", "6765", "10946", "17711", "28657", "46368", "75025"};
std::string N; //Stores number N

//Recursive function to check if composite fibonacci
bool composite_fibonacci(int left = 0, std::string num = ""){

    std::string substr = ""; //Storing the substring of this recurse, I'm going to be checking part by part of the number
    int copy = left; //To revert changes later on

    for (int i = 0; i < N.length() - left; i++){

        //Add to string
        num += N[left + i]; //Used to know if I've reached the end of the number
        substr += N[left + i];

        //Check if substring is a fibonacci number
        for (auto it = fibonacciseq.begin(); it != fibonacciseq.end(); it++){

            //If it is
            if (substr == *it){

                //If I've reached the end of the entire number and the substring is valid as well, then this number is a composite fibonacci number
                //Left > 0 because of special cases like 89
                if (num.length() == N.length() && left > 0){
                    return true;
                }

                left = num.length(); //Update left for next recurse, left just stands for what index I'm at in the number

                //Recurse
                if (composite_fibonacci(left, num)){
                    return true;
                }

                left = copy; //Undo change and move on to the next iteration

            }

        }

    }

    //If no combination of fibonacci numbers is found
    return false;

}

int main(){

    int T;

    std::cin >> T;

    for (int i = 0; i < T; i++){
        
        std::cin >> N;

        //Length 1 doesn't count
        if (composite_fibonacci() && N.length() > 1){
            std::cout << "YES" << std::endl;
        }
        
        else{
            std::cout << "NO" << std::endl;
        }
        
    }

    return 0;

}