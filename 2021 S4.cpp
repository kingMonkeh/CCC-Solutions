#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define INFINITY 100000000

/*
CCC 2021 S4 - Daily Commute
This is a breadth first search problem (BFS).
Important things to note that will help us create our algorithm:
1. You will only ever leave the train once at max, because if you get off the train and use a walkway to get ahead but do not reach station N, you'll have to wait for the train to catch up effectively taking the same time as if you never left to begin with
2. The time it takes to walk from station i to station N remains constant regardless of station placement, this defies all logic but it's what the question states
3. For each day, you only need to calculate the new times for the 2 new stations, nothing else has changed
4. The base time each day must be the time it takes to go from station 1 to station N by train only

Therefore, the optimal solution is either the base time, or a combination of train + walkways that allows the user to get to station N faster
Total distance for each station in the route = Subway to station i time + station i to station N walking time supposing there's a path

To determine the walking times we will use a breadth first search
We will use a multiset to store the total times because the question is not asking for index, instead it's asking for the minimum time which is perfect
*/

int main(){

    int N, W, D;
    std::cin >> N >> W >> D;

    std::vector<int> walkways[N + 1]; //array of vectors, walkways[n] is a vector containing all connecting stations to station n

    for (int i = 0; i < W; i++){
        int start, stop;
        std::cin >> start >> stop;
        walkways[stop].push_back(start); //Append in reverse for the breadth first search
    }

    //Calculate walking time from station i to station N
    //Breadth First Search

    std::queue<int> stack;
    std::vector<bool> alreadyvisited(N + 1, false); //to prevent revisiting the same node
    std::vector<int> walkwaytimes(N + 1, INFINITY); //INF to help us sort our multiset later, indicates there's no possible walkway
    walkwaytimes[N] = 0;
    alreadyvisited[N] = 1;
    stack.push(N);
    int time = 0;

    while(stack.empty() != true){

        int curstation = stack.front();
        stack.pop();

        for (const int connectingstation: walkways[curstation]){

            if (!alreadyvisited[connectingstation]){
                walkwaytimes[connectingstation] = walkwaytimes[curstation] + 1; //Connecting stations will always be 1 more minute away from the current station
                stack.push(connectingstation);
            }

            alreadyvisited[connectingstation] = true;

        }

    }

    //Calculate initial time for subway route
    std::vector<int> subwayroute(N + 1);
    //indices don't matter for this problem as we're only searching for the minimum time, making multiset extremely useful here as it sorts the times and allows for quick erasing and insertion of elements
    std::multiset<int> cumulativeTime; 
    subwayroute[0] = 0; //Dummy value

    for (int i = 1; i < N + 1; i++){
        std::cin >> subwayroute[i];
        cumulativeTime.insert(i - 1 + walkwaytimes[subwayroute[i]]); //calculate cumulative time = subway to station i + walking distance from i to N
    }

    int temp;
    int value;
    //Determining minimum time each day
    for (int d = 0; d < D; d++){
        int changes1, changes2;
        std::cin >> changes1 >> changes2;

        //Erase previous times for swapped stations that are to be swapped
        value = changes1 - 1 + walkwaytimes[subwayroute[changes1]];
        cumulativeTime.erase(cumulativeTime.find(value)); //important that .find() is used because otherwise all instances of the value would be removed

        value = changes2 - 1 + walkwaytimes[subwayroute[changes2]];
        cumulativeTime.erase(cumulativeTime.find(value));

        //Swap stations
        temp = subwayroute[changes1];
        subwayroute[changes1] = subwayroute[changes2];
        subwayroute[changes2] = temp;

        //Add new times
        cumulativeTime.insert(changes1 - 1 + walkwaytimes[subwayroute[changes1]]);
        cumulativeTime.insert(changes2 - 1 + walkwaytimes[subwayroute[changes2]]);

        std::cout << *cumulativeTime.begin() << '\n'; //multiset is always ordered meaning the minimum time is always at the front
    }

    return 0;
}