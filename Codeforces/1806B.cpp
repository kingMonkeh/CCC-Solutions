/*
Basically ans can only be 0, 1, or 2
Try making it 0, for it to be 0, you need to able to surround every 0
aka, 0 must be less than or equal to n / 2

If there's too many zeros, try making mex 1
To do this, you basically just shove all the zeros to the left, this ensures 0 will be in the set
Then after, you just search for any element greater than 1, to seperate the 0's from the 1's

EDGE CASE: whole array is just 0, mex = 1, no need for seperator

If this isn't possible, then the array is just a bunch of 0's and 1's
Meaning the answer must be 2

*/

#include <iostream>

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        int total0 = 0;
        bool bigNum = false;
        for (int i = 0; i < n; i++){
            int a;
            std::cin >> a;
            if (a == 0){
                total0++;
            }
            if (a >= 2){
                bigNum = true;
            }
        }
        if (total0 <= (n + 1) / 2){
            std::cout << 0 << '\n';
        }
        //There exists a seperator element or all of the array is 0
        else if (bigNum || total0 == n){
            std::cout << 1 << '\n';
        }
        else{
            std::cout << 2 << '\n';
        }
    }
    return 0;
}