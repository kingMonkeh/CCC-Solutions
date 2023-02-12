/*

MOCK 2023 J4 - String Decryption

Failed: 3/15 Marks

Too lazy to fix this problem, will finish later when I feel like it.

*/

#include <iostream>
#include <string>
#include <map>

int main(){

    int N; std::cin >> N;

    std::string stevenString;
    std::cin >> stevenString;

    int astericksRemaining = 0;

    for (char c: stevenString){

        if (c == '*'){
            astericksRemaining++;
        }

        else{
            N -= std::abs('a' - c) + 1;
        }

    }

    if (N < astericksRemaining){
        std::cout << "Impossible" << '\n';
        return 0;
    }

    std::map<int, char> numToLetter;
    numToLetter[1] = 'a';
    numToLetter[2] = 'b';
    numToLetter[3] = 'c';
    numToLetter[4] = 'd';
    numToLetter[5] = 'e';
    numToLetter[6] = 'f';
    numToLetter[7] = 'g';
    numToLetter[8] = 'h';
    numToLetter[9] = 'i';
    numToLetter[10] = 'j';
    numToLetter[11] = 'k';
    numToLetter[12] = 'l';
    numToLetter[13] = 'm';
    numToLetter[14] = 'n';
    numToLetter[15] = 'o';
    numToLetter[16] = 'p';
    numToLetter[17] = 'q';
    numToLetter[18] = 'r';
    numToLetter[19] = 's';
    numToLetter[20] = 't';
    numToLetter[21] = 'u';
    numToLetter[22] = 'v';
    numToLetter[23] = 'w';
    numToLetter[24] = 'x';
    numToLetter[25] = 'y';
    numToLetter[26] = 'z';

    for (int i = 0; i <= stevenString.length() - 1; i++){

        if (stevenString[i] == '*'){

            if ((astericksRemaining - 1) * 26 >= N){
                stevenString[i] = 'a';
                N--;
                astericksRemaining--;
            }

            else if (astericksRemaining * 26 == N){
                stevenString[i] = 'z';
                N -= 26;
                astericksRemaining--;
            }

            else{
                stevenString[i] = numToLetter[N % 26];
                N -= N % 26;
                astericksRemaining--;
            }

            if (astericksRemaining == 0 && N > 0){
                std::cout << "Impossible" << '\n';
                return 0;
            }

        }

    }

    std::cout << stevenString << '\n';

    return 0;

}