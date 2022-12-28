#include <iostream>
#include <stdio.h>

//Ad Hoc Problem, just implement exactly what the question is asking

int main(){

    int i, j;
    int length;
    int num;
    int max;
    int temp; //Used for swapping i and j in the case that i > j

    while (scanf("%d %d", &i, &j) == 2){

        std::cout << i << " " << j << " "; //Print before we swap them as they must be outputted originally as they were, which may not be the case if we swap i and j

        max = 0; //Reset for each pair

        //In the case that i > j
        if (i > j){
            temp = j;
            j = i;
            i = temp;
        }

        //Brute forcing is fine since i and j can only be up to 10,000
        for (int n = i; n <= j; n++){

            length = 1; //Start at 1 in the case that we have num = 1 meaning the loop never starts
            num = n; //As to not change n since it's being used as the iterator

            //Implement the 3n + 1 rule
            while (num > 1){
                
                if (num % 2 == 1){
                    num = num * 3 + 1;
                }

                else{
                    num = num / 2;
                }

                length++;

            }

            //Check for max
            if (length >= max){
                max = length;
            }

        }

        std::cout << max << std::endl;

    }

    return 0;

}