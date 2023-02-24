/*

2023 S2 - Symmetric Mountains

Difficulty: Easy/Medium

For an S2 problem, this question is quite difficult.
If you tried brute forcing this problem, you would only get 5/15 points.

Idea: We go through every crop size, but we use previous crop size to determine next one, this is sort of dp but not really

Imagine we have
1 2 3 4 5 6

We will iterate through every mountain

For example
1 2 3 4 5 6
^

This single mountain is crop size 1, we will calculate its absolute difference which is equal to 0
Now we're going to try going left and right, to form a crop of size 3

  1 2 3 4 5 6
^ ^ ^ 

Here we see there's no mountain left, so it's impossible to make a crop of size 3 with a center at 1, so we move on

Looking at mountain 2
1 2 3 4 5 6
  ^

This is another crop of size 1, we calculate its absolute difference which is equal to 0
Then we see if we can go left and right
1 2 3 4 5 6
^ ^ ^

In this case we can, this now a crop of size 3, we will now add the absolute difference between the left and right to the previous crop of size 1
0 + abs(1 - 3) = 2, we will update the minimum value for crop size 3 accordingly,

We will now try going left and right again
  1 2 3 4 5 6
^ ^ ^ ^ ^

There's no more mountains to the left, therefore we move on to the next middle

Note that this only covers odd number crop sizes, to account for even numbered crop sizes, we will start with 2 middle mountains

For example
1 2 3 4 5 6
^ ^

In this case, 1 2 would be our middle, we repeat the same process

*/

#include <iostream>
#include <vector>

int main(){

    long long N;
    std::cin >> N;

    std::vector<long long> mins (N + 1, 21487777886); //mins[i] tells us the minimum assymetry for crop size i, default is very big number so that when we compare min it takes the initial value

    std::vector<long long> mountains (N);

    for (int i = 0; i < N; i++){
        std::cin >> mountains[i];
    }

    //For odd numbered crop sizes
    for (long long mid = 0; mid < N; mid++){

        long long left = mid, right = mid;

        long long size = 1;
        long long assy = 0;
        mins[size] = assy;

        //Go until out of bounds
        while (left > 0 && right < N - 1){

            left--; right++;
            size += 2;

            assy += std::abs(mountains[left] - mountains[right]);

            mins[size] = std::min(assy, mins[size]); //Only change if the resulting value is lower

        }

    }

    long long mid1 = 0, mid2 = 1;

    //For even number crop sizes
    while(mid2 < N){

        long long left = mid1, right = mid2;

        long long size = 2;
        long long assy = std::abs(mountains[mid1] - mountains[mid2]);
        mins[size] = std::min(assy, mins[size]);

        while (left > 0 && right < N - 1){

            left--; right++;
            size += 2;

            assy += std::abs(mountains[left] - mountains[right]); //Add 2 new outer mountains

            mins[size] = std::min(assy, mins[size]); //Take min only

        }

        mid1++;
        mid2++;

    }

    for (int i = 1; i <= N; i++){
        std::cout << mins[i] << ' ';
    }

    return 0;

}