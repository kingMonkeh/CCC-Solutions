#include <iostream>

int main(){
    int H, S, Q;
    std::cin >> H >> S >> Q;
    for (int i = 1; i <= Q; i++){
        std::cout << H - S * i << '\n';
    }
    return 0;
}