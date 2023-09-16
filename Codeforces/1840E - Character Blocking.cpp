/*

idea:

lets keep a vector that keeps track whether the characters at index i are matching

notice that when we block a character or swap characters
only the characters affected have a chance at changing whetehr or not theyre matching
all the other characters will remain the same

therefore we will just keep track of how many characters are matching at a given moment
and how many are not matching at a given moment

if the # of non matching characters == 0, then the strings are matching

blocking a character is pretty simple
if the characters blocked were matching, matching--
else not_matching--

swap characters will only affect the two indices
if the chars at pos1 were matching, matching--
else not_matching--
same thing for pos2

then we will swap the characters
and check specifically if those characters are not matching or not
and update matching and not_matching accordingly

initializing the matching array will take O(n) time, and all queries can be answered in O(1) time

*/

#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        std::string s [2];
        std::cin >> s[0] >> s[1];
        int t, q;
        std::cin >> t >> q;

        //initial array creation
        int matching = 0, not_matching = 0;
        std::vector<bool> match (s[0].size());
        for (int i = 0; i < (int) s[0].length(); i++){
            if (s[0][i] == s[1][i]){
                matching++;
                match[i] = true;
            } 
            else{
                not_matching++;
                match[i] = false;
            }
        }

        std::queue<std::pair<int, bool>> blocked; //keep track of when the character blocking will come off
        for (int i = 0; i < q; i++){

            //Check if blocking has expired
            if (!blocked.empty() && blocked.front().first == i){
                std::pair<int, bool> cur = blocked.front();
                blocked.pop();
                if (cur.second){
                    matching++;
                }
                else{
                    not_matching++;
                }
            }
                
            int query_type;
            std::cin >> query_type;

            //create blocking
            if (query_type == 1){
                int pos;
                std::cin >> pos;
                pos--;
                blocked.push({i + t, match[pos]}); //{time it will come off, whether was matching or not}
                if (match[pos]){
                    matching--;
                }
                else{
                    not_matching--;
                }
            }

            //swap
            else if (query_type == 2){
                int i1, pos1, i2, pos2;
                std::cin >> i1 >> pos1 >> i2 >> pos2;
                i1--; pos1--; i2--; pos2--;
                
                //update initial
                if (match[pos1]) matching--;
                else not_matching--;
                if (match[pos2]) matching--;
                else not_matching--;
                
                //swap
                std::swap(s[i1][pos1], s[i2][pos2]);
                match[pos1] = s[0][pos1] == s[1][pos1];
                match[pos2] = s[0][pos2] == s[1][pos2];

                //update with new info
                if (match[pos1]) matching++;
                else not_matching++;
                if (match[pos2]) matching++;
                else not_matching++;
            }

            //query
            else{
                if (not_matching == 0) std::cout << "YES\n";
                else std::cout << "NO\n";
            }
            
        }
        
    }
    
    return 0;
    
}