#include <bits/stdc++.h>

/*

for any two a values

for all the bit position in which they are not the same
there exists no x value that will be capable of turning them on

lets say a[i] = 1, a[j] = 0 and x = 1
x ^ a[i] = 0, x ^ a[j] = 1;

lets say a[i] = 1, a[j] = 0, and x = 0
x ^ a[i] = 1, x ^ a[j] = 0

we see that
if we want a bit to be one in our final answer after we &
we need the bit positions in each a[i] and a[j] to both be the same

therefore
we sort increasing order

we notice that by doing so
adjacent a values will have a common prefix of bits

by taking a[i] ^ a[j]
we know the total value of bits that we cannot activate in our final answer
therefore our goal is to minimize a[i] ^ a[j]

*/

struct martian{

    int a, pos;
    bool operator <(martian& x){
        return this->a < x.a;
    }

};

int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {
 
        int n, k;
        std::cin >> n >> k;
        std::vector<martian> a (n);
        for (int i = 0; i < n; i++){
            std::cin >> a[i].a;
            a[i].pos = i;
        }

        std::sort(a.begin(), a.end());

        int minans = INT_MAX;
        int ind;
        for (int i = 0; i < n - 1; i++){
            if ((a[i].a ^ a[i + 1].a) < minans){
                minans = a[i].a ^ a[i + 1].a;
                ind = i;
            }
        }

        std::cout << a[ind].pos + 1 << ' ' << a[ind + 1].pos + 1 << ' ' << (1 << k) - 1 - a[ind].a << '\n'; 

    }
 
    return 0;
    
}