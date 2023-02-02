/*

2001 J5/S3 - Strategic Bombing

Difficulty: Easy

Since the graph is at max 26 points, it suffices to try removing each road temporarily, check if it's still possible via DFS and then output the road depending on the result.

*/

#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <vector>

int main(){

    std::set<std::string> disconnecting_roads; //Store which roads are disconnecting roads
    std::set<std::string> possible_roads; //Stores all roads
    std::map<char, std::set<char>> roads; //Actually maps points to other points, roads[i] tell us what points we can go to from point i
    //Initialize the map
    roads['A'] = {}; roads['B'] = {}; roads['C'] = {}; roads['D'] = {}; roads['E'] = {}; roads['F'] = {}; roads['G'] = {}; roads['H'] = {}; roads['I'] = {}; roads['J'] = {}; roads['K'] = {}; roads['L'] = {}; roads['M'] = {}; roads['N'] = {}; roads['O'] = {}; roads['P'] = {}; roads['Q'] = {}; roads['R'] = {}; roads['S'] = {}; roads['T'] = {}; roads['U'] = {}; roads['V'] = {}; roads['W'] = {}; roads['X'] = {}; roads['Y'] = {}; roads['Z'] = {};

    //Collect roads
    while (true){

        std::string road; std::cin >> road;

        //If terminated input
        if (road == "**"){
            break;
        }

        int point1 = road[0], point2 = road[1];
        //Remember to add bothways
        roads[point1].insert(point2); roads[point2].insert(point1);
        possible_roads.insert(road);

    }

    //For each road
    for (std::string road: possible_roads){

        //Erase this road
        roads[road[0]].erase(road[1]);
        roads[road[1]].erase(road[0]);

        bool possible = false; //If it's still possible to reach point B from point A after having removed this road
        std::stack<char> s; //Stack
        std::map<char, bool> visited; //Keep track of visited points
        visited['A'] = false; visited['B'] = false; visited['C'] = false; visited['D'] = false; visited['E'] = false; visited['F'] = false; visited['G'] = false; visited['H'] = false; visited['I'] = false; visited['J'] = false; visited['K'] = false; visited['L'] = false; visited['M'] = false; visited['N'] = false; visited['O'] = false; visited['P'] = false; visited['Q'] = false; visited['R'] = false; visited['S'] = false; visited['T'] = false; visited['U'] = false; visited['V'] = false; visited['W'] = false; visited['X'] = false; visited['Y'] = false; visited['Z'] = false;
        s.push('A'); visited['A'] = true; //Initialize

        while (!s.empty()){

            char current_point = s.top();
            s.pop();

            //For all connecting points
            for (char point: roads[current_point]){

                //If not already visited
                if (!visited[point]){
                    s.push(point); //Add point
                    visited[point] = true; //Mark visited

                    //If we've made it to point B
                    if (point == 'B'){
                        possible = true;
                        break;
                    }

                }

            }

        }

        //If we couldn't make it to point B after removing the road
        if (possible == false){
            disconnecting_roads.insert(road);
        }

        //Undo our changes
        roads[road[0]].insert(road[1]);
        roads[road[1]].insert(road[0]);

    }

    //Output the disconnecting roads
    for (std::string road: disconnecting_roads){
        std::cout << road << '\n';
    }

    //End your input with a new line, otherwise DMOJ will mark it as WA even though it's correct. Remember that your answer must be exactly as stated, watch out for periods and capitals.
    std::cout << "There are " << disconnecting_roads.size() << " disconnecting roads." << '\n';

    return 0;

}