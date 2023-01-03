/*

2020 S3 Searching for Strings

7/15 Marks

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

std::unordered_set<std::string> permutations;

int main(){

    std::string N, H;

    std::cin >> N >> H;

    std::multiset<char> letters;

    for (int i = 0; i < N.length(); i++){
        letters.insert(N[i]);
    }

    //Initialization
    std::multiset<char> substringLetters;
    std::string substring = H.substr(0, N.length());

    for (int i = 0; i < N.length(); i++){
        substringLetters.insert(substring[i]);
    }

    if (letters == substringLetters){
            permutations.insert(substring);
    }

    //If there are still more substrings
    for (int i = 1; i < H.length() - N.length() + 1; i++){

        substring.erase(0, 1);
        substring += H[i + N.length() - 1];
        
        substringLetters.erase(substringLetters.find(H[i - 1]));
        substringLetters.insert(H[i + N.length() - 1]);

        if (letters == substringLetters){
            permutations.insert(substring);
        }

    }

    std::cout << permutations.size();

    return 0;
}