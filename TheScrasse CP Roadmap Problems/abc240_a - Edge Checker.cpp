#include <iostream>

int main (){

    int a, b;
    std::cin >> a >> b;
    
    std::cout << (abs(a - b) == 1 || abs(a - b) == 9 ? "Yes" : "No");

    return 0;

}