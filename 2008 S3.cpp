/*

2008 S3 - Maze

Difficulty: Easy

Problem is a very simple BFS problem. Just traverse the maze with breadth first search and restrict which nodes you can go to accordingly depending on the current node.

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main(){

    int t;
    std::cin >> t;

    //For each test case
    for (int i = 0; i < t; i++){

        int r, c;
        std::cin >> r >> c;

        std::vector<std::string> map (r); //I recommend using a new vector everytime, this helps prevent memory errors, otherwise you can clear and resize a vector repeatedly

        for (int j = 0; j < r; j++){
            std::cin >> map[j];
        }

        std::pair<int, int> start = {0, 0}; //Always start in top left corner
        std::queue<std::pair<int, int>> q; //Queue
        std::vector<std::vector<bool>> visited (r, std::vector<bool> (c, false)); //Keep track of where we've already visited
        std::vector<std::vector<int>> distance (r, std::vector<int> (c, -1)); //Keep track of distance from top left corner to this node, default to -1 to represent not possible
        q.push(start); visited[0][0] = true; distance[0][0] = 1; //Initial setup

        while (!q.empty()){

            std::pair<int, int> current_pos = q.front(); //Current position, current_pos.first = row number, current_pos.second = column number
            q.pop();

            //If we are on a '+', check all 4 directions, be careful for going out of bounds and remember to not add areas marked with '*' or areas that you've already visited.
            if (map[current_pos.first][current_pos.second] == '+'){

                //Up
                if (current_pos.first > 0 && current_pos.first < r && !visited[current_pos.first - 1][current_pos.second] && map[current_pos.first - 1][current_pos.second] != '*'){
                    q.push(std::make_pair(current_pos.first - 1, current_pos.second));
                    distance[current_pos.first - 1][current_pos.second] = distance[current_pos.first][current_pos.second] + 1; //Distance is the distance of previous node + 1
                    visited[current_pos.first - 1][current_pos.second] = true; //Mark as visited
                }

                //Down
                if (current_pos.first >= 0 && current_pos.first < r - 1 && !visited[current_pos.first + 1][current_pos.second] && map[current_pos.first + 1][current_pos.second] != '*'){
                    q.push(std::make_pair(current_pos.first + 1, current_pos.second));
                    distance[current_pos.first + 1][current_pos.second] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first + 1][current_pos.second] = true;
                }

                //Left
                if (current_pos.second > 0 && current_pos.second < c && !visited[current_pos.first][current_pos.second - 1] && map[current_pos.first][current_pos.second - 1] != '*'){
                    q.push(std::make_pair(current_pos.first, current_pos.second - 1));
                    distance[current_pos.first][current_pos.second - 1] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first][current_pos.second - 1] = true;
                }

                //Right
                if (current_pos.second >= 0 && current_pos.second < c - 1 && !visited[current_pos.first][current_pos.second + 1] && map[current_pos.first][current_pos.second + 1] != '*'){
                    q.push(std::make_pair(current_pos.first, current_pos.second + 1));
                    distance[current_pos.first][current_pos.second + 1] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first][current_pos.second + 1] = true;
                }

            }

            //Same concept as before, except we're only checking up and down since that's what is possible
            else if (map[current_pos.first][current_pos.second] == '|'){

                //Up
                if (current_pos.first > 0 && current_pos.first < r && !visited[current_pos.first - 1][current_pos.second] && map[current_pos.first - 1][current_pos.second] != '*'){
                    q.push(std::make_pair(current_pos.first - 1, current_pos.second));
                    distance[current_pos.first - 1][current_pos.second] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first - 1][current_pos.second] = true;
                }

                //Down
                if (current_pos.first >= 0 && current_pos.first < r - 1 && !visited[current_pos.first + 1][current_pos.second] && map[current_pos.first + 1][current_pos.second] != '*'){
                    q.push(std::make_pair(current_pos.first + 1, current_pos.second));
                    distance[current_pos.first + 1][current_pos.second] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first + 1][current_pos.second] = true;
                }

            }

            //If not '+' and not '|', it has to be '-' since we never add '*' to our BFS and it's stated that we will never start on a '*'. Check left and right only
            else{

                //Left
                if (current_pos.second > 0 && current_pos.second < c && !visited[current_pos.first][current_pos.second - 1] && map[current_pos.first][current_pos.second - 1] != '*'){
                    q.push(std::make_pair(current_pos.first, current_pos.second - 1));
                    distance[current_pos.first][current_pos.second - 1] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first][current_pos.second - 1] = true;
                }

                //Right
                if (current_pos.second >= 0 && current_pos.second < c - 1 && !visited[current_pos.first][current_pos.second + 1] && map[current_pos.first][current_pos.second + 1] != '*'){
                    q.push(std::make_pair(current_pos.first, current_pos.second + 1));
                    distance[current_pos.first][current_pos.second + 1] = distance[current_pos.first][current_pos.second] + 1;
                    visited[current_pos.first][current_pos.second + 1] = true;
                }

            }

        }

        //Output distance to bottom left corner, if no distance is possible, it will output -1 since that's the default distance value
        std::cout << distance[r - 1][c - 1] << '\n';

    }

    return 0;

}