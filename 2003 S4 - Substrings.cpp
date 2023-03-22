/*

2003 S4 - Substrings

Difficulty: Medium

For this problem, you just need to know either suffix tree or suffix array, either work.
If you don't know about these structures, then that's probably why you can't solve this problem.

A good channel to check out to learn about suffix arrays is WilliamFiset, he even has a video that solves this problem

Basically we just have a suffix array, which is all the suffixes of string S, sorted
Afterwards, we count what is the length of the longest prefix between two adjacent suffixes, this tells us how many duplicates there are

We total all these duplicates.

Afterwards, we recognize that excluding the "" substring, there are n(n + 1) / 2 substrings for a string with length n

You could derive this from the arithmetic series formula with n(a1 + a2) / 2
n would be the length of our string and so would a1.
a2 would be the minimum substring length which is 1.
This gives us the formula.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){

    int N; std::cin >> N;

    for (int n = 0; n < N; n++){

        std::string S;
        std::cin >> S;

        std::vector<std::string> suffix; //Suffix array, holds all the suffixes

        //Get all suffixes
        for (int i = 0; i < S.length(); i++){
            suffix.push_back(S.substr(i, S.length() - i));
        }

        std::sort(suffix.begin(), suffix.end()); //Sort lexicographically

        int lcp = 0; //Longest common prefix total

        //For each suffix, compare with previous one
        for (int i = 1; i < suffix.size(); i++){

            int index = 0; //Char index in suffixes

            while (true){
                //If they don't match, break
                if (suffix[i][index] != suffix[i - 1][index]) break;
                lcp++; index++; //Otherwise, add it to the lcp
            }

        }

        //Our answer, 1 for the "" substring and then we use our formula for total substrings - lcp which represents the duplicates
        int count = 1 + ((S.length() * (S.length() + 1)) / 2) - lcp;

        std::cout << count << '\n';

    }

    return 0;

}