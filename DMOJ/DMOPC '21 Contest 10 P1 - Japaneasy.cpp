#include <iostream>
#include <string>
#include <map>

/*

None of the sounds overlap, so you can quite literaly just attempt to build the word from left to right

*/

int main(){
    int T;
    std::cin >> T;

    //Quick init
    std::map<std::string, int> good;
    std::string cons = "knhmr";
    std::string vowel = "aiueo";
    good["a"] = 1;
    good["i"] = 1;
    good["u"] = 1;
    good["e"] = 1;
    good["o"] = 1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == 2 && j == 2){
                good["fu"] = 1;
                continue;
            }
            std::string sound = "";
            sound += cons[i];
            sound += vowel[j];
            good[sound] = 1;
        }
    }

    while (T--){
        std::string word;
        std::cin >> word;
        bool japaneasy = true;
        for (int i = 0; i < word.length();){
            std::string substr = "";
            substr += word[i];
            if (good[substr]){
                i++;
                continue;
            }
            if (i < word.length() - 1){
                substr += word[i + 1];
            }
            if (good[substr]){
                i += 2;
            }
            else{
                japaneasy = false;
                break;
            }
        }
        if (japaneasy){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
    return 0;
}