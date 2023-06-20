/*

Matrix exponentiation go crazy
UNSIGNED LONG LONG IS IMPORTANT

https://usaco.guide/plat/matrix-expo?lang=cpp
very useful guide

*/

#include <iostream>
#include <array>

using matrix = std::array<std::array<unsigned long long, 2>, 2>;

matrix multiply (matrix a, matrix b){   
    matrix ret;
    ret[0][0] = ((a[0][0] * b[0][0]) % 1000000007 + (a[0][1] * b[1][0]) % 1000000007) % 1000000007;
    ret[0][1] = ((a[0][0] * b[0][1]) % 1000000007 + (a[0][1] * b[1][1]) % 1000000007) % 1000000007;
    ret[1][0] = (((a[1][0] * b[0][0]) % 1000000007) + (a[1][1] * b[1][0]) % 1000000007) % 1000000007;
    ret[1][1] = (((a[1][0] * b[0][1]) % 1000000007) + (a[1][1] * b[1][1]) % 1000000007) % 1000000007;
    return ret;
}

int main(){
    unsigned long long N;
    std::cin >> N;
    matrix thing = {{{1, 1}, {1, 0}}};
    matrix answer = {{{1, 0}, {0, 1}}};
    //((2)^2) * 2^1, reason for the N % 2 thing, binary exponentiation, faster exponents
    for (; N > 0; N /= 2, thing = multiply(thing, thing)){
        if (N % 2){
            answer = multiply(answer, thing);
        }
    }
    std::cout << answer[0][1];
    return 0;
}