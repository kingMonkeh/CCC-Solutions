#include <iostream>

int main(){

    int t;
    std::cin >> t;

    while(t--){

        int x, y;
        std::cin >> x >> y;

        if (x == 1 || y == 1){
            std::cout << 1 << '\n' << x << ' ' << y << '\n';
            continue;
        }

        std::cout << 2 << '\n';
        std::cout << x - 1 << ' ' << 1 << '\n';
        std::cout << x << ' ' << y << '\n';

    }

    return 0;

}