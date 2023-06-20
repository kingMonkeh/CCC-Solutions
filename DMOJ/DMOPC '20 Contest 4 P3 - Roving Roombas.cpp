/*

Difficulty: Hard

This problem is funny fenwick tree problem

Basically instead of using actual coords
We just gonna rank them from least to greatest

ie if we have {1, 3}, {5, 3} and {2, 7}
Their x's and y's ranked would be {1, 3}, {4, 3}, {2, 5}
because {1, 2, 3, 5, 7}, (their indices match)

Afterward, we're gonna sort the roombas and cords by their height

We will now create a fenwick tree to represent the x axis, note that it's not literaly the x axis
As we don't have enough memory for 1 billion points
Instead, its the x axis, but it uses the ranks we devised earlier to order points on the plane
Lastly, we go through each cord
For each cord:
Add all roombas that have height less than or equal to the current cord to our fenwick tree (we're adding their x values btw)
Afterward we will query the x value of the cord itself on the fenwick tree
Note that the fenwick tree computes the prefix sum, but the prefix sum is actually the number of roombas that did not touch the cord
Since their ranks are all less than that of the cords' x value

Therefore
answer += total number of roombas in the fenwick tree rn - query;

Output our answer afterward

*/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

std::map<long long, long long> RANK;
long long BIT [800005];

long long query (long long i){
    long long roombasNotTouching = 0;
    while (i){
        roombasNotTouching += BIT[i];
        i -= i & -i;
    }
    return roombasNotTouching;
}

void add (long long roomba){
    while (roomba < 800005){
        BIT[roomba]++;
        roomba += roomba & -roomba;
    }
}

int main() {
    long long N, M;
    std::cin >> N >> M;
    std::vector<std::pair<long long, long long>> roombas (N + 1), cords (M + 1);
    for (long long i = 1; i <= N; i++){
        std::cin >> roombas[i].first >> roombas[i].second;
        RANK[roombas[i].first] = 0; //remember map is already sorted
        RANK[roombas[i].second] = 0;
    }
    for (long long i = 1; i <= M; i++){
        std::cin >> cords[i].first >> cords[i].second;
        RANK[cords[i].first] = 0;
        RANK[cords[i].second] = 0;
    }
    //Update ranks
    long long pos = 1;
    for (auto& x: RANK){
        x.second = pos++;
    }
    //Actually give points their ranks now
    for (long long i = 1; i <= N; i++){
        roombas[i].first = RANK[roombas[i].first];
        roombas[i].second = RANK[roombas[i].second];
    }
    for (long long i = 1; i <= M; i++){
        cords[i].first = RANK[cords[i].first];
        cords[i].second = RANK[cords[i].second];
    }
    roombas[0] = {-1, -1};
    cords[0] = {-1, -1};
    //Sort increasing height
    std::sort(roombas.begin(), roombas.end(), [](std::pair<long long, long long>& a, std::pair<long long, long long>& b){return a.second < b.second;});
    std::sort(cords.begin(), cords.end(), [](std::pair<long long, long long>& a, std::pair<long long, long long>& b){return a.second < b.second;});
    
    //For each cord
    long long answer = 0;
    for (long long i = 1, j = 1; i <= M; i++){
        //For all roombas less than or equal height
        while (j <= N && roombas[j].second <= cords[i].second){
            add(roombas[j].first);
            j++; //j is not only our roomba index, it also tells us the amount of roombas currently considered
        }
        answer += j - query(cords[i].first - 1) - 1; // -1 since j++, therefore j will be 1 greater than it's supposed to be 
    }
    std::cout << answer << '\n';
    return 0;
}