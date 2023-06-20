#include <iostream>
#include <string>

std::string codeforces = "codeforces";

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::string s;
        std::cin >> s;
        int counter = 0;
        for (int i = 0; i < 10; i++){
            if (s[i] != codeforces[i]){
                counter++;
            }
        }
        std::cout << counter << '\n';
    }
    return 0;
}