/*

2022 S5 - Good Influencers

Difficulty: Hard

Basically for this problem, we try every possible combination of students, to optimize this process we use dynamic programming

Notice that we're given a tree, since there are N people, and N - 1 friendships (a tree has only one path between any two nodes and has n - 1 edges and n nodes)
Essentially, we will choose any node and call it the root of the tree
From this node, we will perform a depth first search of the tree

This is where things get a bit confusing
Essentially, to brute force every possible combination
We will create three states (or as I like to view them, building blocks)
Let 0 indicate that this node is influenced by its parent node
Let 1 indicate that the node is participating in the ccc
Let 2 indicate that the node is going to give a seminar to its parent

Using these three building blocks, we can create every possible combination
Let us create a DP array where DP[i][j] tells us the minimum cost of activating i's subtree if i has taken on state j
Note that some states are not possible, we will have these return INFINTY as to indicate this

However, these building blocks themselves have rules as to what they can do and can't do

The main cases are as follows:

Case 0: The node is initially participating and it will influence its parent node
Here we must pay this node since it has to influence its parent
By turning on this node however, its adjacent nodes will now take on state 0 since theyre being influenced by this node

Case 1: The node is influenced by its parent or it's initially participating and is not influencing its parent
Here, we're not forced to pay it this time. This forces us to try both options. Either we pay it or we don't
If we choose to pay it, then its adjacent nodes would take on the state 0 since they're being influenced
If we don't pay it, then its adjacent nodes would take on state 1, since in the final answer, they must be turned on, but theyre not being influenced by the current node

You may wonder why we don't also try state 2 when we choose not to pay, the reason behind this is that you would never do that in the optimal answer

Case 2: The node is not on, either directly or indirectly and is a leaf node
In this case, we've reached a dead end, it's not possible, return INF

Case 3: Node will influence parent, but is not participating initially
If its not already on and influencing its parent, it must be influenced by its child
Note that the node may have multiple child nodes, only one of these nodes needs to influence the parent, the rest are on since this node is also forced to be on
To determine which child should influence the parent, we will get the sum of all child subtrees if they were activated by the current node
Afterward, we will attempt to swap one of the child on values with a influence parent value and check which yields the lowest cost

Case 4: Node is activated
We will do the same as in case 3, but since we're not forced to pay this node, we can repeat the same process, one child will influence this node
But instead of having the current node influence the remaining children, it will have no influence

*/
#include <iostream>
#include <vector>
#include <string>

#define INF 2147483647

/*
state 0 = will be influenced by parent node
state 1 = intends to write either initially, or by influence from child node
state 2 = influences its parent
*/

std::vector<std::vector<int>> DP;
std::string initial = " ";
std::vector<std::vector<int>> graph;
std::vector<int> costs;

int dfs (int current, int previous, int state){
    
    if (DP[current][state] != -1){
        return DP[current][state];
    }
    
    //If node influences its parent and is initially participating
    if (state == 2 && initial[current] == 'Y'){
        int payCost = costs[current];
        //Try paying this node
        //fr, short for friend
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            payCost += dfs(fr, current, 0);
        }
        DP[current][state] = payCost;
        return DP[current][state];
    }

    //If node is indirectly influenced or is initially participating
    if (state == 0 || initial[current] == 'Y'){

        int payCost = costs[current], noPayCost = 0;

        //Try paying this node
        //fr, short for friend
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            payCost += dfs(fr, current, 0);
        }

        //Don't pay this node
        //Note that if the current state is to influence its parent, we can't not pay it
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            //If we don't pay this node, the next node must be activated by something however
            int noInfluence = dfs(fr, current, 1);
            if (noInfluence == INF){
                noPayCost = INF;
                break;
            } 
            noPayCost += noInfluence;
        }

        DP[current][state] = std::min(payCost, noPayCost); //Take the minimum between the two
        
        return DP[current][state];

    }
    
    //Check dead end leaf node
    if (graph[current].size() == 1 && graph[current][0] == previous){
        DP[current][state] = INF;
        return INF;
    }

    //if node is influencing parent and is not initially participating, it must be payed
    //Not only that, since it's not initially activated, then one of its children must influence it
    //The rest of the children will be influenced by this node since the current node is forced to be activated
    if (state == 2){
        int paySum = 0, payAns = INF;
        //Get sum of all child costs if this node were to influence them
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            paySum += dfs(fr, current, 0);
        }
        //With this sum, we now testing the price if child x were to influence our node while our node influences the rest
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            int influencePrice = dfs(fr, current, 0);
            int childPayPrice = dfs(fr, current, 2);
            if (childPayPrice == INF){
                continue;
            }
            payAns = std::min(payAns, paySum - influencePrice + childPayPrice);
        }
        
        if (payAns != INF){
            payAns += costs[current];
        }
        
        DP[current][state] = payAns;
        return DP[current][state];
        
    }
    
    //if node is on, but isn't initially on and is not influenced by its parent
    //then it must be influenced by one of its children
    //from here we have one of two choices
    //Option 1: After a child node activates us, we pay this person to give a seminar to all other child nodes
    //Option 2: After a child node activates us, we don't pay this person and let its child nodes be influenced by its child nodes
    if (state == 1){
        //Option 1
        int paySum = 0, payAns = INF;
        //Get sum of all child costs if this node were to influence them
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            paySum += dfs(fr, current, 0);
        }
        //With this sum, we now testing the price if child x were to influence our node while our node influences the rest
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            int influencePrice = dfs(fr, current, 0);
            int childPayPrice = dfs(fr, current, 2);
            if (childPayPrice == INF){
                continue;
            }
            payAns = std::min(payAns, paySum - influencePrice + childPayPrice);
        }
        
        if (payAns != INF){
            payAns += costs[current];
        }
        
        //Try Option 2
        int noPaySum = 0, noPayAns = INF;
        bool possible = true;
        //Get sum of all child costs if this node were to not influence them, note that this may not be possible
        for (auto &fr: graph[current]){
            if (fr == previous){
                continue;
            }
            int noInfluencePrice = dfs(fr, current, 1);
            if (noInfluencePrice == INF){
                possible = false;
                break;
            }
            noPaySum += noInfluencePrice;
        }
        
        //If it's possible
        if (possible){
            for (auto &fr: graph[current]){
                if (fr == previous){
                    continue;
                }
                int noInfluencePrice = dfs(fr, current, 1);
                int childPayPrice = dfs(fr, current, 2);
                if (childPayPrice == INF){
                    continue;
                }
                noPayAns = std::min(noPayAns, noPaySum - noInfluencePrice + childPayPrice);
            }
            payAns = std::min(payAns, noPayAns);
        }
        
        DP[current][state] = payAns;
        return DP[current][state];
        
    }
    
}

int main(){

    int N;
    std::cin >> N;

    DP.resize(N + 1, std::vector<int> (3, -1));
    graph.resize(N + 1); costs.resize(N + 1);

    //Get friendships
    for (int i = 0; i < N - 1; i++){

        int A, B;
        std::cin >> A >> B;

        //Construct graph, forwards and backwards
        graph[A].push_back(B);
        graph[B].push_back(A);

    }
    
    std::string CCC;
    std::cin >> CCC;
    initial += CCC;

    for (int i = 1; i <= N; i++){
        std::cin >> costs[i];
    }
    
    std::cout << dfs(1, -1, 1) << '\n';

    return 0;

}
