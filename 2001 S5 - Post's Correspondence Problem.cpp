/*

2001 S5 - Post's Correspondence Problem

Difficulty: Easy

Just uh try every single set of numbers
This works since m * n is no greater than like 40

You can essentially view this problem as a really big choice tree
We will perform recursive dfs on this tree

We will also use a stack to keep track of our current path
Since we need to print out the set in order

*/

#include <iostream>
#include <string>
#include <stack>

bool possible = false; //mark if solvable or not
std::stack<int> path;
int m, n;
std::string A [40];
std::string B [40];

//Since k cannot be greater than m, we need to keep track of k's value in each recurse
//solve(current value of k, which index from the array we want to add to our string, string a, string b)
void solve (int k, int i, std::string a, std::string b){

    //If we're out of bounds, return nothing
    if (k >= m){
        return;
    }
    
    //Update strings, add current node to our path
    path.push(i + 1);
    a += A[i];
    b += B[i];

    //If they're the same
    if (a == b){
        possible = true;
        //Output total terms used
        std::cout << k << '\n';
        std::stack<int> copy; //Since we put stuff in a stack the order is actually reverse
        //Therefore we just flip the stack, by putting it in another stack. Master level programming right here
        while (!path.empty()){
            copy.push(path.top());
            path.pop();
        }
        while (!copy.empty()){
            std::cout << copy.top() << '\n';
            copy.pop();
        }
        return;
    }

    //Try every possibility
    for (int j = 0; j < n; j++){
        solve(k + 1, j, a, b);
        //If the stack is empty after a recurse, that means that we solved it since thats the only way the stack can become empty
        if (path.empty()){
            return;
        }
    }

    //Remember to delete nodes if they're not necessary
    path.pop();
    
}

int main(){

    std::cin >> m >> n;

    for (int i = 0; i < n; i++){
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        std::cin >> B[i];
    }

    for (int i = 0; i < n; i++){
        solve(1, i, "", "");
    }

    //If not solvable
    if (!possible){
        std::cout << "No solution.\n";
    }

    return 0;
    
}