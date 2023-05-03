/*

2003 S5 - Trucking Troubles

Difficulty: Easy/Medium

This problem is like textbook level Kruskal's
Quite literaly, all you have to do is just use kruskal's
But instead of sorting least to greatest weight
You do greatest to least since you're trying to get maximum weight
Note that you also don't need to construct a full tree, you just need enough to connect all the destinations

*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string.h>

int parent [100001];
int size [100001];

//Sort greatest to least
struct reverseSort{
    bool operator()(std::vector<int> const& a, std::vector<int> const& b){
        return a[0] > b[0];
    }
};

//Union Find
int root(int city){
    if (parent[city] == city){
        return city;
    }
    else{
        return root(parent[city]);
    }
}

void Union (int x, int y){

    int parX = root(x);
    int parY = root(y);

    if (size[parX] > size[parY]){
        parent[parY] = parX;
        size[parX] += size[parY];
    }

    else{
        parent[parX] = parY;
        size[parY] += size[parX];
    }
        
}

int find(int x, int y){
    int parX = root(x);
    int parY = root(y);

    if (parX == parY){
        return true;
    }

    else{
        return false;
    }
    
}

int main(){

    int c, r, d;
    std::cin >> c >> r >> d;

    int required [10001]; //Keep track of what cities are required
    std::vector<std::vector<int>> roads; //2-D vector holding roads
    
    for (int i = 0; i < r; i++){
        int x, y, w;
        std::cin >> x >> y >> w;
        roads.push_back({w, x, y}); //road is a vector where {weight, city x, city y}
    }

    memset(required, 0, sizeof(required)); //default required
    memset(size, 1, sizeof(size)); //default size
    //init parent array
    for (int i = 1; i <= 100000; i++){
        parent[i] = i;
    }

    //Get required cities
    int total = 1;
    required[1] = 1;
    for (int i = 0; i < d; i++){
        int city;
        std::cin >> city;
        required[city] = 1;
        total++;
    }

    //Sort edges
    std::sort(roads.begin(), roads.end(), reverseSort());

    int max = 2e7; //answer variable
    for (auto road: roads){

        //If we've connected all the required cities
        if (total == 0){
            break;
        }

        //No cycle
        if (!find(road[1], road[2])){

            Union(road[1], road[2]);

            //If a required city, subtract from the total, mark as found
            if (required[road[1]]){
                total--;
                required[road[1]] = 0;
            }
    
            if (required[road[2]]){
                total--;
                required[road[2]] = 0;
            }

            //Update max
            max = std::min(max, road[0]);
            
        }

    }

    std::cout << max << '\n';
    
    return 0;
    
}