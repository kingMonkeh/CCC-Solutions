/*

2006 S5 - Origin of Life

Difficulty: Hard

Basically, since the grid is only like 20 cells at max
You can actually just generate every single possible cell arrangement
Afterward, you find the next generation for each arrangement

What you've essentially done, is created a graph
Where each arrangement is a node, and an edge shows that this generation comes from the previous generation

Therefore from this graph, we can just perform a breadth first search from the starting arrangement
Until we find a garden of eden since it would have no nodes after it

The main problem however is that its not really possible to use a 2-D array as a node
Notice that each cell can only have 2 states, alive or dead
We can represent these as true or false, or as 1's and 0's
What else can we represent using 1's and 0's? Binary.

Essentially, we will view the 2-D array as a binary number and we will convert it into base 10 decimal to represent it as a single integer which will act as our nodes

From here, it's very easy

*/

#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>

int m, n, a, b, c;

std::vector<int> previous [1048576 + 1];

//Find next generation given an arrangement
void findNextGen(int binary){

    int original = binary; //Make copy for later
    int current [m + 2][n + 2];
    memset(current, 0, sizeof(current));

    //Pad the array with a border so that we don't have to manually check border ourselves
    //Convert decimal back to binary
    for (int i = 1; i < m + 1; i++){
        for (int j = 1; j < n + 1; j++){
            current[i][j] = binary % 2;
            binary /= 2;
        }
    }

    int nextGen = 0;
    int power = 1;

    //Find next gen    
    for (int i = 1; i < m + 1; i++){
        for (int j = 1; j < n + 1; j++){

            //Count alive neighbours
            int alive = 0;
            alive += current[i - 1][j]; //Up
            alive += current[i + 1][j]; //Down
            alive += current[i][j - 1]; //Left
            alive += current[i][j + 1]; //Right
            alive += current[i - 1][j - 1]; //Top Left
            alive += current[i - 1][j + 1]; //Top right
            alive += current[i + 1][j - 1]; //Bottom left
            alive += current[i + 1][j + 1]; //Bottom right

            //If the cell was already alive
            if (current[i][j]){
                if (alive >= a && alive <= b){
                    nextGen += power;
                }
            }

            //If the cell was previously dead
            else{
                if (alive > c){
                    nextGen += power;
                }
            }

            power *= 2;
            
        }
    }

    //Add to graph
    previous[nextGen].push_back(original);
        
}

int main(){

    std::cin >> m >> n >> a >> b >> c;

    //Get decimal of starting node
    int start = 0;
    int powOf2 = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            char x;
            std::cin >> x;
            //Cell is alive
            if (x == '*'){
                start += powOf2;
            }
            powOf2 *= 2;
        }
    }   

    //Generate graph
    for (int i = 0; i <= pow(2, m * n); i++){
        findNextGen(i);
        //;
    }

    //BFS
    std::vector<int> visited (1048576 + 1, 0);
    std::vector<int> distance (1048576 + 1, 0);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    //DEBUGGING
    //for (auto& prev: previous[start]){
    //        std::cout << prev << ' ';
    //}

    int steps = 0;
    while (!q.empty()){
        int curr = q.front(); q.pop();
        //If garden of eden
        if (previous[curr].size() == 0){
            std::cout << distance[curr] << '\n';
            return 0;
        }
        for (auto& prev: previous[curr]){
            if (!visited[prev]){
                q.push(prev);
                distance[prev] = distance[curr] + 1;
                visited[prev] = true;
            }
        }
        //funny cheat, basically if it takes more than 50 nodes, then theres no garden of eden
        steps++;
        if (steps == 50){
            std::cout << -1 << '\n';
            return 0;
        }
    }

    std::cout << -1 << '\n';
    
    return 0;
    
}