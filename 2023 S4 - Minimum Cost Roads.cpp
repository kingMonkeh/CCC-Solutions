/*

2023 S4- Minimum Cost Roads

Difficulty: Hard

This problem requries knowledge of both Kruskal's MST algorithm and Dijkstra's shortest path in a weighted graph, it's a very annoying problem

General idea, there's a kruskal like way to determine the total cost of the plan

Start out by sorting all edges in descending order by cost

For each edge:
Temporarily delete the current edge from the graph
Afterward, to determine if we truly need this edge, we will perform Dijkstra's between the two points 
From Dijkstra's if there exist an indirect path that connects u and v with the same amount of length or less, we will permanently discard this edge
Otherwise, we can deem that this edge is necessary therefore we will add it to our graph to ensure the distance is minimized

Some parts that may be confusing:

Why sort edges in descending order?

This part is kind of hard to explain, basically by starting out with the most expensive ones, we can immediately determine if we need them or not
If we had started with the cheapest, when we perform Dijkstra's, it's very much possible that a really expensive edge may yield better distance but horrendous cost
But by starting with the most expensive, any indirect path found connecting u and v will be made up of cheaper edges as well, minimizing cost and distance

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 922337203685477580 //INFINITY for Dijkstra's

std::vector<long long> dist; //Distance array for Dijkstra's

//Compare function for priority queue for Dijkstra's
struct compare {

    bool operator()(const int& a, const int& b){

        return dist[a] > dist[b];

    }

};

//Compare function for sorting edges in descending order for Kruskal's
struct compare2 {

    bool operator()(std::vector<int> const& a, std::vector<int> const& b){

        return a[0] > b[0];

    }

};

int main(){

    long long cost = 0;

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> roads (M); //Store edges for Kruskal's MST
    std::vector<std::vector<std::vector<int>>> graph (N + 1); //Create a graph so that we do Dijkstra's

    for (int i = 0; i < M; i++){

        int u, v, l, c; std::cin >> u >> v >> l >> c;
        roads[i] = {c, l, u, v}; //cost, length, start, stop
        graph[u].push_back({l, v}); //Construct forward edge
        graph[v].push_back({l, u}); //Construct backward edge

    }

    std::sort(roads.begin(), roads.end(), compare2()); //Sort edges in descending order

    //For each edge
    for (auto road: roads){

        std::vector<int> currentRoad = road; //Get current road
        std::vector<int> UtoV = {currentRoad[1], currentRoad[3]}; //Forward edge
        std::vector<int> VtoU = {currentRoad[1], currentRoad[2]}; //Backward edge

        //Temporarily delete the forward edge
        for (auto it = graph[currentRoad[2]].begin(); it != graph[currentRoad[2]].end(); it++){
            if (*it == UtoV){
                graph[currentRoad[2]].erase(it);
                break;
            } 
        }

        //Temporarily delete the backward edge
        for (auto it = graph[currentRoad[3]].begin(); it != graph[currentRoad[3]].end(); it++){
            if (*it == VtoU){
                graph[currentRoad[3]].erase(it);
                break;
            } 
        }

        //Perform Dijkstra's
        dist.clear(); dist.resize(N + 1, INF);
        std::priority_queue<int, std::vector<int>, compare> pq;

        //pq.push({length, u}); dist[u] = 0
        pq.push(currentRoad[2]); dist[currentRoad[2]] = 0;

        while (!pq.empty()){

            int current = pq.top(); pq.pop();

            //For all adjacent nodes
            for (auto edge: graph[current]){

                if (dist[edge[1]] > dist[current] + edge[0]){

                    pq.push(edge[1]);
                    dist[edge[1]] = dist[current] + edge[0];

                }

            }

        }

        //If there exists no indirect path that has length equal to or less than l, than this edge is mandatory, add it to our plan
        if (dist[currentRoad[3]] > currentRoad[1]){

            //Re add edges to graph, update cost of plan
            graph[currentRoad[2]].push_back(UtoV);
            graph[currentRoad[3]].push_back(VtoU);
            cost += currentRoad[0];

        }

    }

    std::cout << cost << '\n';

    return 0;

}