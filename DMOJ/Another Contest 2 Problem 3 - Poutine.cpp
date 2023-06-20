/*

Basically, we root the tree at node 1

Afterward, we dfs and generate 2 sparse tables
one that tells us the node that is 2^i nodes above the current
and another table that tells us the 2 longest edges, between the current node and the node that is 2^i nodes above it

To query, it's quite simple
We find the lowest common ancestor of the two queried nodes
Note that the shortest path between two nodes in the tree is equal to the distance from the first node to the lca + distance from lca to second node

Once you find the lca of the two nodes
You use the second sparse table you created to determine the second largest edge on that path

*/

#include <iostream>
#include <utility>
#include <vector>

const int LOG = 17; //2^17 > 100000

int N, Q;
std::vector<std::pair<int, int>> graph [100001];
int depth [100001];
int ancestor [100001][LOG + 1]; //ancestor[i][j] tells us node that is 2^j nodes above node i
std::pair<int, int> mxedges [100001][LOG + 1];

//Given 2 pairs of edges {a, b} and {c, d}
//Return a pair containing the 2 greatest edges
std::pair<int, int> maxmax (std::pair<int, int> a, std::pair<int, int> b){
    std::pair<int, int> c = a;
    if (b.first > c.first){
        c.second = c.first;
        c.first = b.first;
    }
    else if (b.first > c.second){
        c.second = b.first;
    }
    if (b.second > c.second){
        c.second = b.second;
    }
    return c;
}

//dfs
void dfs (int cur, int prev, int weight){
    depth[cur] = depth[prev] + 1; //Keep note of depth
    ancestor[cur][0] = prev; //Ancestor sparse tree
    mxedges[cur][0] = {weight, -1}; //2 largest edges sparse tree
    for (int pow = 1; pow <= 17; pow++){
        ancestor[cur][pow] = ancestor[ancestor[cur][pow - 1]][pow - 1];
        mxedges[cur][pow] = maxmax(mxedges[cur][pow - 1], mxedges[ancestor[cur][pow - 1]][pow - 1]);
    }
    //Continue dfs
    for (auto& edge: graph[cur]){
        if (edge.first == prev) continue;
        dfs(edge.first, cur, edge.second);
    }
}

//Find lca
int lca (int a, int b){
    //Make sure a is below b
    if (depth[b] > depth[a]){
        int temp = b;
        b = a;
        a = temp;
    }
    //Match depth
    for (int pow = LOG; pow >= 0; pow--){
        if (depth[ancestor[a][pow]] >= depth[b]){
            a = ancestor[a][pow];
        }
    }
    if (a == b) return a;
    //Traverse
    for (int pow = LOG; pow >= 0; pow--){
        if (ancestor[a][pow] != ancestor[b][pow]){
            a = ancestor[a][pow];
            b = ancestor[b][pow];
        }
    }
    return ancestor[a][0];
}

std::pair<int, int> query (int a, int lca){
    std::pair<int, int> ret = {-1, -1};
    for (int pow = LOG; pow >= 0; pow--){
        if (depth[ancestor[a][pow]] >= depth[lca]){
            ret = maxmax(ret, mxedges[a][pow]);
            a = ancestor[a][pow];
        }
    }
    return ret;
}

int main (){
    std::cin >> N;
    for (int i = 0; i < N - 1; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    dfs (1, 0, -1);
    std::cin >> Q;
    for (int i = 0; i < Q; i++){
        int s, t;
        std::cin >> s >> t;
        int LCA = lca(s, t);
        std::cout << maxmax(query(s, LCA), query(t, LCA)).second << '\n';
    }
    return 0;
}