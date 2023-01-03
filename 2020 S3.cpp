/*

Difficulty: Medium

Problem Type: String Algorithms

NOTE: THIS SOLUTION ONLY WORKS ON THE CCC GRADER, IF YOU'RE ATTEMPTING THIS PROBLEM ON DMOJ, THIS SOLUTION WILL GET TLE.
TO FIX THIS, USE RABIN-KARP'S STRING SEARCHING ALGORITHM WITH POLYNOMIAL ROLLING HASH

Subtask 1:
This problem can be completed via complete search. Generate every single permutation recursively, then check if each permutation exists with the haystack

Subtask 2 + 3:
We must optimize our algorithm since complete search is extremely slow.

Key realizations:
Permutations of the needle are all the same length, therefore we only need to search all substrings of the haystack that are the same length as the needle
We do not need to actually generate every permutation, note that all permutations share the same frequency of characters.
For example, aab and baa both have 2 a's and 1 b.

Therefore, we just need to create 2 arrays to store the character frequencies of the needle and the haystack substring.
Then just iterate over each substring the same length as the needle within the haystack and compare letter frequencies.
To avoid duplication, it's recommended to append the permutations to a set which allows no duplicate elements

Subtask 4:
Our previous algorithm has 2 problems:

It's too slow to generate the letter frequencies of each substring. Notice that each time we go right within the haystack, the previous letter was removed and one new letter was added to our substring. Thus we only need to compute these 2 letters in our array.

The second problem lies in the fact that we're appending everything to a set.
The strings can be up to 200 000 in length, if we append too many we will run into Error: Signal 6, indicating memory corruption

To reduce the memory usage considerably, we will instead hash each substring. This reduces memory usage and still allows us to tell if a permutation is distinct or not.
You may choose to write your own hashing algorithm, or you can use std::hash like me.

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <array>

std::set<size_t> hashes; //Storing hashes

std::array<int, 26> letters; //Needle frequency
std::array<int, 26> substringLetters; //Substring frequency

int main(){

    std::string N, H;

    std::cin >> N >> H;

    //Generate needle letter frequency
    for (int i = 0; i < N.length(); i++){
        letters[N[i] - 'a']++;
    }

    //Generate first substring of haystack, and initialize substring letter frequency
    std::string substring = H.substr(0, N.length());

    for (int i = 0; i < N.length(); i++){
        substringLetters[substring[i] - 'a']++;
    }

    //Add hash, if the substring is a permutation
    if (letters == substringLetters){

            std::hash<std::string> hasher;
            size_t hash = hasher(substring);
            hashes.insert(hash);
    }

    //For the remaining substrings, sliding window
    for (int i = 1; i < H.length() - N.length() + 1; i++){

        //Adjust frequencies
        substringLetters[substring[0] - 'a']--; //Remove previous letter frequency
        substringLetters[H[i + N.length() - 1] - 'a']++; //Add new letter frequency

        //Adjust actual substring
        substring.erase(0, 1);
        substring += H[i + N.length() - 1];

        //Hash substring
        std::hash<std::string> hasher;
        size_t hash = hasher(substring);

        //If substring is permutation and hash has not yet been seen
        if (letters == substringLetters && hashes.count(hash) == 0){

            hashes.insert(hash);

        }

    }

    //I've stored the hashes in a set, therefore only unique hashes exist meaning it's safe for me to output the size of set<size_t> hashes.
    std::cout << hashes.size();

    return 0;
}