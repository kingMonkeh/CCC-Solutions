#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

/*

1 * 9
2 * 90
3 * 900
4 * 9000
5 * 90000

*/

std::string dir;
std::vector<std::vector<int>> vis (9, std::vector<int> (9, 0));
//up down left right
int up [4] = {-1, 1, 0, 0}, hor [4] = {0, 0, -1, 1};

int solve (int i, int r, int c){

    if (r == 7 && c == 1){
        if (i == 48) return 1;
        else return 0;
    }

    if (i == 48) return 0;

    if (vis[r][c - 1] && vis[r][c + 1] && !vis[r - 1][c] && !vis[r + 1][c]) return 0;
    if (!vis[r][c - 1] && !vis[r][c + 1] && vis[r - 1][c] && vis[r + 1][c]) return 0;

    vis[r][c] = true;

    int sum = 0;
    
    if (dir[i] == '?'){
        for (int j = 0; j < 4; j++){
            if (!vis[r + up[j]][c + hor[j]]){
                sum += solve (i + 1, r + up[j], c + hor[j]);
            }
        }
    }
    else if (dir[i] == 'R'){
        if (!vis[r][c + 1]){
            sum += solve (i + 1, r, c + 1);
        }
    }
    else if (dir[i] == 'L'){
        if (!vis[r][c - 1]){
            sum += solve (i + 1, r, c - 1);
        }
    }
    else if (dir[i] == 'D'){
        if (!vis[r + 1][c]) sum += solve (i + 1, r + 1, c);
    }
    else{
        if (!vis[r - 1][c]){
            sum += solve (i + 1, r - 1, c);
        }
    }
    
    vis[r][c] = false;
    return sum;
    
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> dir;

        for (int i = 0; i < 9; i++){
            vis[0][i] = true;
            vis[8][i] = true;
            vis[i][0] = true;
            vis[i][8] = true;
        }
        
        std::cout << solve (0, 1, 1);
        
    }

    return 0;
    
}