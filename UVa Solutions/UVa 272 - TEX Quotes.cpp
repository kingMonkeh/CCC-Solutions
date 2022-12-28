#include <iostream>
#include <string>

//Ad Hoc problem, code the problem given the constraints.
//Input is extremely small, no optimization is needed.

int main(){

    std::string line;
    //In this question there can't be double quotes within double quotes, therefore if a double quote is found, the next double quote found must be the closing one
    bool quoteOpened = false; 

    //Collect lines until EOF
    while (std::getline(std::cin, line)){

        for (int i = 0; i < line.length(); i++){

            if (line[i] == '"'){

                if (quoteOpened == true){
                    quoteOpened = false;
                    std::cout << "''";
                }

                else{
                    quoteOpened = true;
                    std::cout << "``";
                }
                
            }

            else{
                std::cout << line[i];
            }
        }

        std::cout << std::endl; //Output must match input exactly except for the double quote changes

    }

    return 0;
}