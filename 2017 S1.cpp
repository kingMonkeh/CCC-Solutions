/*

2017 S1 - Sum Game

Difficulty: Very Easy

Very simple problem. Take in inputs, store them in vectors. 
Loop through the vectors, add each vector's sum to total runs of the corresponding team.
Compare the teams, if they're equal, update the maximum possible day.

*/

#include <iostream>
#include <vector>

int main(){

    int N;
    std::cin >> N;

    int K = 0; //0 by default since if no value of K where both teams have equal runs, you should output 0
    int swifts = 0, semaphores = 0; //Total runs of each team

    std::vector<int> swiftsRuns (N);
    std::vector<int> semaphoresRuns (N);

    for (int i = 0; i < N; i++){

        std::cin >> swiftsRuns[i];

    }

    for (int i = 0; i < N; i++){

        std::cin >> semaphoresRuns[i];

    }

    //For each day
    for (int i = 0; i < N; i++){

        //Update sums
        swifts += swiftsRuns[i];
        semaphores += semaphoresRuns[i];

        //Check if equal
        if (swifts == semaphores){
            K = i + 1; //Update max day
        }

    }

    std::cout << K; //Output day

    return 0;

}