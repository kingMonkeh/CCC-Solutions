/*

2015 J5 - π-day

Topics: Dynamic Programming + Recursion

Difficulty: Medium

You can earn half marks very easily on this problem by just trying every single line. The problem with this however is that it's far too slow for the last few test cases.
To speed things up, we can use dynamic programming to memoize our previous calculations and reuse their answers.

In our memoization, we must keep track of three things:
1. The remaining slices of pie
2. The remaining people to enter the line
3. The minimum next value (The value of the recent person to be added to the line, since the next person wants the same or more pie)

For each memoization of a state, we must assign it the value of the # of ways we can form a line under those constraints.

With this information now, when we're partway building a line, if we have the answer to the memoization of our current state, we can just return that value since it's like a concatation to our line defining all possibilities.

For example:

Imagine n = 26 we're currently building:

1 3 3 5 _ _

Now suppose we've already solved

1 2 4 5 _ _

We notice that 1 3 3 5 and 1 2 4 5 are in the same state, they each have 14 slices of pie remaining, 2 people left to be added and the next person must be greater than or equal to 5

Since we've already solved for 1 2 4 5 _ _, and their memoization states are the same, we can say 1 3 3 5 _ _ can be built the same amount of ways as 1 2 4 5 _ _

*/

#include <iostream>
#include <vector>

int waysToDistribute = 0; //Our answer

//ways[piesRemaining][peopleRemaining][nextPerson] tells us the number of ways we can build a line given the remaining pies, people remaining and the value of the next person
std::vector<std::vector<std::vector<int>>> ways;

//Solve(), nextPerson indicates the minimum value the next person must take on, piesRemaining and peopleRemaining are self-explanatory
int solve(int nextPerson, int piesRemaining, int peopleRemaining){
    
    //If 0, meaning we haven't solved this memoization state yet
    if (ways[piesRemaining][peopleRemaining][nextPerson] == 0){

        //If piesRemaining == peopleRemaining, you can only give 1 pie to each person and no other way, so max 1 possibility
        if (piesRemaining == peopleRemaining){
            ways[piesRemaining][peopleRemaining][nextPerson] = 1;
        }

        //If there's only one person remaining, they will get however much pie is left, 1 possibility
        else if (peopleRemaining == 1){
            ways[piesRemaining][peopleRemaining][nextPerson] = 1;
        }

        //Otherwise, we will attempt to add different people to the end of the current line and recurse deeper
        else{

            int lines = 0; //# of ways we can form the line

            //Start at the minimum value the nextPerson must take on, and loop until we hit the maximum value they can take on.
            //Max is piesRemaining / peopleRemaining because every person must receive atleast the same amount and if we give too much to the nextPerson, the people afterwards won't be able to take equal or more
            for (int i = nextPerson; i <= piesRemaining / peopleRemaining; i++){
                lines += solve(i, piesRemaining - i, peopleRemaining - 1);
            }

            ways[piesRemaining][peopleRemaining][nextPerson] = lines; //Memoize state

        }

    }

    return ways[piesRemaining][peopleRemaining][nextPerson];

}

int main(){

    int n, k;
    
    std::cin >> n >> k;

    ways.resize(n + 1, std::vector<std::vector<int>> (k + 1, std::vector<int> (n + 1, 0))); //3-D vector to store our states, default value is 0 indicating unsolved
    
    waysToDistribute = solve(1, n, k);

    std::cout << waysToDistribute;
    
    return 0;
    
}
