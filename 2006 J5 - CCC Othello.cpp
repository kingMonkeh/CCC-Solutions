/*

Difficulty: annoying to implement, easy in terms of knowledge
just uh simulate it

let -1 mean no piece
let 0 mean white
let 1 mean black

*/

#include <iostream>
#include <string.h>

int board [10][10];

int main(){

    memset(board, -1, sizeof(board));
    char config;
    int N;
    std::cin >> config >> N;
    
    if (config == 'a'){
        board[4][4] = 0;
        board[4][5] = 1;
        board[5][4] = 1;
        board[5][5] = 0;
    }
    if (config == 'b'){
        for (int i = 1; i <= 8; i++){
            board[i][i] = 1;
            board[i][8 - i + 1] = 0;
        }
    }
    if (config == 'c'){
        for (int i = 1; i <= 8; i++){
            board[i][3] = 1;
            board[i][4] = 1;
            board[i][5] = 0;
            board[i][6] = 0;
        }
    }

    bool BLACK = true; //1
    while (N--){

        int R, C;
        std::cin >> R >> C;
        board[R][C] = BLACK;

        //Check left
        if (board[R][C - 1] == !BLACK){
            bool possible = false;
            int range;
            for (int i = C - 1; i > 0; i--){
                if (board[R][i] == -1){
                    break;
                }
                if (board[R][i] == BLACK){
                    possible = true;
                    range = i;
                    break;
                }   
            }
            if (possible){
                for (int i = C - 1; i > range; i--){
                    board[R][i] = BLACK;
                }
            }
        }
        
        //Check right
        if (board[R][C + 1] == !BLACK){
            bool possible = false;
            int range;
            for (int i = C + 1; i < 9; i++){
                if (board[R][i] == -1){
                    break;
                }
                if (board[R][i] == BLACK){
                    possible = true;
                    range = i;
                    break;
                }   
            }
            if (possible){
                for (int i = C + 1; i < range; i++){
                    board[R][i] = BLACK;
                }
            }
        }

        //Check up
        if (board[R - 1][C] == !BLACK){
            bool possible = false;
            int range;
            for (int i = R - 1; i > 0; i--){
                if (board[i][C] == -1){
                    break;
                }
                if (board[i][C] == BLACK){
                    possible = true;
                    range = i;
                    break;
                }   
            }
            if (possible){
                for (int i = R - 1; i > range; i--){
                    board[i][C] = BLACK;
                }
            }
        }

        //Check down
        if (board[R + 1][C] == !BLACK){
            bool possible = false;
            int range;
            for (int i = R + 1; i < 9; i++){
                if (board[i][C] == -1){
                    break;
                }
                if (board[i][C] == BLACK){
                    possible = true;
                    range = i;
                    break;
                }   
            }
            if (possible){
                for (int i = R + 1; i < range; i++){
                    board[i][C] = BLACK;
                }
            }
        }

        //Check top left
        if (board[R - 1][C - 1] == !BLACK){
            bool possible = false;
            int range = 0;
            int i = 0;
            while (true){
                if (board[R - 1 - i][C - 1 - i] == -1){
                    break;
                }
                if (board[R - 1 - i][C - 1 - i] == BLACK){
                    possible = true;
                    range++;
                    break;
                }   
                i++;
            }
            if (possible){
                for (int i = 0; i <= range; i++){
                    board[R - 1 - i][C - 1 - i] = BLACK;
                }
            }
        }

        //Check top right
        if (board[R - 1][C + 1] == !BLACK){
            bool possible = false;
            int range = 0;
            int i = 0;
            while (true){
                if (board[R - 1 - i][C + 1 + i] == -1){
                    break;
                }
                if (board[R - 1 - i][C + 1 + i] == BLACK){
                    possible = true;
                    range++;
                    break;
                }   
                i++;
            }
            if (possible){
                for (int i = 0; i <= range; i++){
                    board[R - 1 - i][C + 1 + i] = BLACK;
                }
            }
        }

        //Check bottom left
        if (board[R + 1][C - 1] == !BLACK){
            bool possible = false;
            int range = 0;
            int i = 0;
            while (true){
                if (board[R + 1 + i][C - 1 - i] == -1){
                    break;
                }
                if (board[R + 1 + i][C - 1 - i] == BLACK){
                    possible = true;
                    range++;
                    break;
                }   
                i++;
            }
            if (possible){
                for (int i = 0; i <= range; i++){
                    board[R + 1 + i][C - 1 - i] = BLACK;
                }
            }
        }

        //Check bottom right
        if (board[R + 1][C + 1] == !BLACK){
            bool possible = false;
            int range = 0;
            int i = 0;
            while (true){
                if (board[R + 1 + i][C + 1 + i] == -1){
                    break;
                }
                if (board[R + 1 + i][C + 1 + i] == BLACK){
                    possible = true;
                    range++;
                    break;
                }   
                i++;
            }
            if (possible){
                for (int i = 0; i <= range; i++){
                    board[R + 1 + i][C + 1 + i] = BLACK;
                }
            }
        }

        BLACK = !BLACK; //swap turns
        
    }
    
    int black = 0, white = 0;
    for (int i = 1; i < 9; i++){
        for (int j = 1; j < 9; j++){
            if (board[i][j] == 1){
                black++;
            }
            else if (board[i][j] == 0){
                white++;
            }
        }
    }

    std::cout << black << ' ' << white << '\n';
    
    return 0;
    
}