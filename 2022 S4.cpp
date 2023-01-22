/*

2022 S4 Good Triplets

Difficulty: Hard

This problem required knowledge of combinatorics which I have very little knowledge of. After spending 3 days, I sort of understand the solution to this problem, but still very annoying.

General idea:
Instead of calculating how many good triplets there are directly, we can instead calculate the number of bad triplets and subtract it from the total amount of possible triplets.

Bad triplets + Good triplets = total triplets
total triplets - bad triplets = good triplets

Total amount of triplets = N(N-1)(N-2)/6 by combinatorics

what makes a triplet bad?
All of its points are only on what half of the circle.

Therefore, we loop around the entire circle and find the opposite point

Let i represent a point on the circle
From here, we try to create all bad triangles using points from i to the opposite point

There are three possibilites

1. We take one point that exists at i and we take two other points in between i and the opposite
2. We take two points that exist at i and we take one other point in between i and the opposite
3. We take three points that exists at i, note that this doesn't even form a triangle but is still a bad triplet

Subtract all these possibilites from the total amount to obtain good triplets

VERY IMPORTANT

if the circumference is even, we will have calculated duplicate triplets
For example, if you look at the sample input for the problem, let i = 0 and opposite = 5

From i, if you look at possibility 1, you can make the triplet P1, P3, P4
But from opposite, if you look at possibility 2, you can also make the exact same triplet P3, P4, P1

Therefore, we must eliminate these duplicates to obtain the correct answer

Credit goes to geekedu for helping me understand the solution

*/

#include <iostream>
#include <vector>

#define ll long long

int main(){

    ll N, C;

    std::cin >> N >> C;

    std::vector<ll> totalPoints (C); //Total amount of points from 0 until index
    std::vector<ll> count (C, 0); //Total number of points at i on the circle

    for (ll i = 0; i < N; i++){
        ll location;
        std::cin >> location;
        count[location]++;
    }

    totalPoints[0] = count[0];
    for (ll i = 1; i < C; i++){
        totalPoints[i] = totalPoints[i - 1] + count[i];
    }

    ll possible = N * (N - 1) * (N - 2) / 6; //Total possible good triplets, divide by 6 to count ordered triplets only

    for (ll i = 0; i < C; i++){

        ll opposite = (i + C / 2) % C; //Point opposite
        ll pointsbetween; //Points between i and opposite not including i

        //If i is less than opposite
        if (i + 1 <= opposite){
            pointsbetween = totalPoints[opposite] - totalPoints[i];
        }

        //Opposite is greater than i, for example in sample output, if i = 7, opposite = 2
        else{
            pointsbetween = totalPoints[opposite] + (totalPoints[C - 1] - totalPoints[i]);
        }

        //Taking one point from position i and choosing two other points from i to opposite not including i.
        possible -= count[i] * (pointsbetween) * (pointsbetween - 1) / 2;
        //Select two points from i and choose one other point from i to opposite not including i
        possible -= count[i] * (count[i] - 1) * pointsbetween / 2;
        //Select three points from i, aka not even forming a triangle but just a point
        possible -= count[i] * (count[i] - 1) * (count[i] - 2) / 6;

    }

    //Note that if the circumference is even, triplets that only make use of points at i and opposite will be calculated twice, therefore we must get rid of them
    if (C % 2 == 0){

        for (ll i = 0; i < C/2; i++){
            ll opposite = i + C / 2;
            possible += count[i] * (count[i] - 1) * count[opposite] / 2; //Take 2 points from i and 1 point from opposite
            possible += count[i] * count[opposite] * (count[opposite] - 1) / 2; //Take 1 points from i and 2 points from opposite 
        }

    }

    std::cout << possible;

    return 0;

}