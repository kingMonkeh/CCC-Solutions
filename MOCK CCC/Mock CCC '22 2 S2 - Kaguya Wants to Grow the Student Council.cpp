/*

Basically uh you can view it as a graph

Lets just translate the alphabet to integers
aka A = 0, B = 1, C = 2, ...

And lets let the nodes be the candidates
Let an edge from candidate A to candidate B
indicate that candidate A is ranked higher than candidate B

When we get a ballot
For each candidate, we add an edge connecting it to every candidate lower than it

Notice something important
if there exists an edge from candidate A to candidate B
yet there also exists an edge from candidate B to candidate A

Then these 2 candidates, cannot be put together
since we're saying that A > B && B > A which is not possible
Therefore we eliminate all such pairs of edges

Afterwards we're left with a pretty small graph
We can gurantee that the graph is a directed, acyclic graph
since every child node of a node must be smaller
therefore a child node can never go back to an ancestor node

Afterward, just perform dfs to find distance of every path
and output largest one

*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <string.h>

std::vector<int> graph [26];

int maxCouncil = 0;
void dfs (int current, int dist){
    if (graph[current].size() == 0){
        maxCouncil = std::max(maxCouncil, dist);
    }
    for (int& next: graph[current]){
        dfs(next, dist + 1);
    }
}

int main(){
    int N, K;
    std::cin >> N >> K;
    int greater [26][26];
    memset(greater, 0, sizeof(greater));
    for (int i = 0; i <= N; i++){
        std::string ballot;
        std::cin >> ballot;
        for (int i = 0; i < ballot.length(); i++){
            for (int j = i + 1; j < ballot.length(); j++){
                //ascii table
                greater[(ballot[i] - 65)][(ballot[j] - 65)] = true;
            }
        }
    }
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            //i > j and !(j > i)
            if (greater[i][j] == 1 && !(greater[i][j] && greater[j][i])){
                graph[i].push_back(j);
            }
        }
    }
    for (int start = 0; start < 26; start++){
        dfs(start, 1);
    }
    /*
    for (int i = 0; i < 26; i++){
        char ch = i + 'A';
        std::cout << ch << ": ";
        for (int& a: graph[i]){
            char c = a + 'A';
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
    */
    std::cout << maxCouncil << '\n';
    return 0;
}