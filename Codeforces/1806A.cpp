#include <iostream>

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (y2 < y1){
            std::cout << -1 << '\n';
            continue;
        }
        if (x2 > x1){
            if (y1 + (x2 - x1) > y2){
                std::cout << -1 << '\n';
                continue;
            }
        }
        int right = x1 + y2 - y1;
        int left = abs(right - x2);
        std::cout << y2 - y1 + left << '\n';
    }
    return 0;
}