/*

2020 S3 Searching for Strings

Complete seach method

3/15 Marks

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

std::set<std::string> permutations;

void generatePermutation (std::string p, std::vector<char> letters, int i){

    p += letters[i];
    letters.erase(letters.begin() + i);

    if (letters.size() == 0){
        permutations.insert(p);
    }

    else{
        for (int j = 0; j < letters.size(); j++){
        generatePermutation(p, letters, j);
        }
    }

    

}

int main(){

    std::string N, H;

    std::cin >> N >> H;

    int matchingPermutations = 0;

    std::vector<char> letters;


    for (int i = 0; i < N.length(); i++){
        letters.push_back(N[i]);
    }

    for (int i = 0; i < N.length(); i++){
        std::string init = "";
        generatePermutation(init, letters, i);
    }

    for (auto it = permutations.begin(); it != permutations.end(); it++){

        if (H.find(*it) != std::string::npos){
            matchingPermutations += 1;
        }

    }

    std::cout << matchingPermutations;

    return 0;
}