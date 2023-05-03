/*

1998 S5 - Mountain Passage

Difficulty: Medium

Basically, the question requires you to find the path to the end that requires the minimum amount of oxygen
When moving between any two points, if either have an altitude greater than the initial, you require 1 oxygen
Therefore, we will make note that we can essentially construct a weighted graph given the input
From there, we can perform Dijkstra's shortest path algorithm to determine the minimum oxygen required to reach the end

Not really much else to say, pretty straightforward problem

*/

#include <iostream>
#include <queue>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>

//compare for dijkstra's priority queue
struct compare{
    bool operator ()(int& a, int& b){
        return a > b;
    }
};

//Going up down left right
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

int main(){

    int tests;
    std::cin >> tests;

    while (tests--){

        int n;
        std::cin >> n;

        //Set up the grid, notice that I pad the left and right of the mountain to avoid overflow when checking left right up down
        std::vector<std::vector<int>> mountain (n + 2, std::vector<int> (n + 2, 999999999));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                std::cin >> mountain[i][j];
            }
        }

        //Time to actually construct the graph from the given input
        int initialAltitude = mountain[1][1];
        //I'm converting the 2-D graph into a 1-D graph by imagining the 2-D array as a really long number line
        std::vector<std::vector<std::vector<int>>> graph (n * n + 1);
        std::vector<int> oxygenUsed (n * n + 1, 999999999); //Dijkstra's distance array

        //For each row
        for (int r = 1; r <= n; r++){
            //For each column
            for (int c = 1; c <= n; c++){
                //Check up left right down
                for (int i = 0; i < 4; i++){
                    //An edge only exists if the absolute difference between the 2 altitudes is < 3
                    if (abs(mountain[r + row[i]][c + col[i]] - mountain[r][c]) < 3){
                        //If either is greater than initial altitude, the edge requires oxygen
                        if (mountain[r + row[i]][c + col[i]] > initialAltitude || mountain[r][c] > initialAltitude){
                            graph[n * (r - 1) + c].push_back({1, n * (r + row[i] - 1) + c + col[i]});
                        }
                        //Otherwise, no oxygen
                        else{
                            graph[n * (r - 1) + c].push_back({0, n * (r + row[i] - 1) + c + col[i]});
                        }
                    }
                }
            }
        }
        

        //Dijkstra's begin
        oxygenUsed[1] = 0;
        std::priority_queue<int, std::vector<int>, compare> q;
        q.push(1);
        
        while(!q.empty()){
            
            int cur = q.top();
            q.pop();

            for (auto edge: graph[cur]){
                if (oxygenUsed[edge[1]] > oxygenUsed[cur] + edge[0]){
                    q.push(edge[1]);
                    oxygenUsed[edge[1]] = oxygenUsed[cur] + edge[0];
                }
            }
            
        }

        //If not reachable
        if (oxygenUsed[n * n] == 999999999){
            std::cout << "CANNOT MAKE THE TRIP\n";
        }
        //Reachable
        else{
            std::cout << oxygenUsed[n * n] << '\n';
        }

        //This is just for correct output format
        if (tests != 0){
            std::cout << '\n';
        }
            
    }
    
    return 0;
    
}