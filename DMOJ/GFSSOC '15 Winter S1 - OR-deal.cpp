/*

Think about the OR operator
You only need a single 1, for it to be 1 forever after all the operations
Since you're going from 1 -> N
Every digit in base 2, would have been covered
Therefore, everything should be 1

*/

#include <iostream>
#include <math.h>

int main(){
    long long N;
    std::cin >> N;
    for (int i = 0; i <= log2(N); i++){
        std::cout << 1;
    }
    return 0;
}