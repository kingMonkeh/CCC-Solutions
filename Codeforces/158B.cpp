#include <iostream>
#include <algorithm>

int main(){
    int n;
    int groups [5] = {0};
    std::cin >> n;
    for (int i = 0; i < n; i++){
        int children;
        std::cin >> children;
        groups[children]++;
    }
    int cars = 0;
    cars += groups[4];
    cars += groups[3];
    groups[1] -= std::min(groups[1], groups[3]);
    //4's gone, 3's gone, 1's and 2's remain
    cars += groups[2] / 2;
    groups[2] %= 2;
    cars += groups[1] / 4;
    groups[1] %= 4;
    //Almost all 2's and 1's are gone
    if (groups[2] == 0){
        if (groups[1] > 0) cars += 1;
    }
    else{
        if (groups[1] <= 2){
            cars += 1;
        }
        else{
            cars += 2;
        }
    }
    std::cout << cars;
    return 0;
}