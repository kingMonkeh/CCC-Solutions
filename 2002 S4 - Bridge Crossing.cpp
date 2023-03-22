/*

2002 S4 - Bridge Crossing

Difficulty: Medium/Hard

Credit: MMHS solutions for inspiration

This is a dynammic programming problem.
Essentially, lets say min[i] tells us the minimum time for the first i people to cross

You can view this problem as segmentizing an array and determining the optimal segment arrangement such that the time is minimized

We will iterate over each possible segment starting position, afterward, we will try all segment sizes from this starting position until we go out of bounds or reach the segment limit
To calculate time, we just take min[i] up until the starting point of the current segment, then we just add the slowest person in our segment and determine if it's more optimal

Next up we have to worry about output and knowing which segments we used, as well as what people were in those segments.

To do this, we will create a second array called groupSize, groupsize[i] will tell us the size of the segment that ends with person i
Note that we should only update this value if the segment creates a more optimal solution, otherwise we wouldn't want it

Using this array, by starting from the end, we can work backwards, to obtain the size of each segment we used in order backwards
From there, we just for each segment size, we then just output all the people within that range before starting a newline

*/
#include <iostream>
#include <vector>
#include <string>

#define INF 2147483647

int main(){

    int M; std::cin >> M;
    int Q; std::cin >> Q;

    std::vector<std::string> names (Q); //names of people
    std::vector<int> time (Q); //time person i takes to cross

    // Get input
    for (int i = 0; i < Q; i++){
        std::cin >> names[i] >> time[i];
    }

    std::vector<int> min (Q + 1, INF); //Our DP arraym min[i] tells us minimum time for first i people to cross
    std::vector<int> groupSize (Q + 1); //groupSize[i] tells us the size of the optimal group that ends with person i

    min[0] = 0; groupSize[0] = 0; //Set these default values for use later on

    //For each segment start position
    for (int i = 0; i < Q + 1; i++){

        int slowest = 0; //Time of slowest person of this segment

        //For every possible segment size from this starting position
        for (int j = 1; i + j < Q + 1 && j <= M; j++){

            slowest = std::max(slowest, time[i + j - 1]); //Update slowest

            //If this segment creates an optimal solution, replace the current
            if (min[i] + slowest < min[i + j]){
                min[i + j] = min[i] + slowest;
                groupSize[i + j] = j; //Update group size accordingly
            }

        }

    }

    std::vector<int> output (Q + 1); //Our output array, essentially, it holds all the segment sizes in reverse order
    //output[0] would be the size of the last segment we used

    int person = Q; //Last person of group
    int index = 0; //Index of output
    //Here we will obtain the segment sizes in order,
    //To do this we start backwards since we know the last segment will always end with the last person
    //Afterward, to find the next segment size, we subtract the current segment size from our person index to obtain the index of the last person in the previous segment, repeat this until we reach 0
    while (groupSize[person] != 0){

        output[index] = groupSize[person]; //Set segment size
        person -= groupSize[person]; //Get last person of previous segment
        index++; //Update output index

    }

    std::cout << "Total Time: " << min[Q];

    //Since output stores the sizes in reverse, we need to undo that by reversing the reverse
    int nameIndex = 0; //Index of names array

    //For each segment size, starting with the last of output, which is technically the first in our solution
    for (int i = index; i >= 0; i--){

        //While j is smaller than the group size
        //Output each person, increment nameIndex each time
        for (int j = 0; j < output[i]; j++){
            std::cout << names[nameIndex] << ' ';
            nameIndex++;
        }

        std::cout << '\n'; //Newline for next segment

    }

    return 0;

}