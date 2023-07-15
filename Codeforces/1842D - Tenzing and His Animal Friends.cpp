#include <bits/stdc++.h>

/*

Problem statement kinda confusing, basically for the conditions
if you have animals a and b
If you choose to play with some set of animals that only includes one of a or b and excludes the other
The total time you spend playing with them solo cannot exceed the value y

Solution:
View problem as graph, constraints are like edges
Be greedy, sort edges or constraints from least to greatest
Play the absolute max amount of time before you must include another vertex/animal in your set S

*/

std::vector<long long> dist;

struct compare{
    bool operator()(const int& a, const int& b){
        return dist[a] > dist[b];
    }
};

int main () {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> graph (n);
    dist.resize(n, LLONG_MAX);
    for (int i = 0; i < m; i++){
        int u, v, y;
        std::cin >> u >> v >> y;
        u--; v--;
        graph[u].push_back({v, y});
        graph[v].push_back({u, y});
    }
    //Do dijkstra's, or any shortest path algorithm
    std::priority_queue<int, std::vector<int>, compare> pq;
    pq.push(0); dist[0] = 0;
    while (!pq.empty()){
        int cur = pq.top();
        pq.pop();
        for (auto edge: graph[cur]){
            if (dist[cur] + edge.second < dist[edge.first]){
                pq.push(edge.first);
                dist[edge.first] = dist[cur] + edge.second;
            }
        }
    }
    //inf when animal 1 is not connected to animal n in any way
    //you can basically keep playing with the set S, that doesnt include the animals connected to animal n, since animal n cannot play
    if (dist[n - 1] == LLONG_MAX){
        std::cout << "inf\n";
        return 0;
    }
    //Sort animals by distance
    std::vector<int> order (n);
    for (int i = 0; i < n; i++) order[i] = i;
    std::sort(order.begin() + 1, order.end(), [](const int& a, const int& b){return dist[a] < dist[b];});
    std::vector<std::pair<std::string, long long>> games;
    std::string animals (n, '0');
    for (int i = 0; i < n - 1; i++){
        int u = order[i], v = order[i + 1];
        //current animal we play with
        animals[u] = '1';
        //after we play with this animal, we would have reached the limit of the constraint of the next animal
        //meaning in the next iteration, we would have to include animal v in our set as well, otherwise it will be too lonely
        games.push_back({animals, dist[v] - dist[u]});
        if (v == n - 1) break; //animal n cannot play
    }
    std::cout << dist[n - 1] << ' ' << games.size() << '\n';
    for (auto game: games){
        std::cout << game.first << ' ' << game.second << '\n';
    }
    return 0;
}