/*

1997 S4 - Dynamic Dictionary Coding

Difficulty: Easy

Quite literaly, use map/dictionary data structure to map a word to a number in increasing order
There's not much to say, easiest S4 by far, makes sense though, it was made in 1997

*/

#include <iostream>
#include <string>
#include <map>

int main(){

    int sets; std::cin >> sets; //Test cases
    std::string dummy; std::getline(std::cin, dummy); //Dummy line, aka first line

    int uniqueWord = 1; //Unique words are added to end, just keep track of current dict index

    while (sets > 0){

        std::map<std::string, int> dictionary; //Make new dict
        std::string line; //line of input

        //Iterate through lines of input for test case
        while (true){

            std::getline(std::cin, line);

            //If empty line, new case, exit loop
            if (line.length() == 0){
                uniqueWord = 1;
                std::cout << '\n';
                sets--;
                break;
            }

            //For each word in line
            std::string word = "";

            for (int i = 0; i < line.length(); i++){

                //Note that words have spaces between them
                if (line[i] == ' '){
                    //If already seen, output number
                    if (dictionary[word]){
                        std::cout << dictionary[word] << ' ';
                    }
                    //Otherwise, add to dictionary and output word
                    else{
                        std::cout << word <<' ';
                        dictionary[word] = uniqueWord;
                        uniqueWord++;
                    }
                    word = "";
                }

                //To handle the last word
                else if (i == line.length() - 1){
                    word += line[i];
                    //If already seen, output number
                    if (dictionary[word]){
                        std::cout << dictionary[word] << '\n';
                    }
                    //Otherwise, add to dictionary and output word
                    else{
                        std::cout << word <<'\n';
                        dictionary[word] = uniqueWord;
                        uniqueWord++;
                    }
                }

                //Keep adding letters to word
                else{
                    word += line[i];
                }

            }

        }

    }

    return 0;

}