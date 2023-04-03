/*

2019 S5 - Triangle Data Structure

Difficulty: Hard

This problem has a very interesting solution. 
Essentially, we notice that if we brute force the problem by searching through each cell of each subtriangle
There's a lot of unnecessary overlap.

To avoid this, we will determine the max element in a sub triangle by dividing it into 3 smaller subtriangles and picking the max of the 3
This reduces our overlap and allows us to build upon our solved triangles to reach the desired subtriangle size

Notice that to split a triangle into 3 smaller subtriangles, each subtriangle must have a minimum height of atleast ceil(triangle size * (2 / 3))
Sub triangles any larger, create too much overlap and are inefficient

With this knowledge, we will write a recursive function called solve() which takes a triangle size as a parameter
This function will determine the max value for each triangle of the given size using 3 smaller subtriangles

Note that if we're attempting to calculate triangle size 2, the minimum size of each subtriangle is 1, not ceil(size * 2 / 3)
This is the only edge case, if we're passed triangle size 1, we do nothing since thats the base

IMPORTANT NOTE:
INPUT SIZE IS VERY LARGE, USE SCANF AS IT'S MUCH FASTER THAN CIN, (ABOUT 3x FASTER ON MY SUBMISSION)

*/

#include <iostream>
#include <vector>
#include <math.h>

std::vector<std::vector<int>> triangle; //Our original triangle, note that as we run solve(), it will overwrite the actual values of this triangle

//subtriangle_size is the size of the current triangle we're trying to solve for
void solve(int subtriangle_size){

    //If subtriangles of size 1, just do nothing
    if (subtriangle_size == 1){
        return;
    }

    //Otherwise, we calculate the size of the 3 sub triangles of this sub triangle
    int subsize = ceil(subtriangle_size * 2.0 / 3.0);

    //Edge case, if subtriangle_size = 2, we actually only need subsize 1
    if (subtriangle_size == 2){
        subsize = 1;
    }
    
    solve(subsize); //Solve for all the smaller subtriangles that will make up the triangles of our current size
    //Note that for every triangle we solve, we put the max value of a triangle at its head node, (the top corner)

    //Update the triangles using triplets of smaller subtriangles
    for (int i = 0; i <= triangle.size() - subtriangle_size; i++){
        for (int j = 0; j <= i; j++){
            //The first top subtriangle has the same head as the current triangle, the bottom left subtriangle has its head at i + subtriangle_size - subsize
            //Lastly, the bottom right subtriangle is located at [i + subtriangle_size - subsize][j + subtriangle_size - subsize]
            //If you don't believe me, try this on paper
            triangle[i][j] = std::max(triangle[i][j], std::max(triangle[i + subtriangle_size - subsize][j], triangle[i + subtriangle_size - subsize][j + subtriangle_size - subsize]));
        }   
    }
    
}

int main(){

    int N, K;
    scanf("%d%d", &N, &K);

     triangle.resize(N);

    //Get triangle
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            int value;
            scanf("%d", &value); //USE SCANF, DO NOT USE CIN
            triangle[i].push_back(value);
        }
    }

    //Solve
    solve(K);
    long long sum = 0; //Use long long, number gets very big

    //For each subtriangle of size K
    for (int i = 0; i <= N - K; i++){
        for (int j = 0; j <= i; j++){
            //Add max value for this sub triangle size generated from solve() function call
            sum += triangle[i][j]; 
        }
    }
    
    std::cout << sum << '\n';
    
    return 0;
  
}