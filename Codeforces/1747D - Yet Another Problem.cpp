/*

Key things to note

We notice that once we perform a XOR operation a certain segment of the array,
If we repeat this XOR again, nothing will change, you can try this out yourself

Not only this, but no matter the number of operations or the way you perform them
At the end, if you take the XOR of all the elements of the subarray
It will always just equal to XOR of the entire subarray

Therefore, if the XOR of the elements of the array is not equal to 0
Its guranteed to not be possible to make them all 0

Lets assume the XOR of the segment is 0, meaning theres a chance its possible
if the size of the segment is odd, we can just choose the entire segment and finish in 1 operation

If its even sized, things get slightly more complex
We just have to split the even sized segment into 2 smaller odd sized segments
where the XOR of each of the smaller segments is 0

Special cases:
All elements are zero, you don't need to do anything, output zero

let n = size of segment
Segment is evenly sized, and either the a[1] or a[n] == 1
Here, we can split into 2 segments size 1 and n - 1
Since one of the segments is zero, just operate on the other only, 1 move

*/

#include <bits/stdc++.h>

int main(){

    //Fast I/O is heavily recommended as to not TLE
    std::ios_base::sync_with_stdio(false);
    
    int n, q;
    std::cin >> n >> q;

    std::map<int, int> odd, even; //odd[prefixXOR] = last odd index which had this prefixXOR, same idea for even with even indices
    std::vector<int> prefixXOR (n + 1, 0), last_nonzero (n + 1, 0), last (n + 1, -1);
    std::vector<int> a (n + 1);
    int prefXOR = 0;
    even[0] = 0;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        //PrefixXOR may be a bit confusing as to how it would work
        //Essentially we notice that prefix[l] and pref[r] both share the XOR of all element a[l - 1], a[l - 2], ... a[0]
        //therefore if pref[l] == pref[r], then the XOR of that segment must be 0
        //since initially we started with the XOR of all the previous elements, and after XORing all the new elements of the segment
        //they all cancelled each other out and nothing changed, hence XOR[l, r] = 0
        prefXOR ^= a[i];
        prefixXOR[i] = prefXOR;
        //Mark index of last non zero number considering all number from index 1 --> i
        if (a[i] == 0){
            last_nonzero[i] = last_nonzero[i - 1];
        }
        else{
            last_nonzero[i] = i;
        }
        //Find index of last occurence of this prefix in the array 
        //view i as the right end of the entire segment that we will be splitting
        //If odd
        if (i % 2){
            //Note that when we split a segment into 2 odd sized segments
            //The initial segment must end at an even index since odd + even = odd
            if (even.count(prefXOR)){
                last[i] = even[prefXOR];
            }
            odd[prefXOR] = i;
        }
        else{
            //Note that when we split a segment into 2 odd sized segments
            //The initial segment must end at an odd index since odd + odd = even
            if (odd.count(prefXOR)){
                last[i] = odd[prefXOR];
            }
            even[prefXOR] = i;
        }
    }

    while (q--){
        int l, r;
        std::cin >> l >> r;
        //Cant obtain 0 after full XOR
        if (prefixXOR[l - 1] != prefixXOR[r]){
            std::cout << -1 << '\n';
        }
        //All elements are 0
        else if (last_nonzero[r] < l){
            std::cout << 0 << '\n';
        }
        //Odd sized segments, aka l and r share the same parity
        else if (l % 2 == r % 2){
            std::cout << 1 << '\n';
        }
        //We split into a segment of size 1, and the other is the remaining size
        //The size 1 segment is already 0, hence we only need to operate on the other segment
        else if (a[l] == 0 || a[r] == 0){
            std::cout << 1 << '\n';
        }
        //There exists a point which we should split the evenly sized array such that both smaller odd sized segments can XOR to 0
        else if (last[r] >= l){
            std::cout << 2 << '\n';
        }
        //Not possible otherwise
        else{
            std::cout << -1 << '\n';
        }
    }
    
    return 0;
    
}