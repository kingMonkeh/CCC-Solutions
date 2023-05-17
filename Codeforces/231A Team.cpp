#include <iostream>

int main(){

    int n;
    std::cin >> n;

    int total{0};
    while (n--){
        int p, v, t;
        std::cin >> p >> v >> t;
        if (p + v + t >= 2){
            total++;
        }
    }

    std::cout << total << '\n';

    return 0;

}