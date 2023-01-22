/*

2018 S3 - RoboThieves

Difficulty: Medium

Topics: Graph Theory

So this problem is quite evidently a breadth first search problem since you have to traverse the entire factory starting from one point and you can only go to adjacent points up down left right

Tricky parts about this problem:
Cameras can only see empty space, and are stopped at a wall, they skip conveyors.
Conveyors. Conveyors can go in circles, so we must keep track of what we've already visited

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

std::vector<std::string> factory; //Store layout of factory
int N, M;

//Check for a camera, return true if a camera can see the robot, note that the factor always has walls as its perimeter
bool seen (int y, int x){

    //Check upwards from player, stop when a wall is hit
    for (int i = y - 1; i > -1 && factory[i][x] != 'W'; i--){

        if (factory[i][x] == 'C'){
            return true;
        }

    }

    //Check downwards
    for (int i = y + 1; i < N && factory[i][x] != 'W'; i++){

        if (factory[i][x] == 'C'){
            return true;
        }

    }

    //Check towards the left
    for (int i = x - 1; i > -1 && factory[y][i] != 'W'; i--){

        if (factory[y][i] == 'C'){
            return true;
        }

    }

    //Check towards the right
    for (int i = x + 1; i < M && factory[y][i] != 'W'; i++){

        if (factory[y][i] == 'C'){
            return true;
        }

    }

    return false;

}


int main(){

    std::cin >> N >> M;
    factory.resize(N);

    //Collect input
    for (int i = 0; i < N; i++){
        std::cin >> factory[i];
    }

    std::pair<int, int> startPos; //Represents robot's starting position
    for (int i = 0; i < N; i++){

        for (int j = 0; j < M; j++){

            if (factory[i][j] == 'S'){
                startPos = std::make_pair(i, j);
            }

        }

    }

    std::vector<std::vector<int>> distances (N, std::vector<int> (M, -1)); //Storing distance to each place in the factory, default to -1 since it indicates impossible
    std::vector<std::vector<bool>> alreadyVisited (N, std::vector<bool> (M, false)); //Keeping track of what has been visited

    std::queue<std::pair<int, int>> q; //Using queue, preparing for Breadth First Search since we're trying to find the minimum distance
    q.push(startPos); //Add start
    alreadyVisited[startPos.first][startPos.second] = true; //Mark start as visited

    int distance = 0; //Keep track of depth of breadth first search

    //This is just for iterating over up, right, left, down, you'll understand once you read the loop
    const int xShift[4] = {0, 1, 0, -1};
    const int yShift[4] = {1, 0, -1, 0};
    
    //You can spawn beside a camera
    if (!seen(startPos.first, startPos.second)){

        while (!q.empty()){
    
            int size = q.size(); //To search for just this horizontal level of the graph
            
            for (int i = 0; i < size; i++){
    
                std::pair<int, int> currentPos = q.front();
                q.pop();
                
                distances[currentPos.first][currentPos.second] = distance; //Set distance
    
                for (int j = 0; j < 4; j++){
    
                    //Check up right left down, here's where the shifts are used
                    std::pair<int, int> possibleLocation = std::make_pair(currentPos.first + yShift[j], currentPos.second + xShift[j]);
    
                    if (alreadyVisited[possibleLocation.first][possibleLocation.second]){
                        continue;
                    }
                    
                    char letter = factory[possibleLocation.first][possibleLocation.second]; //Check letter
                    //If on a conveyor
                    while (!alreadyVisited[possibleLocation.first][possibleLocation.second] && letter != '.' && letter != 'W' && letter != 'C'){
                        
                        alreadyVisited[possibleLocation.first][possibleLocation.second] = true;
                        
                        if (letter == 'U'){
                            possibleLocation.first--;
                        }
                        
                        else if (letter == 'D'){
                            possibleLocation.first++;
                        }
                        
                        else if (letter == 'L'){
                            possibleLocation.second--;
                        }
                        
                        else if (letter == 'R'){
                            possibleLocation.second++;
                        }
                        
                        letter = factory[possibleLocation.first][possibleLocation.second];
                        
                    }
                    
                    if (alreadyVisited[possibleLocation.first][possibleLocation.second]){
                        continue;
                    }
                    
                    alreadyVisited[possibleLocation.first][possibleLocation.second] = true; //Very important that you mark locations that have already been visited
    
                    //Add unexplored areas
                    if (letter == '.' && !seen(possibleLocation.first, possibleLocation.second)){
                        q.push(possibleLocation);
                    }
    
                }
    
                
                
    
            }
       
            distance++; //Increase depth
            
        }
        
    }

    //Print our answer
    for (int i = 0; i < N; i++){

        for (int j = 0; j < M; j++){

            if (factory[i][j] == '.'){
                std::cout << distances[i][j] << '\n';
            }

        }

    }

    return 0;

}

