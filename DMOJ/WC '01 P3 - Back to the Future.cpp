/*

Implementation
Just convert it to binary
Reverse it,
Convert back to base 10

*/

#include <iostream>
#include <string>

int main(){
    int T;
    std::cin >> T;
    while (T--){
        int X;
        std::cin >> X;
        if (X == 0){
            std::cout << "0\n";
            continue;
        }
        std::string binary = "";
        while (X > 0){
            binary += char ((X % 2) + 48);
            X /= 2;
        }
        int power = 1, base10 = 0;
        for (int i = binary.length() - 1; i >= 0; i--){
            base10 += (binary[i] - '0') * power;
            power *= 2;
        }
        std::cout << base10 << '\n';
    }
    return 0;
}