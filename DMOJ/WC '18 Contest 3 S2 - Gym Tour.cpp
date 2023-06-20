#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

/*

Another similar problem: CCC '16 S3 - Phonomenal Reviews

Pseudo Code
Try without Dragonite
1. Trim tree until all leaf nodes are gyms
2. Find furthest gym
3. Ans = 2 * Roads - diameter of tree

Explanation: start from 1, ignore all roads that aren't in the optimal (ie their subtree does not contain a gym)
traverse entire graph
Imagine you must walk back to town 1 at the very end
That means you walk double the amount of edges
But since you can end at the final gym
You want to maximize the distance between town 1 and the gym you end at, hence furthest gym

Try with Dragonite
1. Trim tree, keep Dragonite though
2. Ans = Number of roads
Same idea as before, except thanks to dragonites ability to return to previous towns in 0 days
You don't need to walk balkwards on the edges
Thus the answer is just the number of useful edges

Take min of the 2

*/

//towns, gyms, dragonite
int N, K, F;
std::vector<std::vector<int>> roads (100005);
int gyms [100005];

int max_dist = 0;
int important_roads = -1;

bool cut (int town, int prev, int dist){

    //Leaf node
    if (roads[town].size() == 1 && roads[town][0] == prev){
        if (gyms[town]){
            important_roads++;
            max_dist = std::max(max_dist, dist);
            return true;
        }
        else{
            return false;
        }
    }

    //Just needs to contain at least 1 gym in subtree
    bool important = false;
    for (int& dest: roads[town]){
        if (dest != prev){
            important = cut(dest, town, dist + 1) || important;
        }
    }

    if (important || gyms[town]){
        important_roads++;
        max_dist = std::max(max_dist, dist);
        return true;
    }
    else{
        return false;
    }
    
}

int main(){
    memset(gyms, 0, sizeof(gyms));
    std::cin >> N >> K >> F;
    for (int i = 0; i < K; i++){
        int gym;
        std::cin >> gym;
        gyms[gym] = 1;
    }
    for (int i = 0; i < N - 1; i++){
        int a, b;
        std::cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    cut(1, -1, 0);
    int answer = 2 * important_roads - max_dist;
    gyms[F] = 1;
    important_roads = -1, max_dist = 0;
    cut(1, -1, 0);
    answer = std::min(answer, important_roads);
    std::cout << answer << '\n';
    return 0;
}