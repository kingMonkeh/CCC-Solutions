/*

2010 S4 - Animal Farm

Difficulty: Hard

CS LIFE LESSON: If you have a graph great! If you don't have a graph, make one.

For this problem, you can view each pen as a vertex/node, and you can view sides that are shared by pens as edges.
As for outside edges, they can be viewed as edges that connect the pen to another node which represents the outside.

Now the question merely becomes a minimum spanning tree problem as the minimum cost to connect them all would just be the MST of the graph.

There's a catch though, we must perform two MST's, one without going outside, and another that allows us to go outside.

The reason for this is because the node that represents the outside is an optional node, that is we don't have to connect it to our graph
But there's the possibility that going outside will cost less than purely being inside, which is why we have to check for both

*/

#include <iostream>
#include <vector>
#include <set>

std::vector<int> parent;
std::vector<int> size;

int root(int pen){

    if (parent[pen] != pen){
        return root(parent[pen]);
    }
    
    else{
        return pen;
    }

}

bool find(int pen1, int pen2){

    if (root(pen1) != root(pen2)){
        return false;
    }

    else{
        return true;
    }

}

void Union(int pen1, int pen2){

    int rootPen1 = root(pen1);
    int rootPen2 = root(pen2);

    if (size[rootPen1] > size[rootPen2]){
        parent[rootPen2] = rootPen1;
        size[rootPen1] += size[rootPen2];
    }

    else{
        parent[rootPen1] = rootPen2;
        size[rootPen2] += size[rootPen1];
    }

}



int main(){

    int M;
    std::cin >> M;

    //edges before the graph is constructed
    //edges[i][j] returns a vector with its first element being the cost of the edge between corner i and j
    //After the cost, will be the pens that this edge is apart of
    std::vector<std::vector<std::vector<int>>> edges (1001, std::vector<std::vector<int>> (1001));

    //Collect edges

    //for each pen
    for (int i = 0; i < M; i++){

        int e; std::cin >> e;

        std::vector<int> corners (e);

        //Collect the corners
        for (int j = 0; j < e; j++){
            std::cin >> corners[j];
        } 

        corners.push_back(corners[0]); //Since the front and back corner are connected, we will add the front to the end as well

        //Now we can get each edge and its cost
        for (int j = 0; j < e; j++){
            
            int weight; std::cin >> weight;
            int current = corners[j], next = corners[j + 1]; //The corners

            //Note that we will be sorting them since (2, 3) is the same as (3, 2) and we will be using the size of edges[i][j] to determine if two pens share an edge
            if (current > next){
                int temp = next;
                next = current;
                current = temp;
            }

            if (edges[current][next].size() == 0){
                edges[current][next].push_back(weight);
            }

            edges[current][next].push_back(i);
            
        }

    }

    //Convert input to actual graph
    //edges are represented as vectors with cost first, then start and stop of edge. {cost, start, stop}
    std::multiset<std::vector<int>> graphEdges;

    for (int i = 0; i < 1001; i++){

        for (int j = i; j < 1001; j++){

            //This means there's only one pen using this edge since the other element in the vector is the cost of this edge
            //Meaning this is an edge that connects to the outside
            if (edges[i][j].size() == 2){
                graphEdges.insert({edges[i][j][0], edges[i][j][1], M});
            }

            //If equal to 3 then this means its a shared edge connecting 2 pens
            else if (edges[i][j].size() == 3){
                graphEdges.insert({edges[i][j][0], edges[i][j][1], edges[i][j][2]});
            }

        }

    }

    parent.resize(1001); size.resize(1001, 1);
    for (int i = 0; i < 1001; i++){
        parent[i] = i;
    }
    
    //Kruskals without going outside

    int cost1 = 0; int edgesUsed = 0;

    for (auto &edge: graphEdges){

        if (edge[2] == M) continue; //Ignore edges that go outside

        if (!find(edge[1], edge[2])){

            cost1 += edge[0]; edgesUsed++;
            Union(edge[1], edge[2]);

        }

        if (edgesUsed == M - 1) break;

    }

    //Kruskals going outside

    parent.clear(); size.clear();
    parent.resize(1001); size.resize(1001, 1);
    for (int i = 0; i < 1001; i++){
        parent[i] = i;
    }

    int cost2 = 0; int edgesUsed2 = 0;

    for (auto &edge: graphEdges){

        if (!find(edge[1], edge[2])){

            cost2 += edge[0]; edgesUsed2++;
            Union(edge[1], edge[2]);

        }

        if (edgesUsed2 == M) break; //MST will have nodes - 1 edges, since we're including the outside this time, there should be M edges

    }

    std::cout << std::min(cost1, cost2) << '\n';

    return 0;

}