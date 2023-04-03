/*

2018 S5 - Maximum Strategic Savings

Difficulty: Hard

I highly recommend that you read the editorial posted on dmoj for this problem
Still, it's a bit confusing and so I'll try my best to explain it in further detail

Basically we could try performining kruskals on every single individual edge
But the graph gets too big, so instead we think about it this way:

Take a single inputted edge, this edge is either repeated across every row, or every column
So instead of iterating over each duplicate of this edge, we can instead do them all at once.

To calculate the minimum number of edges we would need to use out of all the duplicates,
We keep track of how many rows or columns need to be merged, and this is exactly how many edges we need to connect the two rows or edges,
Therefore we multiply the weight w, by this amount, since all edges in the batch have weight w

To determine cycles in our Kruskals, we will have two union find sets
One representing the rows, named vertical, vertical[0] is the top row or row 0 and vertical[N] representing the last row/planet
The other union find set is called horizontal, it represents the cities from left to right

One may wonder how 2 1-D structures could possibly represent the large 2-D structure that the problem presents
But, recall that each edge we observe in Kruskals, takes into consideration all of its duplicates as well to ensure that either 2 rows are completely connected
or 2 columns are completely connected

This means, we only need to keep track of whether an entire row or column is merged

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//Kruskal's comparison operator
struct compare{
    bool operator() (std::vector<int> a, std::vector<int> b){
        return a[0] < b[0];
    }
} cmp;

//Cycle finding and Union Find
struct unionFind{

    std::vector<int> parent = std::vector<int> (100001);
    std::vector<int> size = std::vector<int> (100001, 1);

    //Root function
    int find(int x){
        if (parent[x] == x){
            return x;
        }
        else{
            return find(parent[x]);
        }
    }

    //Union
    void Union(int a, int b){
        int roota = find(a);
        int rootb = find(b);

        if (size[roota] > size[rootb]){
            parent[rootb] = roota;
            size[roota] += size[rootb];
        }

        else{
            parent[roota] = rootb;
            size[rootb] += size[roota];
        }

    }

} horizontal, vertical;

int main(){

    int N, M, P, Q;
    scanf("%d%d%d%d", &N, &M, &P, &Q);

    //Edge = {cost, a, b, type}
    std::vector<std::vector<int>> edges (P + Q);

    long long total = 0; //Total cost of all edges, including the ones we don't want

    //Flights
    for (int i = 0; i < P; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {c, a, b, 0};
        total += 1LL * c * N; //Note that the numbers get quite big
    }

    //Portals
    for (int i = 0; i < Q; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[P + i] = {c, a, b, 1};
        total += 1LL * c * M;
    }

    //Initialize parent arrays of the union find structures
    for (int i = 1; i <= N; i++){
        vertical.parent[i] = i;
    }

    for (int i = 1; i <= M; i++){
        horizontal.parent[i] = i;
    }

    //The following 2 lines can be ignored, they also initialize the parent arrays, just in a much cleaner method
    //std::iota(vertical.parent.begin(), vertical.parent.begin() + 1 + N, 0);
    //std::iota(horizontal.parent.begin(), horizontal.parent.begin() + 1 + M, 0);

    std::sort(edges.begin(), edges.end(), cmp);
    
    //rowsRemaining and colsRemaining, this will let us know how many of duplicate edges we need to fully connect two rows or columns
    int rowsRemaining = N, colsRemaining = M;
    long long optimalCost = 0; //Cost of the MST

    for (auto& edge: edges){

        //If a flight and no cycle created
        if (edge[3] == 0 && horizontal.find(edge[1]) != horizontal.find(edge[2])){
            horizontal.Union(edge[1], edge[2]);
            optimalCost += 1LL * edge[0] * rowsRemaining;
            colsRemaining--; //By connecting two cities in every planet, we can imagine it that these two columns in the 2-D array have been merged, meaning when we're adding a portal, it technically only needs to stem connect to one of these columns, since this city also connects to the other city and vice verca
        }

        //If a portal and no cycle created
        else if (edge[3] == 1 && vertical.find(edge[1]) != vertical.find(edge[2])){
            vertical.Union(edge[1], edge[2]);
            optimalCost += 1LL * edge[0] * colsRemaining;
            rowsRemaining--; //By connecting two planets, we only need flights connecting the cities on per groups of rows since from the cities in the planet with the flights, you can just take a portal to reach the same city on the other planet
        }
        
    }

    //Output answer, the difference in cost, aka how much was saved
    std::cout << total - optimalCost << '\n';
    
    return 0;
    
}