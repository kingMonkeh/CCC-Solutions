/*

2023 J5 - CCC Word Hunt
Difficulty: Medium

This question is very different from previous years
It does not require any computer science knowledge to be completed
Just a sold ability to program

Basic idea
Since the word is stated to be made up of distinct letters, we basically just try searching from every possible starting point on the grid

There's 8 cases
up down left right upleft upright downleft downright

To solve this i will write 8 recursive functions
Let a function be defined as
dir (i, j, progress, turned)
where i represents the current row
j represents the current column
progress tells us how many letters of the word we've found so far
and turned tells us whether or not we've turned yet

for each dir function
There's three cases

1. we continue in the same direction, we just call the function again
2. we go 90 degrees one way
3. we go 90 degrees the other way

To turn 90 degrees, we must have it such that we have not turned yet
Lastly, all we have to do is ensure we're in bounds at all times

Code is lengthy, but not complex by any means.

*/

#include <iostream>
#include <string>
#include <vector>

char grid [100][101];
int R, C;
std::string word;

int ans = 0;

void up (int i, int j, int progress, bool turned);
void down (int i, int j, int progress, bool turned);
void right (int i, int j, int progress, bool turned);
void left (int i, int j, int progress, bool turned);
void upleft (int i, int j, int progress, bool turned);
void upright (int i, int j, int progress, bool turned);
void downleft (int i, int j, int progress, bool turned);
void downright (int i, int j, int progress, bool turned);

void up (int i, int j, int progress, bool turned){

    if (progress == word.length() - 1){
        ans++;
        return;
    }

    //Continue up
    if (i > 0 && grid[i - 1][j] == word[progress + 1]){
        up(i - 1, j, progress + 1, turned);
    }
    //Left
    if (j > 0 && !turned && grid[i][j - 1] == word[progress + 1]){
        left(i, j - 1, progress + 1, !turned);
    }
    //Right
    if (j < C - 1 && !turned && grid[i][j + 1] == word[progress + 1]){
        right(i, j + 1, progress + 1, !turned);
    }
    
}

void right (int i, int j, int progress, bool turned){
    
    if (progress == word.length() - 1){
        ans++;
        return;
    }
    
    //continue right
    if (j < C - 1 && grid[i][j + 1] == word[progress + 1]){
        right(i, j + 1, progress + 1, turned);
    }
    //up
    if (i > 0 && !turned && grid[i - 1][j] == word[progress + 1]){
        up(i - 1, j, progress + 1, !turned);
    }
    //down
    if (i < R - 1 && !turned && grid[i + 1][j] == word[progress + 1]){
        down(i + 1, j, progress + 1, !turned);
    }
    
}

void down (int i, int j, int progress, bool turned){

    if (progress == word.length() - 1){
        ans++;
        return;
    }

    //continue down
    if (i < R - 1 && grid[i + 1][j] == word[progress + 1]){
        down(i + 1, j, progress + 1, turned);
    }
    //left
    if (j > 0 && !turned && grid[i][j - 1] == word[progress + 1]){
        left(i, j - 1, progress + 1, !turned);
    }
    //right
    if (j < C - 1 && !turned && grid[i][j + 1] == word[progress + 1]){
        right(i, j + 1, progress + 1, !turned);
    }
}

void left (int i, int j, int progress, bool turned){
    
    if (progress == word.length() - 1){
        ans++;
        return;
    }

    //left
    if (j > 0 && grid[i][j - 1] == word[progress + 1]){
        left(i, j - 1, progress + 1, turned);
    }
    //up
    if (i > 0 && !turned && grid[i - 1][j] == word[progress + 1]){
        up(i - 1, j, progress + 1, !turned);
    }
    //down
    if (i < R - 1 && !turned && grid[i + 1][j] == word[progress + 1]){
        down(i + 1, j, progress + 1, !turned);
    }
    
}

