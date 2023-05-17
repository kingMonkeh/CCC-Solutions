#include <iostream>
#include <string> 

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::string word;
        std::cin >> word;
        if (word.length() > 10){
            std::cout << word[0] << word.length() - 2 << word[word.length() - 1] << '\n';
        }
        else{
            std::cout << word << '\n';
        }
    }
    return 0;
}