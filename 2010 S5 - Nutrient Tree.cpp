/*

2010 S5 - Nutrient Tree

Difficulty: Very Hard

Basically for each non-leaf node
It has 2 children

  N
 / \
L   R

Basically, we make dp array where dp[i][j] tells us the max nutrients, node i can transport with j growth agents given to it
To calculate this value for non leaf nodes, its the dp[i][j] values of its 2 children added together
Note that the edge may be limiting, so take into account the edge as well
If its a leaf node, you just try every amount of growth agent on the node itself and on its edge

for this problem, i think its easier to explain with actual code

*/

#include <iostream>
#include <string>
#include <stack>

#define leftChild node * 2
#define rightChild node * 2 + 1

int X;
int tree [10000];
int dp[10000][2501];
int leftRight[10000][2501];
int answer = 0;

void dfs(int node){

    //Leaf node
    if (tree[node]){

        //For every growth agent amount
        for (int i = 0; i <= X; i++){
            //From the current amount of growth agent that can be used, try giving every possible value to the edge
            for (int e = 0; e <= i; e++){
                int nodeGrowth = i - e; //Total growth agents - agents given to edge = growth agents left for node
                //Remember that the edge may be limiting, so you have to take min
                //dp[node][i] = max(itself, min(node + growth, edge capacity))
                dp[node][i] = std::max(dp[node][i], std::min(tree[node] + nodeGrowth, (1 + e) * (1 + e)));
            }
        }
        
    }

    //Not leaf node
    else{

        //Solve its children first,
        dfs(leftChild);
        dfs(rightChild);

        //For every growth agent amount
        for (int i = 0; i <= X; i++){
            //For every growth agent amount that can be given to the left child
            for (int l = 0; l <= i; l++){
                //Growth agent to right child = total amount to be used - amount given to left child
                int r = i - l;
                //leftRight[node][i] basically tells us the max amount of nutrients that can be produced by the children of the node given i growth agents
                //Note that this does not take into account the edge yet, that is in the next loop
                leftRight[node][i] = std::max(leftRight[node][i], dp[leftChild][l] + dp[rightChild][r]); //max(itself, its 2 children combined)

                //Note that if the current node is the root, then this would also be the answer
                if (node == 1){
                    answer = std::max(answer, leftRight[node][i]);
                }
            }
        }

        //For every growth agent amount
        for (int i = 0; i <= X; i++){
            //From the current amount of growth agent that can be used, try giving every possible value to the edge
            for (int e = 0; e <= i; e++){
                int nodeGrowth = i - e; //Amount given to edge
                //Same idea, max(itself, min(total nutrients from node, edge))
                dp[node][i] = std::max(dp[node][i], std::min(leftRight[node][nodeGrowth], (1 + e) * (1 + e)));
            }
        }
        
    }
    
}

int main() {
    
    std::string input;
    getline(std::cin, input);
    std::cin >> X;

    //If it's just a root, no subtrees
    if (input[0] != '('){
        std::cout << std::stoi(input) + X << '\n';
        return 0;
    }

    //Otherwise, we have to deal with this atrocious input format
    std::stack<std::string> s; s.push("(");
    int node = 1;
    int i = 1;
    while (!s.empty()){

        //Skip blank space
        if (input[i] == ' '){
            i++;
            continue;
        }
        
        //Opening bracket
        if (input[i] == '('){

            //Determine if left or right subtree
            if (s.top() == "("){
                node = leftChild;
            }

            else{
                node = rightChild;
            }

            s.push("(");
            i++;
            
        }

        //End of a subtree
        else if (input[i] == ')'){
            int right = std::stoi(s.top()); s.pop();
            int left = std::stoi(s.top()); s.pop();
            s.pop(); //Get rid of the opening bracket
            tree[leftChild] = left;
            tree[rightChild] = right; 
            if(!s.empty()) s.push("0"); //Basically used for filler if the node isnt a leaf node
            node /= 2; //return to parent
            i++;
        }

        //Get number
        else{
            std::string num = "";
            while (true){
                num += input[i];
                i++;
                if(input[i] == '(' || input[i] == ')' || input[i] == ' '){
                    s.push(num);
                    break;
                }
            }
        }
        
    }

    /* INPUT DEBUGGING
    for (int i = 0 ; i < 20; i++){
        std::cout << "Tree[" << i << "] = " << tree[i] << '\n';
    }
    */

    dfs(1);
    std::cout << answer << '\n';

    return 0;
    
}