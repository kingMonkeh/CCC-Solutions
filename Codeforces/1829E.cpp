#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

int n, m;
int grid [1002][1002];
int vis [1002][1002];

int solve(int i, int j){

    int ans = grid[i][j];

    vis[i][j] = 1;

    if (!vis[i + 1][j] && grid[i + 1][j] != 0){
        ans += solve(i + 1, j);
    }
    if (!vis[i - 1][j] && grid[i - 1][j] != 0){
        ans += solve(i - 1, j);
    }
    if (!vis[i][j + 1] && grid[i][j + 1] != 0){
        ans += solve(i, j + 1);
    }
    if (!vis[i][j - 1] && grid[i][j - 1] != 0){
        ans += solve(i, j - 1);
    }

    return ans;
    
}

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                std::cin >> grid[i][j];
                vis[i][j] = false;
            }
        }
        int lake = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (!vis[i][j] && grid[i][j] != 0){
                    lake = std::max(lake, solve(i, j));
                }
            }
        }
        std::cout << lake << '\n';
    }
    return 0;
}