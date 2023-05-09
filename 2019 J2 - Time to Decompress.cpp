/*

Literaly just implement it, no theory involved
This just tests if you know how to use a loop

*/

#include <iostream>

int main(){

    int L;
    std::cin >> L;

    while (L--){
        int number;
        char letter;
        std::cin >> number >> letter;
        while (number--){
            std::cout << letter;
        }
        std::cout << '\n';
    }
    
    return 0;
    
}