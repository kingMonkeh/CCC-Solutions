#include <iostream>

int main (){

    int a, b, c;
    std::cin >> a >> b >> c;

    bool ans = false;
    int n;
    for (int i = a; i <= b; i++){
        if (i % c == 0){
            ans = true;
            n = i;
        }
    }

    std::cout << (ans ? n : -1) << '\n';
    

    return 0;

}