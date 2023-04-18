/*

2016 S5 - Circle Of Life

Difficulty: Hard

Basically, you can view the game of life, as a repeated XOR operation on the two neighbouring cells of a cell
Obviously, brute forcing this question is not possible since T can be up to 10^15
Meaning even an O(1) jump to the next generation would still take 10^15 iterations at worse

Therefore, we need to notice a pattern
Let C_j [i] represent the ith cell during the jth generation

C_2 [i] = C_1 [i - 1] XOR C_1 [i + 1]
C_3 [i] = C_2[i - 1] XOR C_2 [i + 1] = C_1 [(i - 1) - 1] XOR C_1 [(i - 1) + 1] XOR  C_1 [(i + 1) - 1] XOR C_1 [(i + 1) + 1] 
= C_1 [i - 2] XOR C_1 [i] XOR  C_1 [i] XOR C_1 [i + 2]

Now we need to note some facts about the XOR operation
x XOR x = 0
x XOR 0 = x

Therefore, C_3 [i] = C_1 [i - 2] XOR C_1 [i + 2]

You could keep repeating this for every generation that is a power of 2, (note that when C_1 is technically the 0th generation meaning C_3 is actually the 2nd generation)
Meaning the state of a cell can be determined as the XOR between the two cells that are exactly t cells away from it
Where 2 is a power of 2

This allows us to skip many generations at once

*/

#include <iostream>
#include <string>

//Find largest power of 2 that is less than the generations remaining
long long findPow2(long long gen){

    long long pow2 = 1;
    while (true){

        pow2 *= 2;

        if (pow2 > gen){
            pow2 /= 2;
            break;
        }

    }

    return pow2;

}

int main(){

    long long N, T;
    std::cin >> N >> T;

    std::string cells;
    std::cin >> cells;

    //While generations still remain
    while (T > 0){

        std::string next = "";
        long long pow2 = findPow2(T);

        for (int i = 0; i < N; i++){

            //Get leftIndex and right index, watch out for negative indices
            long long leftIndex = (i - pow2) % N;
            long long rightIndex = (i + pow2) % N;

            if (leftIndex < 0){
                leftIndex += N;
            }

            //Perform XOR
            int Xor = 0;
            Xor += '0' - cells[leftIndex] + 1;
            Xor += '0' - cells[rightIndex] + 1;

            if (Xor == 1){
                next += '1';
            }

            else{
                next += '0';
            }

        }

        cells = next; //Update cells
        T -= pow2; //Subtract gens

    }

    std::cout << cells << '\n';

    return 0;

}