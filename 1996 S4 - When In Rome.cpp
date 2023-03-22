/*

1996 S4 - When In Rome

Difficulty: Easy/Medium

Just do it lmao.

*/

#include <iostream>
#include <string>
#include <map>

int main(){

    std::map<char, int> romanToInt;
    romanToInt['I'] = 1;
    romanToInt['V'] = 5;
    romanToInt['X'] = 10;
    romanToInt['L'] = 50;
    romanToInt['C'] = 100;
    romanToInt['D'] = 500;
    romanToInt['M'] = 1000;

    int cases;
    std::cin >> cases;

    while (cases){

        std::string input;
        std::cin >> input;

        std::string left = "", right = "";
        char current = 'l';
        //Iterate through input, split into two substrings, left side of operator and right side
        for (int i = 0; i < input.length() - 1; i++){

            if (input[i] == '+'){
                current = 'r';
                continue;
            }

            if (current == 'l'){
                left += input[i];
            }

            else{
                right += input[i];
            }

        }

        //Convert the 2 roman numerals into actual numbers
        //Left side of operator
        int LEFT = 0;
        LEFT += romanToInt[left[0]];
        char previous = left[0];
        for (int i = 1; i < left.length(); i++){
            if (romanToInt[left[i]] > romanToInt[previous]){
                LEFT -= romanToInt[previous];
                LEFT += romanToInt[left[i]] - romanToInt[previous];
            }
            else{
                LEFT += romanToInt[left[i]];
            }
            previous = left[i];
        }

        //Right side of operator
        int RIGHT = 0;
        RIGHT += romanToInt[right[0]];
        previous = right[0];
        for (int i = 1; i < right.length(); i++){
            if (romanToInt[right[i]] > romanToInt[previous]){
                RIGHT -= romanToInt[previous];
                RIGHT += romanToInt[right[i]] - romanToInt[previous];
            }
            else{
                RIGHT += romanToInt[right[i]];
            }
            previous = right[i];
        }

        int sum = LEFT + RIGHT;

        //Convert sum to roman numeral

        if (sum > 1000){
            std::cout << input << "CONCORDIA CUM VERITATE\n";
        }

        //Since roman numerals are constructed using the characters from greatest to least
        //It suffices to just greedily construct the roman numberal by using the largest character possible to fill the remaining sum required
        else{

            std::string output = "";

            while (true){

                if (sum == 0){
                    break;
                }

                if (sum >= 1000){
                    output += 'M';
                    sum -= 1000;
                }

                else if (sum >= 900){
                    output += "CM";
                    sum -= 900;
                }

                else if (sum >= 500){
                    output += 'D';
                    sum -= 500;
                }

                else if (sum >= 400){
                    output += "CD";
                    sum -= 400;
                }

                else if (sum >= 100){
                    output += 'C';
                    sum -= 100;
                }

                else if (sum >= 90){
                    output += "XC";
                    sum -= 90;
                }

                else if (sum >= 50){
                    output += 'L';
                    sum -= 50;
                }

                else if (sum >= 40){
                    output += "XL";
                    sum -= 40;
                }

                else if (sum >= 10){
                    output += 'X';
                    sum -= 10;
                }

                else if (sum >= 9){
                    output += "IX";
                    sum -= 9;
                }

                else if (sum >= 5){
                    output += 'V';
                    sum -= 5;
                }

                else if (sum >= 4){
                    output += "IV";
                    sum -= 4;
                }

                else{
                    output += 'I';
                    sum -= 1;
                }

            }

            std::cout << input << output << '\n';

        }

        //std::cout << LEFT << ' ' << RIGHT << '\n';

        cases--;
    }

    return 0;

}