#include <iostream>
#include <vector>

int main(){
    int N; // # of stations
    int W; // # of walkways
    int D; // # of days

    std::cin >> N;
    std::cin >> W;
    std::cin >> D;

    //Collect walkway inputs
    int walkway_start[W];
    int walkway_stop[W];

    for (int i = 0; i < W; i++){
        std::cin >> walkway_start[i];
        std::cin >> walkway_stop[i];
    }

    //Test Print
    for (int i = 0; i < W; i++){
        std::cout << walkway_start[i] << " " << walkway_stop[i] << '\n';

    }

    return 0;

}

