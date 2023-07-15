#include <bits/stdc++.h>

/*

imagine we have vampires
1 3 7 6 2
lets take index 3 and create the next stand and call it p
we now have 
1 3 7 6 2 p
lets make another stand from index 1, note that this goes from index 1 to index 6
We can break this segment into 2 segments, (1 -> 5) (6 -> 6), lets call segment (1 -> 5) as q
therefore we now have vampires
1 3 7 6 2 p p^q
lets take from index 2, same idea, we split into 2 segments, (2 -> 5) and (6 -> 7), lets call (2 -> 5) as r
we now have
1 3 7 6 2 p p^q p^p^q^r

But p^p = 0, this is a fact about the XOR operator
therefore we can simplify p^p^q^r to q^r

Notice that all these variables we use are merely XOR suffixes of the original stands
As you can guess, we maintain a suffix XOR array of the original stands

Then, we check from the range of 0 to 2^8 - 1 whether there exists a suffix that has this value
then we take XOR of the two segments and check if its greater than our current max strength stand


*/

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        
        std::vector<bool> found_prefix (1 << 8, false);
        found_prefix[0] = true;

        int strongest = 0;
        int prefix = 0;
        //Build suffix, i call it prefix due to habit
        for (int i = n - 1; i >= 0; i--){
            prefix ^= a[i];
            //Check for other possible segments to pair with, not that many due to question constraints
            for (int j = 0; j < (1 << 8); j++){
                if (found_prefix[j]) strongest = std::max(strongest, prefix ^ j);
            }
            found_prefix[prefix] = true;
        }

        std::cout << strongest << '\n';
        
    }
    
    return 0;
    
}