/*

4A - Watermelon

Difficulty: Very Easy (800)

Key realization:
Even integer + Even integer = Even integer
Therefore, the weight must be even and greater than 2 for it to be valid

*/

#include <iostream>

int main(){

    int weight;

    std::cin >> weight;

    if (weight % 2 == 0 && weight > 2){
        std::cout << "YES";
    }

    else{
        std::cout << "NO";
    }

    return 0;

}