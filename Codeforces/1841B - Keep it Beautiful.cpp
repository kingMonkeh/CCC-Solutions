#include <iostream>

/*

create first chunk in ascending order
Then when you encouter smaller one, it has to be smaller than front of first chunk so that you can move the first chunk behind it
Afterward just make second chunk in ascending order as well
Watch out for the fact that back of second chunk must be smaller or equal to front of first chunk

*/

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        int q;
        std::cin >> q;
        int front, back, front2, back2;
        std::cin >> front; back = front;
        std::cout << 1;
        int i;
        //chunk one
        for (i = 1; i < q; i++){
            int x;
            std::cin >> x;
            if (x >= back){
                std::cout << 1;
                back = x;
            }
            else if (x < back && x <= front){
                std::cout << 1;
                front2 = x;
                back2 = x;
                break;
            }
            else{
                std::cout << 0;
            }
        }
        //Chunk two
        for (i = i + 1; i < q; i++){
            int x;
            std::cin >> x;
            if (x >= back2 && x <= front){
                std::cout << 1;
                back2 = x;
            }
            else{
                std::cout << 0;
            }
        }
        std::cout << '\n';
    }
    return 0;
}