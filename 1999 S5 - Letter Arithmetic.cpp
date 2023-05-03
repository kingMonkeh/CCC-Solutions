/*

1999 S5 - Letter Arithmetic

Difficulty: Medium

This problem is actually so annoying
Basically, use recursion to try every possible letter to number set
To filter out a good amount of possibilities

Notice that the final letters of the two words % 10
must add together to equal the last letter of the third word

*/

#include <iostream>
#include <string>
#include <map>
#include <set>

int Max;
std::string word1, word2, word3;
std::string UNIQUE = "";
int used [10];
std::map<char, int> value;

void solve (int digit, int letter){

    //All letters have been given a value
    if (letter == Max - 1){
        value[UNIQUE[letter]] = digit;

        //Early filter
        if ((value[word1[word1.length() - 1]] + value[word2[word2.length() - 1]]) % 10 != value[word3[word3.length() - 1]]){
            return;
        }

        std::string copy1 = word1;
        std::string copy2 = word2;
        std::string copy3 = word3;
        //Iterators for each word
        int i1 = word1.length() - 1, i2 = word2.length() - 1, i3 = word3.length() - 1;
        int carryover = 0;

        //We basically just do manual addition
        //Since the strings are too big, this is something grade schoolers do
        while (i1 >= 0 || i2 >= 0 || i3 >= 0){
            int w1 = 0, w2 = 0, w3 = 0;
            if (i1 >= 0){
                w1 = value[word1[i1]];
                copy1[i1] = '0' + w1;
            }
            if (i2 >= 0){
                w2 = value[word2[i2]];
                copy2[i2] = '0' + w2;
            }
            if(i3 >= 0){
                w3 = value[word3[i3]];
                copy3[i3] = '0' + w3;
            }
            
            //If the addition doesnt match, then stop iterating
            if(((((w1 + w2) % 10) + carryover) % 10) != w3){
                return;
            }

            //Calculate carryover
            carryover = ((w1 + w2 + carryover) / 10);
            i1--; i2--; i3--;
        }

        //If it made it past all those filters, then it must be the correct answer
        std::cout << copy1 << '\n' << copy2 << '\n' << copy3 << "\n\n";
        
    }

    //Keep recursing
    else{
        value[UNIQUE[letter]] = digit;
        used[digit] = 1; //Mark which digits have been used
        //If first letter of a word
        if (UNIQUE[letter + 1] == word1[0] || UNIQUE[letter + 1] == word2[0] || UNIQUE[letter + 1] == word3[0]){
                for (int i = 1; i < 10; i++){
                    //Each letter must have unique number, therefore we cant use numbers that have already been used
                    if (!used[i]){
                        solve(i, letter + 1);
                    }
                }
            }
        //Otherwise
        else{
            for (int i = 0; i < 10; i++){ 
                if (!used[i]){
                    solve(i, letter + 1);
                }
            }
        }
        used[digit] = 0;
    }
    
}

int main(){

    int n;
    std::cin >> n;

    while (n--){

        std::cin >> word1 >> word2 >> word3;

        //Get unique characters
        std::set<char> unique;
        
        for (int i = 0; i < word1.length(); i++){
            unique.insert(word1[i]);
        }
        for (int i = 0; i < word2.length(); i++){
            unique.insert(word2[i]);
        }
        for (int i = 0; i < word3.length(); i++){
            unique.insert(word3[i]);
        }

        UNIQUE = "";
        for (auto it = unique.begin(); it != unique.end(); it++){
            UNIQUE += *it;
        }

        Max = unique.size();

        //Since the first letter cannot be 0
        if ((UNIQUE[0] == word1[0] || UNIQUE[0] == word2[0] || UNIQUE[0] == word3[0])){
            for (int i = 1; i < 10; i++){
                solve(i, 0);
            }
        }
        //Otherwise if not a first letter, you can give it any value
        else{ 
            for (int i = 0; i < 10; i++){
                solve(i, 0);
            }
        }
        
    }
    
    return 0;
    
}