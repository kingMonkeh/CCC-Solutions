/*

2011 S4 - Blood Distribution

Difficulty: Easy or Hard, depends

For this problem, the CCC test data was really weak so you could just greedily give blood to produce a correct answer.
But the boosted DMOJ test cases are pretty annoying, which is why I will use dinic's algorithm to solve, really you could use any maximum flow algorithm

Note: I have seen some greedy solutions work, but I never really understood how so we're doing it the hard way.

CS LIFE LESSON: IF THERE's a graph, use it, if not, make a graph

View the problem as a maximum flow problem, connect all blood units to the source
Connect all units to the corresponding patients
connect all patients to the tap/sink

Perform dinic's and see how much blood can reach the sink

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 2147483647

const int NODES = 18; //Number of nodes, 8 blood units, 8 blood patients, source + sink
const int source = 0; //Index of source
const int sink = 17; //Index of sink

//Our graph, we're storing it as a NxN matrix with graph[i][j] telling us the amount of flow from the edge starting from i connecting to j
std::vector<std::vector<int>> graph (NODES, std::vector<int> (NODES, 0));

//To send flow throughout the graph recursively
int dfs(std::vector<std::vector<int>>& graph, std::vector<int>& level, int currentNode, int sink, int flow){

    //If we made it to the end of the graph, aka the sink
    if (currentNode == sink){
        return flow;
    }

    //Iterate through all adjacent nodes
    for (int i = 0; i < NODES; i++){

        //If flow can still be pushed through
        if (graph[currentNode][i] > 0){

            //We only want augmenting paths, therefore the level of the next node should be 1 greater than the current
            if (level[i] == level[currentNode] + 1){

                //Update bottleneck
                int current_flow = std::min(flow, graph[currentNode][i]);

                int bottleneck = dfs(graph, level, i, sink, current_flow);

                //If you've made it to the sink, however many recurses later
                if (bottleneck > 0){

                    graph[currentNode][i] -= bottleneck;
                    graph[i][currentNode] += bottleneck;
                    return bottleneck;

                }

            }

        }

    }

    return 0;

}

int main(){

    //Connect source to blood units
    for (int i = 1; i <= 8; i++){
        int units; std::cin >> units;
        graph[0][i] = units;
    }

    //Connect blood units to patients

    //Connect O- blood to all patients
    for (int i = 9; i <= 16; i++){
        graph[1][i] = INF;
    }

    //Connect O+ blood to O+, A+, B+ and AB+
    for (int i = 10; i <= 16; i += 2){
        graph[2][i] = INF;
    }
    
    graph[3][11] = INF; //A- to A-
    graph[3][12] = INF; //A- to A+
    graph[3][15] = INF; //A- to AB-
    graph[3][16] = INF; //A- to AB+

    graph[4][12] = INF; //A+ to A+
    graph[4][16] = INF; //A+ to AB+

    graph[5][13] = INF; //B- to B-
    graph[5][14] = INF; //B- to B+
    graph[5][15] = INF; //B- to AB-
    graph[5][16] = INF; //B- to AB+

    graph[6][14] = INF; //B+ to B+
    graph[6][16] = INF; //B+ to AB+

    graph[7][15] = INF; //AB- to AB-
    graph[7][16] = INF; //AB- to AB- //AB- to AB+

    graph[8][16] = INF; //AB+ to AB+

    //Connect patients to tap
    for (int i = 9; i <= 16; i++){
        int patients; std::cin >> patients;
        graph[i][17] = patients;
    }
    

    //Dinic's algorithm begin

    int maxBlood = 0;

    while (true){

        std::vector<int> level (18, INF);
        std::vector<bool> visited (18, false);
        std::queue<int> q;
        q.push(0); visited[0] = true; level[0] = 0;

        //Construct level graph
        while (!q.empty()){

            int current = q.front(); q.pop();

            for (int i = 0; i < NODES; i++){

                if (current != i && graph[current][i] > 0 && !visited[i]){
                    level[i] = level[current] + 1;
                    q.push(i); visited[i] = true;
                }
                
            }

        }

        if (level[17] == INF) break; //If sink could not be reached

        //Repeatedly perform dfs until all edges have been saturated
        while (int flow = dfs(graph, level, source, sink, INF)){
            maxBlood += flow;
        }

    }

    std::cout << maxBlood;

    return 0;

}