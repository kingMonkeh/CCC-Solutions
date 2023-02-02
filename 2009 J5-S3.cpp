/*

2009 J5/S3 - Degrees Of Separation

Difficulty: Medium

This question is not that difficult knowledge wise. It's just really annoying to implement.

General idea:
Implement the given graph
Add any friendships and delete friendships accordingly
The number of friends that person x has is the number of edges its node has on the graph
To determine the friends of friends, it suffices to iterate over each friend and add their friends to a set, this will ensure no duplicated are added
Lastly, to determine the degree of separation, perform a bfs since it will return minimum distance

*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

std::vector<std::set<int>> connections (50); //connections[i] is a set that contains all the people that are friends with person i

//Add friendships
void connect(int x, int y){
    
    //Remember edges on the graph go both ways
    connections[x].insert(y);
    connections[y].insert(x);
    
}

//Delete friendships
void unfriend(int x, int y){
    
    connections[x].erase(y);
    connections[y].erase(x);
    
}

//Find total friends of friends
int friendsOfFriends(int x){
    
    std::set<int> friends_of_friends; //Store the friends of friends
    
    //For each friend of person x
    for (auto it = connections[x].begin(); it != connections[x].end(); it++){

        //For each friend's friend        
        for (auto it2 = connections[*it].begin(); it2 != connections[*it].end(); it2++){

            //If the friend of a friend is not person x's friend and is not person x themselves, add friend of friend        
            if (connections[x].count(*it2) == 0 && *it2 != x){
                friends_of_friends.insert(*it2);
            }
                    
        }
                
    }
    
    //Since set has no duplicates, the size of the set will represent the total amount of friends of friends
    return friends_of_friends.size();
    
}

//Find degree of seperation
int degreeOfSeperation(int x, int y){
    
    std::queue<int> q; //Initialize queue
    std::vector<bool> alreadyVisited (50, false); //Mark visited nodes on the graph
    std::vector<int> distances (50); //distances[i] represents the degree of seperation between person x and person i
    
    alreadyVisited[x] = true; //Mark person x as visited
    q.push(x); //Get queue started
    distances[x] = 0; //Mark person x distance as 0

    while (!q.empty()){
        int Friend = q.front();
        q.pop();
        
        //If node is target node
        if (Friend == y){
            return distances[Friend]; //return degree of separation if reachable
        }
        
        //For this persons friends
        for (auto it = connections[Friend].begin(); it != connections[Friend].end(); it++){
            if (!alreadyVisited[*it]){
                q.push(*it);
                distances[*it] = distances[Friend] + 1; //Degree of seperation is the previous nodes degree of separation + 1
            }
            alreadyVisited[*it] = true; //mark visited
        }
    
    }
    
    return -1; //return -1 to indicate there's no path
    
}

int main(){
    
    //Implement the given graph
    connect(2, 6);
    connect(1, 6);
    connect(6, 7);
    connect(6, 3);
    connect(6, 4);
    connect(6, 5);
    connect(3, 4);
    connect(4, 5);
    connect(5, 3);
    connect(3, 15);
    connect(15, 13);
    connect(13, 12);
    connect(13, 14);
    connect(7, 8);
    connect(8, 9);
    connect(9, 10);
    connect(9, 12);
    connect(10, 11);
    connect(11, 12);
    connect(16, 17);
    connect(16, 18);
    connect(17, 18);
    
    //Take instructions until q
    while (true){
        
        char instruction;
        int x, y;
        
        std::cin >> instruction;
        
        //If end
        if (instruction == 'q'){
            break;
        }
        
        //Connect
        if (instruction == 'i'){
            std::cin >> x >> y;
            connect(x, y);
        }
        
        //Unfriend
        if (instruction == 'd'){
            std::cin >> x >> y;
            unfriend(x, y);
        }
        
        //Number of friends
        if (instruction == 'n'){
            std::cin >> x;
            std::cout << connections[x].size() << '\n'; //Count of all their node's edges
        }
        
        //Friends of friends
        if (instruction == 'f'){
            std::cin >> x;
            int friendsfriends = friendsOfFriends(x);
            std::cout << friendsfriends << '\n';
        }
        
        //Degree of separation
        if (instruction == 's'){
            std::cin >> x >> y;
            int degree = degreeOfSeperation(x, y);
            
            //-1 indicates no possible path
            if (degree == -1){
                std::cout << "Not connected" << '\n';
            }
            
            else{
                std::cout << degree << '\n';
            }
            
        }
        
    }
    
    return 0;
    
}
