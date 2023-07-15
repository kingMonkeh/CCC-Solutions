#include <bits/stdc++.h>

/*

Idea:

imagine we have p
a b c d e f g h i j k

if we choose to flip a segment, lets say [4, 5]
we get 
f g h i j k, e d, a b c

we notice that we should try to maximize the first element of the new permutation
therefore we will start out by finding a value of r such that when we create a segment with r
the resulting flipped segements will leave the max possible value for our beginning

now that we know the segment f g h i j k has been maximized lets focus on e d a b c

In determining a value of l is pretty simple

we notice that as we stretch our segment, the segment taht will come after it will be p[0]

[5, 5]
e a b c d
[4, 5]
e d a b c
[3, 5]
e d c a b
[2 , 5]
e d c b a
[1, 5]
e d c b a

tehrefore we only want to stretch our segment or increase l when p[l] > p[0]

*/

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;

        std::vector<int> p (n);
        for (int i = 0; i < n; i++){
            std::cin >> p[i];
        }

        int r = 0;
        for (int i = 0; i < n; i++){
            if (p[std::min(n - 1, r + 1)] <= p[std::min(n - 1, i + 1)]){
                r = i;
            }
        }
        
        for (int i = r + 1; i < n; i++){
            std::cout << p[i] << ' ';
        }

        std::cout << p[r] << ' ';
        for (int l = r - 1; l >= 0; l--){
            if (p[l] > p[0]) std::cout << p[l] << ' ';
            else{
                for (int i = 0; i <= l; i++) std::cout << p[i] << ' ';
                break;
            }
        }

        std::cout << '\n';
        
    }

    return 0;
    
}