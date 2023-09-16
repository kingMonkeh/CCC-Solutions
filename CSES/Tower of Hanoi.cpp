#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

void move (int n, int from, int to, int via){

    if (n == 0) return;

    //to move the current disc, we need to get the current pile on top off of it
    move (n - 1, from, via, to);
    std::cout << from << ' ' << to << '\n';
    //once the above tower has been moved, we just continue based off of it
    move (n - 1, via, to, from);
    
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;
        
        std::cout << pow(2, n) - 1 << '\n';

        move (n, 1, 3, 2);
        
    }

    return 0;
    
}