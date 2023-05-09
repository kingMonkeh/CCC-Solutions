/*
... just do it
if you struggle on this, i recommend learning how to program first
there's no theory involved, just basic knowledge of programming
*/

#include <iostream>

int main(){
    int first, second, third, fourth;
    std::cin >> first >> second >> third >> fourth;
    if ((first == 8 || first == 9) && second == third && (fourth == 8 || fourth == 9)){
        std::cout << "ignore";
    }
    else{
        std::cout << "answer";
    }
    return 0;
}