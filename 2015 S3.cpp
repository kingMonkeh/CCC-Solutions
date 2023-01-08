/*

2015 S3 - Gates

Difficulty: Easy-Medium

CCC Grader - 15/15 Marks, DMOJ Test Cases - 30/30 Marks

Topics: Greedy, Data structures

Main idea:
It's always optimal to put a plane in the largest gate that it can go into, since all the other gates before it should be saved for the smaller planes that can only enter them

It's very much possible to use 2 for loops to solve this problem. This would earn you 15/15 marks on the CCC grader.
But on DMOJ, additional test cases have been added, forcing the use of std::set, a balanced binary search tree.

Algorithm:
1. Create a set of integers, each integer representing a gate that is open
2. For each plane:
3. Check if there is a gate that is equal or less than it that is still open, if not, this plane cannot go anywhere, break from the loop
4. If there is a gate, go for the largest possible gate that is still open, that the plane can go into

Important functions to know
std::set.lower_bound(value) - returns an iterator pointing to an element in the set with the value given, if not, it returns the next element in the set greater than what was keyed

*/

#include <iostream>
#include <set>

int main(){

    int G, P;
    std::cin >> G >> P;

    std::set<int> open; //Store open gates

    for (int i = 1; i <= G; i++){
        //Fill set
        open.insert(i);
    }

    int totalplanes = 0; //Total planes that could enter the airport
    
    for (int i = 0; i < P; i++){

        int plane;
        std::cin >> plane;

        //Check if any gate is open, the function will return the smallest gate that is open, since the input value is 0
        if (*open.lower_bound(0) > plane){
            break;
        }

        auto max_gate = open.lower_bound(plane); //If we've passed the first if statement, we can safely assume that the value that max_gate is pointing to is equal to or less than the plane value

        //If the gate is equal to the plane
        if (*max_gate == plane){
            open.erase(plane);
            totalplanes++;
        }

        //Otherwise, go for the next largest gate
        else{
            max_gate--;
            open.erase(*max_gate);
            totalplanes++;
        }
        

    }

    std::cout << totalplanes; //Output answer

    return 0;

}