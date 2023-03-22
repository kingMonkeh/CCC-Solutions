/*

1999 S4 - A Knightly Pursuit

Difficulty: Medium/Hard

Basically, just do a breadth first search of the entire board starting from the knight
This well tell you to minimum moves to each square of the board

Key insight #1:
For any given square that the knight can visit, he can revisit that square in exactly 2 moves by going away and then coming back

This insight is useful, since this will allow us to detect kills and stalemates that do not take the minimum number of moves to reach a square
Rather they take (min moves to square) + 2m, where m is a repition of moves back and forth

Now, just simulate the pawns movement towards the top of the board
For every square he steps on, check if he can be killed or stalemated, otherwise, if he reaches the board untouched, it's a loss

*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 2147483

int main(){

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++){

        int r, c, pr, pc, kr, kc;
        std::cin >> r >> c >> pr >> pc >> kr >> kc;

        //Note that lists have row 0 at the top rather than at the bottom as the question states
        //We will just flip the input so that the knight and pawn will appear at the bottom of our 2-D vector rather than at the top
        //Also note that columns in the question use 1 indexing, while our vector uses 0 indexing, so we also need to shift the column left 1
        kr = r - kr;
        kc -= 1;

        std::vector<std::vector<int>> moves (r, std::vector<int> (c, INF)); //moves[r][c] tells us amount of moves to reach square on row r, column c
        std::vector<std::vector<bool>> visited (r, std::vector<bool> (c, false));
        std::queue<std::pair<int, int>> q; //<row, column>
        q.push({kr, kc}); visited[kr][kc] = true; moves[kr][kc] = 0;

        //BFS of knights movement to every square, basically just simulating his movement
        while (!q.empty()){

            std::pair<int, int> current = q.front(); q.pop();

            //2 up 1 left
            if (current.first - 2 >= 0 && current.second - 1 >= 0 && !visited[current.first - 2][current.second - 1]){
                q.push({current.first - 2, current.second - 1}); 
                visited[current.first - 2][current.second - 1] = true;
                moves[current.first - 2][current.second - 1] = moves[current.first][current.second] + 1;
            }

            //2 up 1 right
            if (current.first - 2 >= 0 && current.second + 1 < c && !visited[current.first - 2][current.second + 1]){
                q.push({current.first - 2, current.second + 1});
                visited[current.first - 2][current.second + 1] = true; 
                moves[current.first - 2][current.second + 1] = moves[current.first][current.second] + 1;
            }

            //2 down 1 left
            if (current.first + 2 < r && current.second - 1 >= 0 && !visited[current.first + 2][current.second - 1]){
                q.push({current.first + 2, current.second - 1});
                visited[current.first + 2][current.second - 1] = true; 
                moves[current.first + 2][current.second - 1] = moves[current.first][current.second] + 1;
            }

            //2 down 1 right
            if (current.first + 2 < r && current.second + 1 < c && !visited[current.first + 2][current.second + 1]){
                q.push({current.first + 2, current.second + 1});
                visited[current.first + 2][current.second + 1] = true; 
                moves[current.first + 2][current.second + 1] = moves[current.first][current.second] + 1;
            }

            //1 up 2 left
            if (current.first - 1 >= 0 && current.second - 2 >= 0 && !visited[current.first - 1][current.second - 2]){
                q.push({current.first - 1, current.second - 2}); 
                visited[current.first - 1][current.second - 2] = true;
                moves[current.first - 1][current.second - 2] = moves[current.first][current.second] + 1;
            }

            //1 up 2 right
            if (current.first - 1 >= 0 && current.second + 2 < c && !visited[current.first - 1][current.second + 2]){
                q.push({current.first - 1, current.second + 2}); 
                visited[current.first - 1][current.second + 2] = true;
                moves[current.first - 1][current.second + 2] = moves[current.first][current.second] + 1;
            }

            //1 down 2 left
            if (current.first + 1 < r && current.second - 2 >= 0 && !visited[current.first + 1][current.second - 2]){
                q.push({current.first + 1, current.second - 2}); 
                visited[current.first + 1][current.second - 2] = true;
                moves[current.first + 1][current.second - 2] = moves[current.first][current.second] + 1;
            }

            //1 down 2 right
            if (current.first + 1 < r && current.second + 2 < c && !visited[current.first + 1][current.second + 2]){
                q.push({current.first + 1, current.second + 2}); 
                visited[current.first + 1][current.second + 2] = true;
                moves[current.first + 1][current.second + 2] = moves[current.first][current.second] + 1;
            }

        }

        int win = INF, stalemate = INF;
        int move = 0; //Move number
        
        //For each pawns move
        for (int j = r - pr; j >= 0; j--){

            //Win
            //Note how we check % 2, to see if this square can actually be reached by going back and forth
            if (moves[j][pc - 1] % 2 == move % 2 && moves[j][pc - 1] <= move && j != 0){
                win = std::min(win, move);
            }

            //Stalemate
            else if (moves[j][pc - 1] % 2 == (move - 1) % 2 && moves[j][pc - 1] < move){
                stalemate = std::min(stalemate, move - 1);
            }

            move++;

        }

        if (win != INF){
            std::cout << "Win in " << win << " knight move(s).\n";
        }

        else if (stalemate != INF){
            std::cout << "Stalemate in " << stalemate << " knight move(s).\n";
        }

        else{
            std::cout << "Loss in " << move - 2 << " knight move(s).\n";
        }

        /*
        DEBUGGING IGNORE
        for (auto a: moves){
            for (auto &b: a){
                std::cout << b << ' ';
            }
            std::cout << '\n';
        }
        */

        moves.clear();

    }

    return 0;

}