//Up left
void upleft (int i, int j, int progress, bool turned){

    if (progress == word.length() - 1){
        ans++;
        return;
    }

    //Continue up left
    if (i > 0 && j > 0 && grid[i - 1][j - 1] == word[progress + 1]){
        upleft(i - 1, j - 1, progress + 1, turned);
    }
    //turn up right
    if (i > 0 && !turned && j < C - 1 && grid[i - 1][j + 1] == word[progress + 1]){
        upright(i - 1, j + 1, progress + 1, !turned);
    }
    //turn down left
    if (i < R - 1 && j > 0 && !turned && grid[i + 1][j - 1] == word[progress + 1]){
        downleft(i + 1, j - 1, progress + 1, !turned);
    }
    
}
//Up right
void upright (int i, int j, int progress, bool turned){

    if (progress == word.length() - 1){
        ans++;
        return;
    }
    //continue
    if (i > 0 && j < C - 1 && grid[i - 1][j + 1] == word[progress + 1]){
        upright(i - 1, j + 1, progress + 1, turned);
    }
    //upleft
    if (i > 0 && j > 0 && !turned && grid[i - 1][j - 1] == word[progress + 1]){
        upleft(i - 1, j - 1, progress + 1, !turned);
    }
    //downright
    if (i < R - 1 && j < C - 1 && !turned && grid[i + 1][j + 1] == word[progress + 1]){
        downright(i + 1, j + 1, progress + 1, !turned);
    }
    
}
//Down left
void downleft (int i, int j, int progress, bool turned){
    
    if (progress == word.length() - 1){
        ans++;
        return;
    }

    //continue
    if (i < R - 1 && j > 0 && grid[i + 1][j - 1] == word[progress + 1]){
        downleft(i + 1, j - 1, progress + 1, turned);
    }
    //upleft
    if (i > 0 && j > 0 && !turned && grid[i - 1][j - 1] == word[progress + 1]){
        upleft(i - 1, j - 1, progress + 1, !turned);
    }
    //downright
    if (i < R - 1 && j < C - 1 && !turned && grid[i + 1][j + 1] == word[progress + 1]){
        downright(i + 1, j + 1, progress + 1, !turned);
    }
    
}

//Down right
void downright (int i, int j, int progress, bool turned){
    
    if (progress == word.length() - 1){
        ans++;
        return;
    }

    //continue
    if (i < R - 1 && j < C - 1 && grid[i + 1][j + 1] == word[progress + 1]){
        downright(i + 1, j + 1, progress + 1, turned);
    }
    //upright
    if (i > 0 && !turned && j < C - 1 && grid[i - 1][j + 1] == word[progress + 1]){
        upright(i - 1, j + 1, progress + 1, !turned);
    }
    //downleft
    if (i < R - 1 && j > 0 && !turned && grid[i + 1][j - 1] == word[progress + 1]){
        downleft(i + 1, j - 1, progress + 1, !turned);
    }
    
}

int main(){
    std::cin >> word >> R >> C;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            std::cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (grid[i][j] == word[0]){
                //up
                if (i > 0 && grid[i - 1][j] == word[1]){
                    up(i - 1, j, 1, false);
                }
                //continue down
                if (i < R - 1 && grid[i + 1][j] == word[1]){
                    down(i + 1, j, 1, false);
                }
                //continue right
                if (j < C - 1 && grid[i][j + 1] == word[1]){
                    right(i, j + 1, 1, false);
                }
                //left
                if (j > 0 && grid[i][j - 1] == word[1]){
                    left(i, j - 1, 1, false);
                }
                //upleft
                if (i > 0 && j > 0 && grid[i - 1][j - 1] == word[1]){
                    upleft(i - 1, j - 1, 1, false);
                }
                //upright
                if (i > 0 && j < C - 1 && grid[i - 1][j + 1] == word[1]){
                    upright(i - 1, j + 1, 1, false);
                }
                //downleft
                if (i < R - 1 && j > 0 && grid[i + 1][j - 1] == word[1]){
                    downleft(i + 1, j - 1, 1, false);
                }
                //downright
                if (i < R - 1 && j < C - 1 && grid[i + 1][j + 1] == word[1]){
                    downright(i + 1, j + 1, 1, false);
                }
            }
        }
    }

    std::cout << ans << '\n';
    
    return 0;
}