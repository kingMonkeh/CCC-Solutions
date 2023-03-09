/*

2012 S4 - A Coin Game

Difficulty: Medium/Hard

This problem is a breadth first search problem. Essentially since there are such few coins, you can just brute force every possible combination of moves.

The main problem is how we will be storing the coins since a it would be costly to be passing new vectors into a queue

Instead, we will be representing coins using a string
Note that this only works since there's not more than 9 coins

Lets call the string s
s[0] will tell us the position of coin 1
s[1] will tell us the position of coin 2
...

You can now see how we can represent the coins very easily.

Now, the hard part, determining what coins can move given a string

To do this, for the current coin
1. Determine its actual position. e.g. s[1] = 7, the actual position is 7
2. Determine what coins are left and right of the actual position
Note that you should only take the first occurence, since that would be the lowest value coin which would have to be at the top
3. Determine if the coin can move on top of the other coins

Now you can perform a regular breadth first search, adding new possible strings and marking them as visited using a map.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

int main(){

    while (true){

        int n; std::cin >> n;

        if (!n){
            break;
        }

        std::string coins;
        std::string correct; //A string of what the correct arrangement should look like

        for (int i = 1; i <= n; i++){

            coins += ' ';
            correct += std::to_string(i);

        }


        for (int i = 0; i < n; i++){

            int coin;
            std::cin >> coin;
            coins[coin - 1] = '0' + i + 1; //Since string, we need to convert int to char

        }

        std::unordered_map<int, bool> visited; //Keep track of what strings have been tried, note that default value of bool map is false
        std::unordered_map<int, int> moves; //Keep track of how many moves have been made so far
        std::queue<std::string> q;
        q.push(coins);
        visited[std::stoi(coins)] = true;
        moves[std::stoi(coins)] = 0;
        
        bool possible = false; //Determine if it's even possible to obtain the correct arrangement
        while (!q.empty()){

            std::string currentArrangement = q.front();
            q.pop();

            //If it matches the correct arrangement, aka solved
            if (currentArrangement == correct){

                std::cout << moves[std::stoi(currentArrangement)] << '\n';
                possible = true;
                break;

            }

            //Remember how we can only move the coin at the top of a stack at a position
            //Therefore after we encounter a single count found at a position, all other coins at that position should be impossible to move
            std::vector<bool> visitedpositions (9, false);

            for (int i = 0; i < currentArrangement.length(); i++){

                int currentCoinPos = currentArrangement[i] - '0';

                if (visitedpositions[currentCoinPos]) continue;
                visitedpositions[currentCoinPos] = true;

                //Check if there's a coin to the right
                if (currentCoinPos < currentArrangement.length()){

                    std::size_t rightCoin = currentArrangement.find(std::to_string(currentCoinPos + 1));
                    //Remember that we can move if there's no coin there or if our coin is less than
                    if (rightCoin == std::string::npos || rightCoin + 1 > i + 1){

                        std::string arrangement = currentArrangement;
                        arrangement[i] = '0' + currentCoinPos + 1;
                        if (!visited[std::stoi(arrangement)]){

                            q.push(arrangement);
                            visited[std::stoi(arrangement)] = true;
                            moves[std::stoi(arrangement)] = moves[std::stoi(currentArrangement)] + 1;

                        } 

                    }

                }

                //If there's a coin to the left
                if (currentCoinPos > 1){

                    std::size_t leftCoin = currentArrangement.find(std::to_string(currentCoinPos - 1));
                    if (leftCoin == std::string::npos || leftCoin + 1 > i + 1){

                        std::string arrangement = currentArrangement;
                        arrangement[i] = '0' + currentCoinPos - 1;
                        if (!visited[std::stoi(arrangement)]){

                            q.push(arrangement);
                            visited[std::stoi(arrangement)] = true;
                            moves[std::stoi(arrangement)] = moves[std::stoi(currentArrangement)] + 1;

                        } 

                    }

                }

            }

        }

        //If we were unable to obtain the correct arrangement, output impossible
        if (!possible) std::cout << "IMPOSSIBLE\n";

    }

    return 0;

}