#include <bits/stdc++.h>

/*

Greedy solution:
We want to choose the digit that will bring us furthest right
As this decreases the total amount of characters left that could form a subsequence
Ultimately increasing our chances of finding the correct password

*/

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::string s, l, r;
        int m;
        std::cin >> s >> m >> l >> r;
        int len = s.length();
        //For each digit
        int pos = -1;
        for (int i = 0; i < m; i++){
            int best = pos; //Keeps track of index achieved that is furthest to the right
            //For each valid number
            for (char c = l[i]; c <= r[i]; c++){
                int found = len; //pretend as if this digit does not exist in the database
                for (int j = pos + 1; j < len; j++){
                    //In the event we do find it
                    if (s[j] == c){
                        found = j; //First occurence of digit
                        break;
                    }
                }
                best = std::max(best, found); //Update best position, aka one the brings us furthest right
            }
            pos = best; //Update new pos as the index that is furthest right out of all digits
        }
        //Did we make it to end?
        std::cout << (pos == len ? "YES\n" : "NO\n");
    }
}