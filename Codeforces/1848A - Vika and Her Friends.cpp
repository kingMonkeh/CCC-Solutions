#include <bits/stdc++.h>

/*

doggie woof woof problem

basically imagine chessboard coloring
if two guys are on opposite colors, they will never touch since the color cells they can go on never collide

therefore, if atleast 1 friend is on a cell that is the same color as Vika, she will get caught after some quantity of time

proof of this is atrocious, but in simple terms there's always a way to reduce the area that vika can move in until she's trapped

*/

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){
        int n, m, k, vikax, vikay;
        std::cin >> n >> m >> k >> vikax >> vikay;
        int color = (vikax + vikay) % 2;
        bool capture = false;
        for (int i = 0; i < k; i++){
            int x, y;
            std::cin >> x >> y;
            if ((x + y) % 2 == color) capture = true;
        }
        if (capture) std::cout << "NO\n";
        else std::cout << "YES\n";
    }
    
    return 0;
    
}