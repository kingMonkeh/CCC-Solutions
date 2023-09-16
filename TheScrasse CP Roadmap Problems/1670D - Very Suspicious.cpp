#include <bits/stdc++.h>

/*

we notice there are only 3 line orientations
lets call them x y z

We notice that the total triangles 
= 2(xy + yz + xz)

(when any pair of lines intersect, they form 2 triangles)

total times they intersect is # of lines type 1 * # of lines type 2, repeat for all 3

therefore we want to minimize x + y + z
we notice that to accomplish this, we should try keeping their values as close as possible
imagine when factoring a number and the sums of factor pairs, its most optimal at approximately the sqrt(n)

Therefore, rearranging we can get a number close to the answer by doing ceil(sqrt(n / 6)), since 3 pairs, n / 2 / 3 = n / 6
sqrt since we just realized its optimal

from there, we can make minor adjustments to try to further optimize

*/

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;

        int x [3];
        for (int i = 0; i < 3; i++) x[i] = ceil(sqrt((double) n / 6));

        int i = 0;
        //not enough, add more lines
        if (2 * (x[0] * x[1] + x[1] * x[2] + x[0] * x[2]) < n){
            while (2 * (x[0] * x[1] + x[1] * x[2] + x[0] * x[2]) < n){
                x[i]++;
                i++; i %= 3;
            }
        }
        //greater than, try seeing if we can reduce the lines
        else if (2 * (x[0] * x[1] + x[1] * x[2] + x[0] * x[2]) > n){
            while (2 * (x[0] * x[1] + x[1] * x[2] + x[0] * x[2]) > n){
                x[i]--;
                if (2 * (x[0] * x[1] + x[1] * x[2] + x[0] * x[2]) < n){
                    x[i]++;
                    break;
                }
                i++; i %= 3;
            }
        }

        std::cout << x[0] + x[1] + x[2] << '\n';
        
    }
    
    return 0;
    
}