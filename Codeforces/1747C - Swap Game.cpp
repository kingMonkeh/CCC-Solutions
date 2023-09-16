/*

Thought process:

What is the optimal strategy for both players?
To reduce any term in the array to 0, as fast as possible and then hand it to the other player

What the best term to pick if our goal is to reduce it as fast as possible?
the minimum element of course

we notice that if the element is not the first element
then Alice is guranteed to win, since she always has control of this element, and bob cannot make any other element go down faster

let m = min, let A = alice and B = bob

A: a1 a2 a3 m a4
B: m a2 a3 a1 - 1 a4
A: a2 m - 1 a3 a1 - 1 a4
B: m - 1 a2 - 1 a3 a1 - 1 a4

We notice that Bob never gets the change to give the min element to Alice, which means that he's always forced to decrease it
At some point, the min element will reach 0 and Alice will hand it back to him causing Bob to lose

What if the min element is the first element?
A: m a2 a3 a4 a5
B: a2 m - 1 a3 a4 a5
A: m - 1 a2 a3 a4 a5
B: a4 a2 a3 m - 2 a5

Here we see that Bob now has complete control of the min element and that Alice is always forced to decrease it if Bob plays optimally

therefore if we sort a[2] --> a[n]
if a[1] > a[2], Alice wins
else Bob wins

*/

#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::sort(a.begin() + 1, a.end());
        std::cout << (a[0] > a[1] ? "Alice\n" : "Bob\n");
        
    }
    
    return 0;
    
}