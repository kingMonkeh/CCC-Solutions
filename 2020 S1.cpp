/*

Difficulty: Easy

Ad Hoc Problem

There's no special algorithm needed, quite literaly just implement the situation of the problem in your code

Algorithm:
1. Collect input
2. Order times accordingly, recommended data structures: sets and maps
3. Calculate each speed, keep track of which is the max. Use set or use a maximum variable + if statement to do this.

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <map>

int main(){

    //Collect input
    int N;

    std::cin >> N;

    std::set<double> time;
    std::map<double, double> position;
    std::set<double> speed;

    //Insert times into set so they're ordered, map their time to the corresponding position
    for (int i = 0; i < N; i++){

        int t, p;

        std::cin >> t >> p;

        time.insert(t);
        position[t] = p;

    }

    //Copy the ordered set to a vector for easier indexing

    std::vector<int> orderedTime;
    for (auto it = time.begin(); it != time.end(); it++){

        orderedTime.push_back(*it);

    }

    //Calculate each speed
    for (int i = 1; i < N; i++){
        
        double currentSpeed = std::abs(position[orderedTime[i]] - position[orderedTime[i - 1]]) / (orderedTime[i] - orderedTime[i - 1]);
        speed.insert(currentSpeed); //Add to set so that it's ordered

    }        

    //Since set is ordered, just output the last item in the set which is the greatest value
    std::cout << *speed.rbegin();

    return 0;

}