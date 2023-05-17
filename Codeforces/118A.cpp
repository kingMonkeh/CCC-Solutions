#include <iostream>

int main(){

    char ch;
    while (std::cin.get(ch)){
        if (ch == '\n'){
            break;
        }
        if (ch < 'a'){
            ch = ch + 32;
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y'){
            continue;
        }
        else{
            std::cout << '.' << ch;
        }
    }

    return 0;

}