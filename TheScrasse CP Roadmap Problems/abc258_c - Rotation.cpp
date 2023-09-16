#include <iostream>
#include <string>

/*

Imagine the string is circular, as you perform the first operation
Its like pushing the string around the circle

Therefore, just maintain a pointer to the current first element is and from there you can figure out the xth element

*/

int main (){

    int N, Q;
    std::cin >> N >> Q;
    std::string S;
    std::cin >> S;

    int front = 0;
    while (Q--){
        int type, x;
        std::cin >> type >> x;
        if (type == 1){
            front -= x;
            if (front < 0) front += N;
        }
        else{
            std::cout << S[(front + x - 1) % N] << '\n';
        }
    }

    return 0;

}