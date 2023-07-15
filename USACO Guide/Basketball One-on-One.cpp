#include <iostream>
#include <string>

int main (){
    std::string games;
    std::cin >> games;
    std::cout << games[games.length() - 2];
    return 0;
}