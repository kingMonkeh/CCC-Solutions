/*

1997 S5 - Long Division
Difficulty: Medium

This question is literaly just implementation.
This the kind of thing you write for a high school computer science project

*/

#include <iostream>
#include <string>

int main(){

    int n;
    std::cin >> n;

    while (n--){
        
        std::string num1, num2;
        std::cin >> num1 >> num2;

        std::string counter = ""; //Our answer
        //Go left to right
        for (int right = num2.length() - 1; right < num1.length(); right++){
            int count = 0; //Number of times we can subtract
            while (true){
                //Check which is bigger
                bool num1Bigger = true;
                for (int i = 0; i <= right; i++){
                    if (num1[i] - '0' > num2[i] - '0'){
                        break;
                    }
                    else if (num1[i] - '0' < num2[i] - '0'){
                        num1Bigger = false; break;
                    }
                }
                //If num1 is bigger, do subtraction
                if (num1Bigger){
                    //Go right to left, perform manual subtraction
                    int carryover = 0;
                    for (int i = right; i >= 0; i--){
                        //Convert char to int using ASCII codes, remember carryover
                        int top = num1[i] - '0' + carryover, bottom = num2[i] - '0', difference;
                        //If we need to borrow
                        if (top < bottom){
                            top += 10;
                            carryover = -1; //Carryover into next iteration
                            difference = top - bottom;
                            num1[i] = char ('0' + difference);
                        }
                        //Perform normally
                        else{
                            num1[i] = char ((top - bottom) + '0');
                            carryover = 0;
                        }
                    }
                }
                //If num1 smaller, then we stop since we don't go negative
                else{
                    break;
                }
                count++;
            }
            num2 = '0' + num2; //To simulate going left to right, we basically just pad the left side of second string with zeros
            counter += char (count + '0'); //Add count to counter
        }

        //Since we padded our answer and numbers with zeros, we have to ignore them now
        int i = 0;
        for (; i < counter.length(); i++){
            if (counter[i] != '0') break;
        }
        if (i == counter.length()) std::cout << '0'; //If it's all zero
        for (; i < counter.length(); i++){
            std::cout << counter[i];
        } std::cout << '\n';
        i = 0;
        for (; i < num1.length(); i++){
            if (num1[i] != '0') break;
        }
        if (i == num1.length()) std::cout << '0';
        for (; i < num1.length(); i++){
            std::cout << num1[i];
        }

        //To deal with whitespace error
        if (n != 0) std::cout << "\n\n";
        else std::cout << '\n';
        
    }
    
    return 0;
    
}