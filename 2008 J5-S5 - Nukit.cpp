/*

2008 J5/S5 - Nukit

Difficulty: Medium or Hard depends on whether you do J5 or S5

The idea is a bit weird and wonky

Essentially what makes a winning position?
A winning position is one that causes a losing solution

But if a position causes a winning position, then this position must be a losing position
Since you've created a winning position for your enemy

With this logic we can now solve the problem recursively
We will recurse until we hit a final position in which no more moves can be made
We will have it recurse one level deeper in which the a, b, c, d values will go negative

When this is the case, this means we've reached a dead end
We will return true, not to indicate that this is a winning position
But to indicate that the position before it is a losing position

S5 ADDITIONAL

In S5, you just have to be faster
We will use the same logic, but just memoize whether a certain position is winning or losing inside of an array
That is, we will create 4-D DP array where dp[a][b][c][d] tells us whether position a b c d is winning or losing
We will default the value to -1 to mark it as unsolved

*/

#include <iostream>
#include <string.h>

int dp[31][31][31][31];

bool solve(int a, int b, int c, int d){
    
    //Dead end, the extra recurse will get caught here
    if (a < 0 || b < 0 || c < 0 || d < 0){
        return true; //To indicate the previous position was a losing position
    }

    //Check if we've already solved
    if (dp[a][b][c][d] != -1){
        return dp[a][b][c][d];
    } 

    bool winning = false;

    //A winning position only needs to create 1 losing position, since it can always force it to this losing position
    winning = winning || !solve(a - 2, b - 1, c, d - 2);
    winning = winning || !solve(a - 1, b - 1, c - 1, d - 1);
    winning = winning || !solve(a, b - 3, c, d);
    winning = winning || !solve(a, b, c - 2, d - 1);
    winning = winning || !solve(a - 1, b, c, d - 1);

    return dp[a][b][c][d] = winning; //memoize and return
        
}

int main(){

    int n;
    std::cin >> n;

    while (n--){

        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        memset(dp, -1, sizeof(dp));
        
        if (solve(a, b, c, d)){
            std::cout << "Patrick\n";
        }
        else{
            std::cout << "Roland\n";
        }
        
    }

    return 0;
    
}