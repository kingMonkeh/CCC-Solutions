#include <iostream>

/*

If n <= 4, Alice cannot win, you can just try all outcomes

Else
Imagine 1 1 1 1 1
Alice can just take the first 3 1's
3 1 1
Meaning Bob can only merge the two 1's
3 2
Alice always wins, since n >= 4, therefore the initial 1's she merges will always be greater than 2

*/

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        if (n <= 4){
            std::cout << "Bob\n";
        }
        else{
            std::cout << "Alice\n";
        }
    }
    return 0;
}