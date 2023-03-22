/*

1998 S4 - Lottery

Difficulty: Medium

Not really difficult knowledge wise, just really ugly problem.

Basically do all multiplication first,
Iterate through string, if you see an 'X'

Just check whats left and whats right
If there's brackets, keep track of how many brackets are opened and how many are closed, once all brackets have been closed, just add another bracket

If there's no brackets, just iterate until you reach the end of the number, then just insert the bracket

*/

#include <iostream> 
#include <string>

int main(){

    std::string n;
    std::getline(std::cin, n);
    int N = std::stoi(n);

    for (int i = 0; i < N; i++){

        std::string input;
        std::getline(std::cin, input);

        //Handle multiplication
        bool multiply = true;
        while (multiply){

            multiply = false;

            for (int j = 0; j < input.length(); j++){

                if (input[j] == 'X'){

                    input[j] = 'x'; multiply = true;

                    //Left side of operator
                    //If bracket left
                    if (input[j - 2] == ')'){

                        int bracketsOpen = 1;

                        for (int k = j - 3; k >= 0; k--){

                            if (input[k] == ')'){
                                bracketsOpen++;
                            }

                            if (input[k] == '('){
                                bracketsOpen--;
                                if (bracketsOpen == 0){
                                    input.insert(k, "(");
                                    break;
                                }
                            }

                        }

                    }

                    //If no bracket left
                    else{

                        bool begin = true;

                        for (int k = j - 2; k >= 0; k--){

                            if (input[k] == ' '){
                                input.insert(k + 1, "(");
                                begin = false;
                                break;
                            }

                        }

                        if (begin){
                            input.insert(0, "(");
                        }

                    }

                    //Right side of operator

                    //Bracket to the right
                    if (input[j + 3] == '('){

                        int bracketsOpen = 1;

                        for (int k = j + 4; k < input.length(); k++){

                            if (input[k] == '('){
                                bracketsOpen++;
                            }

                            if (input[k] == ')'){
                                bracketsOpen--;
                                if (bracketsOpen == 0){
                                    input.insert(k + 1, ")");
                                }
                            }

                        }

                    }

                    //If no bracket right
                    else{

                        bool end = true;

                        for (int k = j + 3; k < input.length(); k++){

                            if (input[k] == ' '){
                                input.insert(k, ")");
                                end = false;
                                break;
                            }

                        }

                        if (end){
                            input += ")";
                        }

                    }

                    break;

                }

            }

        }

        //Handle addition/subtraction
        bool addition = true;
        while (addition){

            addition = false;

            for (int j = 0; j < input.length(); j++){

                if (input[j] == '+' || input[j] == '-'){

                    addition = true;
                    if (input[j] == '+') input[j] = '=';
                    else input[j] = '_'; 

                    //Left side of operator
                    //If bracket left
                    if (input[j - 2] == ')'){

                        int bracketsOpen = 1;

                        for (int k = j - 3; k >= 0; k--){

                            if (input[k] == ')'){
                                bracketsOpen++;
                            }

                            if (input[k] == '('){
                                bracketsOpen--;
                                if (bracketsOpen == 0){
                                    input.insert(k, "(");
                                }
                            }

                        }

                    }

                    //If no bracket left
                    else{

                        bool begin = true;

                        for (int k = j - 2; k >= 0; k--){

                            if (input[k] == ' '){
                                input.insert(k + 1, "(");
                                begin = false;
                                break;
                            }

                        }

                        if (begin){
                            input.insert(0, "(");
                        }

                    }

                    //Right side of operator

                    //Bracket to the right
                    if (input[j + 3] == '('){

                        int bracketsOpen = 1;

                        for (int k = j + 4; k < input.length(); k++){

                            if (input[k] == '('){
                                bracketsOpen++;
                            }

                            if (input[k] == ')'){
                                bracketsOpen--;
                                if (bracketsOpen == 0){
                                    input.insert(k + 1, ")");
                                    break;
                                }
                            }

                        }

                    }

                    //If no bracket right
                    else{

                        bool end = true;

                        for (int k = j + 3; k < input.length(); k++){

                            if (input[k] == ' '){
                                input.insert(k, ")");
                                end = false;
                                break;
                            }

                        }

                        if (end){
                            input += ")";
                        }

                    }    

                    break;

                }

            }

        }

        //I had temporarily changed the operators in the string to ensure they weren't iterated over twice
        //Now i must undo these changes
        for (int j = 0; j < input.length(); j++){
            if (input[j] == '=') input[j] = '+';
            else if (input[j] == '_') input[j] = '-'; 
            else if (input[j] == 'x') input[j] = 'X';
        }

        //Technically, there's an extra bracket around the entire thing, so we just ignore that by starting at the 2nd letter and ending at the 2nd last
        int length = input.size();
        for (int j = 1; j < length - 1; j++){
            std::cout << input[j];
        }

        //Blank lines between outputs
        if (i != N - 1)
            std::cout << "\n\n";

        //Last line must terminate with a new line
        else
            std::cout << '\n';

    }

    return 0;

}