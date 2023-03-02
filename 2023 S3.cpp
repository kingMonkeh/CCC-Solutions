/*

2023 S3 - Palindromic Posters

Difficulty: Medium/Hard

No way! Bocchi the Rock on CCC!
Still though, I hate this problem...

Basic idea:
You can just fill the entire grid with some letter
Afterward you can just fill however many rows and columns are need with a different letter

For example
4 4 1 2

b b b b
b b a a
b b a a
b b a a

Note that this doesn't work when R or C are equal to 0
This also doesn't work when R == N or C == M
This does work however if R == N and C == M

Case 1: R = 0
Fill grid with all a's, make last column all b's, this will get rid of all palindromic rows while still having M palindromic columns
Afterward, just increment the last M - C letters of any one row, this will eliminate M - C palindromic columns leaving you with C palindromic columns
C + M - C = M

For example
5 4 0 1

a a a b
a a a b
a a a b
a a a b
a b b c

Case 2: R == N
Fill grid with all a's
Note that we have N palindromic rows and M palindromic columns, we can eliminate palindromic columns by incrementing 2 letters in a row such that it still remains a palindrome
This means we can only eliminate 2 palindromes at a time otherwise the row wouldn't be a palindrome

Meaning M % 2 must equal to C % 2 for it to be possible

But there is one exception.
If M is odd and C is even, it's possible since we can keep subtracting 2 palindromic columns until we reach C + 1 palindromic columns remaining
Then we can increment the center letter of the top row, decreasing the palindromic columns by 1 while still keeping the row as a palindrome

Example with M is odd and C is even:

4 5 4 2

b a b a b
a a a a a
a a a a a
a a a a a

If M is even and C is odd, not possible.

If C = 0 or C = M, we can follow the same logic as before by swapping N and M, and swapping R and C
We will then work under the same logic and then we will output our grid, rotated 90 degrees

For example:

Input: 4 5 1 0

Flipped input: 5 4 0 1
Generate grid accordingly

a a a b
a a a b
a a a b
a a a b
a b b c

Now we just output the grid rotated

b b b b c
a a a a b
a a a a b
a a a a a

We can see this final grid matches the original input, it has 4 rows, 5 columns, 1 palindromic row and 0 palindromic columns

In conclusion, really ugly case work problem

*/

#include <iostream>
#include <vector>

std::vector<std::vector<char>> poster; //Our poster, will resize later
std::vector<char> alphabet {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void printPoster(int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout << poster[i][j];
        }
        std::cout << '\n';
    }
}

//Prints poster, but rotated 90 degrees counter clockwise
void printPosterRotated(int N, int M){
    for (int i = N - 1; i >= 0; i--){
        for (int j = 0; j < M; j++){
            std::cout << poster[j][i];
        }
        std::cout << '\n';
    }
}


int main(){
    
    int N, M, R, C;
    std::cin >> N >> M >> R >> C;
    
    //Regular case or when R == N and C == M
    if (R == N && C == M || (R != N && R != 0 && C != M && C != 0)){
        
        poster.resize(N, std::vector<char> (M, 'a'));
        
        //Complete Rows
        for (int i = 0; i < R; i++){
            for (int j = 0; j < M; j++){
                poster[i][j] = 'b';    
            }
        }
        
        //For remaining columns
        for (int i = R; i < N; i++){
            for (int j = 0; j < C; j++){
                poster[i][j] = 'b';
            }
        }
        
    }
    
    //If they're both 0, we can quite literaly just random fill the grid
    else if (R == 0 && C == 0){
        
        poster.resize(N, std::vector<char> (M, 'a'));
        
        //I essentially just keep filling it in with the alphabet except I occasionally jump letters to prevent column palindromes from forming
        int letter = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                poster[i][j] = alphabet[letter];
                letter++;
                letter %= 26;
            }
            letter += (i + 1) * 3;
            letter %= 26;
        }
        
    }
    
    //Special case 1, R == 0, no palindromic rows
    else if (R == 0){
        
        poster.resize(N, std::vector<char> (M, 'a'));
        
        //Fill last column
        for (int i = 0; i < N; i++){
            poster[i][M - 1] = 'b';
        }
        
        //Increment last M - C letters in bottom row
        for (int j = C; j < M; j++){
            poster[N - 1][j] = alphabet[(poster[N - 1][j] - 'a' + 1)];
        }
        
    }
    
    //All rows must be palindromic
    else if (R == N){
        
        poster.resize(N, std::vector<char> (M, 'a'));
        
        //If you can obtain C by subtracting 2 from M repeatedly
        if (M % 2 == C % 2){
            
            int goodCols = M;
            int front = 0, back = M - 1; //Indexes
            while (goodCols > C){
                
                poster[0][front] = 'b';
                poster[0][back] = 'b';
                front++; back--;
                goodCols -= 2;
                
            }
            
        }
        
        //If M is odd and C is even
        else if (M % 2 == 1){
            
            //Same logic as before
            int goodCols = M;
            int front = 0, back = M - 1;
            while (goodCols > C + 1){
                
                poster[0][front] = 'b';
                poster[0][back] = 'b';
                front++; back--;
                goodCols -= 2;
                
            }
            
            //Just change the middle to subtract one more palindromic column
            int mid = (front + back) / 2;
            poster[0][mid] = 'b';
            
        }
        
        //Otherwise impossible
        else{
            std::cout << "IMPOSSIBLE";
            return 0;
        }
        
    }
    
    //No palindromic columns
    else if (C == 0){
        
        poster.resize(M, std::vector<char> (N, 'a')); //Resize oppositely
        
        //Same logic, just swapping N and M
        for (int i = 0; i < M; i++){
            poster[i][N - 1] = 'b';
        }
        
        for (int j = R; j <= N; j++){
            poster[M - 1][j] = alphabet[poster[M - 1][j] - 'a' + 1];
        }
        
        printPosterRotated(N, M);
        
        return 0;
        
    }
    
    //All columns are palindromic
    else if (C == M){
        
        poster.resize(M, std::vector<char> (N, 'a'));
        
        //Same logic once again, just swapping the input
        if (N % 2 == R % 2){
            
            int goodCols = N;
            int front = 0, back = N - 1;
            while (goodCols > R){
                
                poster[0][front] = 'b';
                poster[0][back] = 'b';
                front++; back--;
                goodCols -= 2;
                
            }
            
            printPosterRotated(N, M);
            return 0;
            
        }
        
        else if(N % 2 == 1){
            
            int goodCols = N;
            int front = 0, back = N - 1;
            while (goodCols > R + 1){
                
                poster[0][front] = 'b';
                poster[0][back] = 'b';
                front++; back--;
                goodCols -= 2;
                
            }
            
            int mid = (front + back) / 2;
            poster[0][mid] = 'b';
            
            printPosterRotated(N, M);
            return 0;
            
        }
        
        else{
            std::cout << "IMPOSSIBLE";
            return 0;
        }
        
    }
    
    printPoster(N, M);
    
    return 0;
    
}


