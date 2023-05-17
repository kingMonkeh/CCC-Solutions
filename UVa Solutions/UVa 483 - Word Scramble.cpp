#include <bits/stdc++.h>

int main() {
    
    char ch;
    std::string word = "";
    while (std::cin.get(ch)){
        if (ch == ' ' || ch == '\n'){
            for (int i = word.length() - 1; i >= 0; i--){
                std::cout << word[i];
            }
            std::cout << ch;
            word = "";
        }
        else{
            word += ch;
        }
    }
    
    return 0;
    
}