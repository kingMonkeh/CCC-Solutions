#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>

/*

Difficulty: Hard??? (idk i got the answer by accident :sob:)

Pro tip: work on a subtask first, they likely point u in the direction of the answer, i only got full marks by slightly tweaking my 5 point submission
all i did was add one for loop to my 5 point solution and it worked

idea: if there is only one way to connect two nodes, you need to color that path since otherwise there exists no other path that u can color
but if there is multiple ways to get to a node, ie the node is in a cycle
you just iterate through the cycle, but dont color the last edge, since u can just go backwards on ur previously colored path and reach the node
since the nodes dont all have to be connected, iterate through all the nodes and make sure u visit them

*/

struct path{
 int dest;
 int ind;
};

//Dfs, note that last parameter red, its important that if we color a path red, that when we dfs onto that dest node
//we must color all subsequent paths blue, to ensure that we have the alternating red blue patttern
std::vector<char> ans;
void solve(int cur, std::vector<std::vector<path>>& graph, std::vector<bool>& visited, bool red){
  visited[cur] = true;
  for (auto& p: graph[cur]){
    if (!visited[p.dest]){
      ans[p.ind] = red ? 'R' : 'B';
      solve(p.dest, graph, visited, !red);
    }
  }
}

int main() {

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<path>> graph (n + 1);
  std::vector<bool> vis (n + 1, false);

  for (int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;
    graph[u].push_back({v, i});
    graph[v].push_back({u, i});
  }

  ans.resize(m, 'G');

  //this is to catch disconnected graphs
  for (int i = 0; i < n; i++){
    if (!vis[i + 1]) solve(i + 1, graph, vis, true);
  }
  

  for (auto& c: ans) std::cout << c;

}

/*
5 point solution
Note that for all nodes to be connected, you need at least N - 1 paths, this is a fact, look it up
Since we have exactly N paths, this tells us there exists a cycle in the graph
We can make use of this by coloring RBRBRBRB... up until the last node in the cycle, since we can reach it by just going backwards
The paths outside the cycle must be colored, since there is only one path connecting those nodes

std::vector<char> ans;
void solve(int cur, std::vector<std::vector<path>>& graph, std::vector<bool>& visited, bool red){
  visited[cur] = true;
  for (auto& p: graph[cur]){
    if (!visited[p.dest]){
      ans[p.ind] = red ? 'R' : 'B';
      solve(p.dest, graph, visited, !red);
    }
  }
}

int main() {

  int n, m;
  std::cin >> n >> m;
  
  std::vector<std::vector<path>> graph (n + 1);
  std::vector<bool> vis (n + 1, false);

  for (int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;
    graph[u].push_back({v, i});
    graph[v].push_back({u, i});
  }

  ans.resize(m, 'G');

  solve(1, graph, vis, true);

  for (auto& c: ans) std::cout << c;
  
}
*/

/*
2 Point solution, since i connects to i + 1
just alternate red blue accordingly from node i to i + 1
intuitively makes sense that this is the optimal solution

int main() {

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> paths;

  for (int i = 0; i < m; i++){
    int u, v;
    std::cin >> u >> v;
    if (u > v) std::swap(u, v);
    paths.push_back({u, v, i});
  }

  std::sort(paths.begin(), paths.end());

  std::vector<char> ans (m);

  bool red = true;
  for (auto& p: paths){
    if (p[0] + 1 == p[1]){
      if (red) ans[p[2]] = 'R';
      else ans[p[2]] = 'B';
      red = !red;
    }
    else ans[p[2]] = 'G';
  }

  for (auto& a: ans) std::cout << a;

}
*/