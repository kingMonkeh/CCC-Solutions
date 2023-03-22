/*

2007 S4 - Waterpark

Difficulty: Easy/Medium

Basically depth first search problem, but it needs to be optimized using dynammic programming

The number of ways a point can be reached is the sum of all the ways that its connecting nodes can be reached
This will allow us to save the number of ways a certain point can be reached so that we can use it to calculate the number of ways for other nodes
This helps us skip the brute forcing process

Basically we start from the end (crazy the hint actually guides you)

And just dfs the entire graph recursively, making use of our already stored answers or generating a new one if we don't already have it

*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> ways;

//Takes point, returns the number of ways it can be reached
int solve(int current){

    //If we're at the start, there's only one way
    if (current == 1){
        return 1;
    }

    //If we've already calculated this point before, just reuse our answer
    if (ways[current]){
        return ways[current];
    }

    //Otherwise, recurse deeper into the graph
    int total = 0;

    for (auto &node: graph[current]){

        total += solve(node); //Add the number of ways that each adjacent point can be reached, this gives us the total ways the current point can be reached

    }

    ways[current] = total; //Save our answer for future usage

    return total;

}

int main(){

    int n; std::cin >> n;

    graph.resize(n + 1); //graph[i] is a vector containing all points that connect to i

    while (true){

        int x, y;
        std::cin >> x >> y;

        if (x == 0 && y == 0) break;

        //Put backwards, we're starting from the end this time
        graph[y].push_back(x);

    }

    ways.resize(n + 1, 0); //Our stored answers, ways[i] tells us the total number of ways that point i can be reached

    int answer = solve(n);

    std::cout << answer << '\n';

    return 0;

}