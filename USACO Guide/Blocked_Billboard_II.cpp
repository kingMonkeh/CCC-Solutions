#include <cstdio>
#include <iostream>

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2; //Lawnmower
    int x3, y3, x4, y4; //Bessie
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    //Bessie completely covers the lawnmover sign
    if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2){
        std::cout << 0;
    }
    else if (x3 <= x1 && x4 >= x2){
        //Cut off top
        if (y4 >= y2 && y3 <= y2 && y3 >= y1){
            std::cout << (y3 - y1) * (x2 - x1);
        }
        //Cut off bottom
        else if (y3 <= y1 && y4 >= y1 && y4 <= y2){
            std::cout << (y2 - y4) * (x2 - x1);
        }
        else{
            std::cout << (x2 - x1) * (y2 - y1);
        }
    }
    else if (y3 <= y1 && y4 >= y2){
        //Cut off left
        if (x3 <= x1 && x4 >= x1 && x4 <= x2){
            std::cout << (x2 - x4) * (y2 - y1);
        }
        //Cut off right
        else if (x3 <= x2 && x3 >= x1 && x4 >= x2){
            std::cout << (x3 - x1) * (y2 - y1);
        }
        else{
            std::cout << (x2 - x1) * (y2 - y1);
        }
    }
    //corner
    else{
        std::cout << (x2 - x1) * (y2 - y1);
    }
    return 0;
}