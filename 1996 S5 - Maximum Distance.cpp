/*

1996 S5 - Maximum Distance
Difficulty: Easy

This is a pretty basic binary search problem
Essentially, for a given Y[j], you attempt to find the largest value in X[], that is equal to or less than Y[i]
Since the arrays are already sorted, you can just binary search it

*/

#include <iostream>

int main(){
    int testCases;
    std::cin >> testCases;
    while (testCases--){

        //Get input
        int length;
        std::cin >> length;
        int X[length];
        int Y[length];
        for (int i = 0; i < length; i++){
            std::cin >> X[i];
        }
        for (int i = 0; i < length; i++){
            std::cin >> Y[i];
        }

        //Go right to left in Y
        int max = 0;
        for (int i = length - 1; i >= 0; i--){
            //If Y[i] > the first value in X, its bigger than everything then, so distance is just the index
            if (Y[i] >= X[0]){
                max = std::max(max, i);
            }
            //If Y[i] is smaller than the last value in X, the answer will always be zero since Y[j] must be greater than or equal to X[i]
            else if (Y[i] < X[length - 1]){
                continue;
            }
            //Perform binary search
            else{
                //left, right, middle
                int left = 0, right = length - 1, mid;
                //It will get stuck once left and right are adjacent, in which case the smaller value is on the right side since the list is descending
                while (right - left != 1){
                    mid = (left + right) / 2;
                    //If X[mid] is bigger, update the left side
                    if (X[mid] > Y[i]){
                        left = mid;
                    }
                    //If X[mid] is less than or equal to, update the right side
                    else{
                        right = mid;
                    }
                } 
                //Remember that the index of Y, must be greater than the index of X, therefore we can only update if this is the case
                if (right <= i) max = std::max(max, i - right);
            }
            
        }
        std::cout << "The maximum distance is " << max << '\n';
    }
    return 0;
}