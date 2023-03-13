/*

2009 S4 - Shop and Ship

Difficulty: Medium

This problem is a very simple Dijkstra's algorithm problem, all you have to do is perform dijkstra's starting from the destination

Afterward, iterate through all possible cities that sell pencils, add their pencil price to the shipping price to reach there and update the lowest cost accordingly

*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

#define INF 2147483647

//Random macro i found in DMOJ comment section that speeds up input and output
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

std::vector<int> dist;

int main(){

    int N; scan(N);
    int T; scan(T);

    //Our graph, the hardest part about this problem is the time limit and memory limit, use pair as it consumes much less memory than a vector
    std::vector<std::vector<std::pair<int, int>>> graph (N + 1);

    //Get trade routes
    for (int i = 0; i < T; i++){

        int x, y, cost;
        scan(x); scan(y); scan(cost);

        //Push edges both ways
        graph[x].push_back({y, cost});
        graph[y].push_back({x, cost});

    }

    int K; std::cin >> K;
    std::unordered_map<int, int> pencilCost;

    //Get cities that sell pencils
    for (int i = 0; i < K; i++){

        int city, pencil;
        scan(city); scan(pencil);

        pencilCost[city] = pencil;

    }

    int D; scan(D);
    int minCost = INF;

    //Run Dijkstra's algorithm

    dist.resize(N + 1, INF);
    std::queue<int> q;
    q.push(D); dist[D] = 0;

    while (!q.empty()){

        int current = q.front(); q.pop();

        for (auto &traderoute: graph[current]){

            if (dist[traderoute.first] > dist[current] + traderoute.second){

                dist[traderoute.first] = dist[current] + traderoute.second;
                q.push(traderoute.first);

            }

        }

    }

    //Iterate through each pencil selling city, check if shipping cost + pencil cost is less than our current min
    for (auto it = pencilCost.begin(); it != pencilCost.end(); it++){
        minCost = std::min(minCost, dist[it->first] + it->second);
    }

    std::cout << minCost << '\n';

    return 0;

}