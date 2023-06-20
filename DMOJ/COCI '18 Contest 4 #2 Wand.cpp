#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <cstring>

std::vector<int> graph [100001];
bool visited [100001];

//basic idea: if you reach a person via dfs starting at 1 on the tree
//Then you can end off on them
//No need to deal with duplicate edges, since you can just run those duels before 1 even passes the wand to anyone
//Then you have a perfect tree
void dfs (int cur){
    for (const int& next: graph[cur]){
        if (!visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }
}

int main(){
    memset(visited, false, sizeof(visited));
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++){
        //view it as a graph, where if X defeats Y, then there exists an edge from Y to X indicating Y can give the wand to X
        int X, Y;
        std::cin >> X >> Y;
        graph[Y].push_back(X);
    }
    dfs (1);
    //edge case, 1 cannot pass to anyone, then 1 will be left with the wand
    if (graph[1].empty()){
        visited[1] = true;
    }
    for (int i = 1; i <= N; i++){
        visited[i] ? std::cout << "1" : std::cout << "0";
    }
    return 0;
}