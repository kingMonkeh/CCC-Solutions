#include <bits/stdc++.h>

/*

Start from m
Greedy intuition:
Notice that doubling n covers a lot more distance than just subtracting by 1
Therefore we want to minimize how much subtraction we do

start from m
if m is odd, you cant divide by 2, so add 1
then keep dividing until its less than n
now you just have to decrement n by however much and just keep multiplying

*/

int main (){
    int n, m;
    std::cin >> n >> m;
    if (n >= m) std::cout << n - m << '\n';
    else{
        int clicks = 0;
        while (m > n){
            if (m % 2 == 1){
                m++;
                clicks++;
            }
            m /= 2;
            clicks++;
        }
        clicks += n - m;
        std::cout << clicks << '\n';
    }
}