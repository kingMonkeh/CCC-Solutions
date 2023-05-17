/*

Very similar to 2010 S3 - Firehose

Difficulty: Hard

Basic idea, technically speaking, the maximum distance applies to all warehouses
If we say that the max distance is 6, that is to say that by placing our warehouses correctly
We can reach all restaurants by going 6 units left or 6 units right from a specific warehouse

Therefore, we will create a function called TRY(), that will take in a max distance as a parameter
It will then attempt to see if its possible to connect all restaurants while keeping the max distance
less than or equal to the value of the parameter. It will return false if not possible and true if it is possible.

In this function, how should we place the warehouses?
We should greedily place them is the answer
If we know from a warehouse with a given max distance can reach that distance both ways
We will keep track of the left side of our warehouse and the right side of our warehouse

Starting from the first restaurant as the left most edge of our left border
We will continue iterating until the distance between the left most restaurant and the right most
restaurant of the left side of the warehouse is greater than the max distance
This will now mark the leftmost side of our right side of the warehouse
We will record the warehouse just before this as the center, and then continue with the same logic
until we hit the rightmost restaurant in which the distance between it and the leftmost restaurant
of the right edge surpasses the max distance.
This marks the left most side of the left side of the next warehouse
We keep looping through the warehouses

If our final rightmost warehouse is at the end of the line, then we can connect all restaurants
Otherwise we cannot.

With this function, we can't afford to just try every single max distance
As that would take far too long, that is why we will use a binary search on the possible distances

The ceiling would be the distance between the first and last restaurant
As this is quite literaly the max distance you can achieve with a warehouse

The floor obviously is 0

We must note something important for the binary search to make sense.
If we know that all restaurants can be connected when the max distance = m
Then all max distances > m, are also possible since you extend the arms of each warehouse further

Similarly, if a max distance m is not possible
Any max distance < m is also not possible, since the arms are getting even shorter
When they need to get longer

From this, as we perform binary search, we can confidently discard large amounts of distances
Just by knowing if a certain distance is possible


*/

#include <iostream>

int restaurants [200], warehouses [200];
int n, k;

//Our TRY function
bool TRY(int max_distance){

    //A bit trippy at first since left will represent both the left most and right most of the left side and the same applis for right
    int left, right = 0;
    //For each warehouse
    for (int i = 0; i < k; i++){
        //If we're at the end of the line with spare warehouses, just keep spamming the thing
        if (right == n){
            left = n;
        }
        //Otherwise, see how many restaurants we can cover with the left side of this warehouse
        else{
            for (left = right; left < n && restaurants[left] - restaurants[right] <= max_distance; left++);
        }
        //The previous for loop brings us to the restaurant in which the distance is too big
        //Therefore, the one just before it is actually in range
        warehouses[i] = restaurants[left - 1];
        //Determine how many restaurants we can cover with the right side of our warehouse
        for (right = left; right < n && restaurants[right] - restaurants[left - 1] <= max_distance; right++);
    }

    //If it was possible
    return (right == n);
    
}

int main(){
    while (1){
        std::cin >> n;
        if (n == 0){
            break;
        }
        std::cin >> k;
        for (int i = 0; i < n; i++){
            std::cin >> restaurants[i];
        }
        //Binary search
        int MAX = restaurants[n - 1] - restaurants[0];
        int MIN = 0;
        while (MAX > MIN){
            int midpoint = (MAX + MIN) / 2;
            //If distance is possible, all greater than it must also be possible
            //Recall that we're trying to minimize the maximum distance
            if (TRY(midpoint)){
                MAX = midpoint;
            }
            //If the distance is not enough, anything less will also not be enough
            //We need more
            else{
                MIN = midpoint + 1;
            }
        }
        TRY(MAX);
        for (int i = 0; i < k; i++){
            std::cout << warehouses[i] << ' ';
        }
        std::cout << '\n' << MAX << "\n\n";
    }
    return 0;
}