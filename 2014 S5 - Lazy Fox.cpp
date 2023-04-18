/*

2014 S5 - Lazy Fox

Recursive brute force too slow, therefore we will try the following approach

1. Get all points
2. Add every line that connects 2 points to a vector, do not take duplicate edges and make sure to keep track of what 2 points the edge connects, as well as the total distance
3. Sort the edges from least distance to greatest distance

Essentially, the idea is that we iterate through each edge, we then examine the two points that it connects
Lets call them point a and point b
We will pretend that the distance of the current edge is the limiting distance from this point
We will then determine the maximum treats obtainable from each point if the current edge's distance is the limiting distance

To do this, create 3 different vectors
dist[MAX_N] where dist[i] tells us the current maximum distance from point i
treats[MAX_N] where treats[i] tells us the max amount of treats that you can get starting from point i at the current time/edge
prevTreats[MAX_N] where prevTreats[i] tells us the max amount of treats you can get starting from point i before accounting for the current edge

The max treats you can get from point a would be max(treats[a], prevTreats[b] + 1)
Since a is connected to b, the current edge is greater distance than all previous edges processed (since we sorted them)
Meaning we can gurantee that the lazy fox can jump from point a to point b, since we know max treats from point b with the remaining distance
We can use the memoized solution

*/

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

const int MAX_N = 2001;

int main(){

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> points (N + 1);
    points[0] = {0, 0}; //Origin is point 0

    //Get coords
    for (int i = 1; i <= N; i++){
        int x, y;
        std::cin >> x >> y;
        points[i] = std::make_pair(x, y);
    }

    //Collect edges
    std::vector<std::vector<int>> edges;
    for (int i = 0; i <= N; i++){
        for (int j = i + 1; j <= N; j++){
            int dist = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
            edges.push_back({dist, i, j});
            //{distance of edge, point i, point j}
        }
    }

    //Sort edges least to greatest distance
    std::sort(edges.begin(), edges.end());
    std::vector<int> dist (MAX_N, 0), treats (MAX_N, 0), prevTreats (MAX_N, 0);

    //For each edge
    for (auto& edge: edges){
        
        int d = edge[0];
        int point1 = edge[1];
        int point2 = edge[2];

        //If distance is greater, if edge distance is equal to previous one, nothing changes
        if (d > dist[point1]){
            dist[point1] = d; //Update new limiting distance
            prevTreats[point1] = treats[point1]; //Save current as previous to ensure you have a copy where the limiting distance is not the current edge's
        }

        if (d > dist[point2]){
            dist[point2] = d;
            prevTreats[point2] = treats[point2];
        }

        //Special case, if the origin is one of the points, you cannot visit the origin again, therefore only process the origin and not the other point
        if (point1 == 0){
            treats[point1] = std::max(treats[point1], prevTreats[point2] + 1);
        }

        //Process both ways
        else{
            treats[point1] = std::max(treats[point1], prevTreats[point2] + 1);
            treats[point2] = std::max(treats[point2], prevTreats[point1] + 1);
        }

    }

    //Answer would be at treats[0] = the max treats you can obtain starting from the origin
    std::cout << treats[0] << '\n';

    return 0;

}