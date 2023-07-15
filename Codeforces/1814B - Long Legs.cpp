#include <bits/stdc++.h>

/*

let m be the final step length of the robot

We notice that given a distance a, the total number of moves is a/m
Note that if a % m != 0, there will be a remainder.
This can be avoided by the nature of the problem

Imagine we want to travel to 10, but we have m = 4
4 -> 8 -> 12
We overshot
But recall that as we were increasing our leg length, 1->2->3->4
It had length 2 at some point
Therefore, we could have done m = 1->2
Move to 2, then increase m = 4
2 6 10, therefore we can say the the total moves required is the ceil(a / m)

To translate this idea to a 2d grid,
We can apply this formula to both the vertical and horizontal aspects

*/

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        double x, y;
        std::cin >> x >> y;
        int ans = x + y;
        for (int m = 1; m <= 100000; m++){
            int xclicks = ceil(x / m); //moves to match x
            int yclicks = ceil(y / m); //moves to reach y
            //combine the two prev variables + m - 1 clicks to increase our leg length
            ans = std::min(ans, xclicks + yclicks + (m - 1));
        }
        std::cout << ans << '\n';
    }
}