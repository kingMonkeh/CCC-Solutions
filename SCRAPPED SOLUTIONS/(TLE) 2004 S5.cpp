/*

2004 S5 - Super Plumber

Attempted recursive solution, instantly TLE'd

0/15 Marks

*/

#include <iostream>
#include <vector>
#include <string>

int m, n;
int answer = 0;
std::vector<std::string> grid;
std::vector<std::vector<bool>> visited;

void traverse(int row, int column, int money = 0){

    if (grid[row][column] != '.'){
        money += grid[row][column] - '0';
    }

    if (row == m - 1 && column == n - 1){
        answer = std::max(answer, money);
    }

    if (row - 1 >= 0 && grid[row - 1][column] != '*' && !visited[row - 1][column]){
        visited[row - 1][column] = true;
        traverse(row - 1, column, money);
        visited[row - 1][column] = false;
    }

    if (row + 1 < m && grid[row + 1][column] != '*' && !visited[row + 1][column]){
        visited[row + 1][column] = true;
        traverse(row + 1, column, money);
        visited[row + 1][column] = false;
    }

    if (column + 1 < n && grid[row][column + 1] != '*' && !visited[row][column + 1]){
        visited[row][column + 1] = true;
        traverse(row, column + 1, money);
        visited[row][column + 1] = false;
    }

}

int main(){

    while (true){

        std::cin >> m >> n;

        if (m == 0 && n == 0){
            break;
        }

        grid.resize(m);
        visited.resize(m, std::vector<bool> (n, false));

        for (int i = 0; i < m; i++){
            std::cin >> grid[i];
        }

        visited[m - 1][0] = true;
        traverse(m - 1, 0);
        std::cout << answer << '\n';

        grid.clear();
        visited.clear();
        answer = 0;

    }
    
    return 0;

}