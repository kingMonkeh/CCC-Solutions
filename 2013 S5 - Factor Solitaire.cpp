/*

2013 S5 - Factor Solitaire

Difficulty: Medium/Hard

Basically we work backwards from the final number
If it's even, we want to break it up into 1 * itself
Since this is the optimal amount, it maximises the decrease of the final number, while only costing 1, the lowest amount

If it's not even however, things get a bit more tricky
To get to our current number
The previous number must be made from a x b
imagine that we only add a to the number, and b to our cost
We notice, that we should greedily choose the largest possible value for a, as this would maximise our number increase and minimize our cost
We will follow this, with the added condition that we will only choose odd numbers
The reasons being, even + odd = odd, therefore odd - odd = even
If we get the best when the current number is even, we should try to make it even as much as possible
Therefore, when it's odd, we must find an odd divisor to subtract to bring it back to even

*/

#include <iostream>

int main(){

    int N;
    std::cin >> N;

    int cost = 0;
    
    while (N != 1){

        //If odd
        if (N % 2){

            int divisor = N / 2; //Maximum is half of the current, since c = a x b, the a was 1 and b was the max, then b would be half of the current since it would be doubling the current amount
            
            //If even, add 1 to make it odd again
            if (!(divisor % 2)){
                divisor += 1;
            }
            
            //Try until we find the largest one that's possible
            for (; divisor >= 1; divisor -= 2){
                int newNum = N - divisor; //Hypothetical previous number
                //If c % a == 0, then b is an integer value
                if (newNum % divisor == 0){
                    //cost += b
                    cost += newNum / divisor;
                    N = newNum; //Update new number
                    break;
                }
            }
            
        }

        //If even
        else{

            N /= 2;
            cost++;
            
        }
        
    }

    std::cout << cost << '\n';
    
    return 0;
    
}