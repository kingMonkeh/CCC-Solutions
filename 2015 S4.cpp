/*

Difficulty: Hard

Before solving this problem, I didn't even know what Dijkstra's algorithm was, so there was a lot of learning done for this question.

Essentially this is just a modified Dijkstra's algorithm problem. You quite literaly perform Dijkstra's with the extra parameter of hull wear.
IF going to the next island will cause our hull to be destroyed, we just don't go there. 
To keep track of distances, we will modify the regular 1-D array to a 2-D one
dist[i][j] tells us the distance to island i with j hull remaining, meaning the first node we visit, we will have full hull

You probably should use your own struct for this since it will look nicer and writing a comparator operator would be easier

*/

#include <iostream>
#include <vector>
#include <queue>

//Comparator for priority queue, since STL priority queue takes the largest element, we want the opposite of that for Dijkstra's so we have to write this
struct compare {
    bool operator()(std::vector<int> const& a, std::vector<int> const& b){
        //IF times are the same, sort by hull wear
        if (a[0] == b[0]){
            return a[1] < b[1];
        }
        
        else{
            return a[0] > b[0];
        }
    }
};

int main(){
    
    int K, N, M;
    std::cin >> K >> N >> M;
    
    std::vector<std::vector<std::vector<int>>> graph (N + 1); //Generate the graph
    
    for (int i = 0; i < M; i++){
        
        int a, b, t, h;
        std::cin >> a >> b >> t >> h;
        
        //remember that routes go both ways
        //basically, the routes are stored as {time to travel, damage to hull wear, destination island}
        //graph[i] is a vector containing all routes from island i
        graph[a].push_back({t, h, b});
        graph[b].push_back({t, h, a});
        
    }
    
    int start, stop;
    std::cin >> start >> stop;
    
    std::vector<std::vector<int>> dist (N + 1, std::vector<int> (K + 1, 2147483647)); //2-D dist array I mentioned, auto fill with INF
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, compare> pq; //Create priority queue using our custom compare function to make it minimum
    pq.push({0, K, start}); //Push start island, with 0 time and a full hull to start
    
    //Dijkstra's
    while (!pq.empty()){
        
        std::vector<int> currentEdge = pq.top(); pq.pop();
        
        //If we've made it to our destination, by Dijkstra's the first instance that we reach this island would be the shortest path
        if (currentEdge[2] == stop){
            std::cout << currentEdge[0];
            return 0;
        }
        
        //For searoutes from this island
        for (auto seaRoute: graph[currentEdge[2]]){
            
            //Our current hull must be greater than the searoutes hull, otherwise our hull would break if we traveled
            //Make sure the time is also less otherwise no point
            if (seaRoute[1] < currentEdge[1] && seaRoute[0] + currentEdge[0] < dist[seaRoute[2]][currentEdge[1] - seaRoute[1]]){
                
                dist[seaRoute[2]][currentEdge[1] - seaRoute[1]] = seaRoute[0] + currentEdge[0]; //Update distance
                pq.push({seaRoute[0] + currentEdge[0], currentEdge[1] - seaRoute[1], seaRoute[2]}); //Push next island
                
            }
            
        }
        
    }
    
    //If we couldn't reach the island, print -1
    std::cout << -1;
    
    return 0;
    
}
