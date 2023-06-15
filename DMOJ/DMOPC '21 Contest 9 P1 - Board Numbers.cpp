#include <iostream>
#include <algorithm>

/*

a1, a2, a3

let x be the first number
the next must be a1 - x
the one after must be a2 - (a1 - x) = x - a1 + a2
the one after that must be a3 - (a2 - (a1 - x)) = (a1 - a2 + a3) - x

If we group the collections of a's together and call it c
Then there are only two polynomials
x - c
and 
c - x

if x - c, then x must be at least bigger than c, because otherwise the resulting number would be 0 and teh array requires all positive integers

if c - x, x can only be as big as c - 1, otherwise we get 0 or negative numbers

*/

int main (){
    int N;
    std::cin >> N;
    long long minimum = 1, maximum = 1LL << 62;
    long long c = 0;
    for (int i = 1; i <= N - 1; i++){
        int a;
        std::cin >> a;
        c = a - c;
        //c - x
        if (i % 2){
            maximum = std::min(maximum, c - 1);
        }
        //x - c
        else{
            minimum = std::max(minimum, -c + 1);
        }
    }
    //Take max between max - min + 1 or 0
    std::cout << std::max(maximum - minimum + 1, 0LL) << '\n';
    return 0;
}
