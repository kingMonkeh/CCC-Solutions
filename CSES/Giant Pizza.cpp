#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX / 2
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

std::vector<vi> graph, rgraph, SCC_graph;
vi vis, comp, id, in;
std::stack<int> s;

//graph is like this
//node:  -1 1 -2 2 ...
//index:  1 2  3 4 ...

int flip (int x){
    if (x&1) return x + 1;
    else return x - 1;
}

void add_edge (char like1, int t1, char like2, int t2){
    t1 *= 2; t2 *= 2;
    if (like1 == '-') t1--;
    if (like2 == '-') t2--;
    graph[flip(t1)].push_back(t2);
    graph[flip(t2)].push_back(t1);
    rgraph[t2].push_back(flip(t1));
    rgraph[t1].push_back(flip(t2));
}

void dfs1 (int cur){
    vis[cur] = true;
    for (auto& adj: graph[cur]){
        if (!vis[adj]) dfs1(adj);
    }
    s.push(cur);
}

void dfs2 (int cur){
    vis[cur] = true;
    comp.push_back(cur); //add node to current SCC
    for (auto& adj: rgraph[cur]){
        if (!vis[adj]) dfs2(cur);
    }
}

void dfs3 (int cur){
    vis[cur] = true;
    for (auto& adj: SCC_graph[cur]){
        if (!vis[adj]) dfs3(adj);
    }
    s.push(cur);
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, m;
        std::cin >> n >> m;

        graph.resize(2 * m + 1);
        rgraph.resize(2 * m + 1);
        id.resize(2 * m + 1);
        in.resize(2 * m + 1, 0);

        //create graph
        for (int i = 0; i < n; i++){
            char like1, like2;
            int t1, t2;
            std::cin >> like1 >> t1 >> like2 >> t2;
            add_edge(like1, t1, like2, t2);
        }

        //dfs and add to stack
        vis.resize(2 * m + 1, false);
        for (int i = 1; i <= 2 * m; i++) if (!vis[i]) dfs1(i);

        //find each SCC
        std::vector<vi> SCC (2 * m + 1);
        for (int i = 1; i <= 2 * m; i++) vis[i] = false;
        int comp_id = 1;
        while (!s.empty()){
            int cur = s.top();
            s.pop();
            if (vis[cur]) continue;
            dfs2(cur);
            SCC[comp_id] = comp;
            for (auto& node: comp){
                id[node] = comp_id;
            }
            comp_id++;
            comp.clear();
        }

        //if i and -i are in the same SCC
        //impossible to satisfy 2SAT
        for (int i = 1; i <= m; i++){
            if (id[2 * i] == id[2 * i - 1]){
                std::cout << "IMPOSSIBLE";
                return 0;
            }
        }

        //Create graph of SCC
        SCC_graph.resize(2 * m + 1);
        for (int i = 1; i <= 2 * m; i++){
            for (auto& adj: graph[i]){
                if (id[i] != id[adj]){
                    SCC_graph[id[i]].push_back(id[adj]);
                    in[id[adj]]++;
                }
            }
        }

        //Topological sort of SCC graph
        for (int i = 1; i <= 2 * m; i++) vis[i] = false;
        for (int i = 1; i <= 2 * m; i++){
            if (in[i] == 0) dfs3(i);
        }

        std::vector<char> ans (m + 1);
        for (int i = 1; i <= 2 * m; i++) vis[i] = false;
        while (!s.empty()){
            int cur = s.top();
            s.pop();
            for (auto& a: SCC[cur]){
                int i = (a + 1) / 2;
                if (!vis[i]){
                    ans[i] = a & 1 ? '-' : '+';
                    vis[i] = true;
                }
            }
        }

        for (int i = 1; i <= m; i++) std::cout << ans[i] << ' ';
        
    }
    
    return 0;
    
}

/*
#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

bool vis[maxN];
char ans[maxN];
int N, M, K, in[maxN], rt[maxN];
vector<int> ord, comp, G[maxN], GR[maxN], C[maxN], SCC[maxN];

int flip(int x){
    return (x&1 ? x+1 : x-1);
}

//graph indexing is like
//node represented
//-1 1 -2 2 -3 3...
//actual index
// 1 2  3 4  5 6
void add_edge(char c1, int a, char c2, int b){
    a = 2*a - (c1 == '-');
    b = 2*b - (c2 == '-');
    G[flip(a)].push_back(b);
    G[flip(b)].push_back(a);
    GR[a].push_back(flip(b));
    GR[b].push_back(flip(a));
}

void dfs1(int u){
    vis[u] = true;
    for(int v : G[u])
        if(!vis[v])
            dfs1(v);
    ord.push_back(u); //push the things to stack once we have visited all neighbours
}

//in the reversed graph, mark all connected components
void dfs2(int u){
    vis[u] = true;
    comp.push_back(u);
    for(int v : GR[u])
        if(!vis[v])
            dfs2(v);
}

int main(){
    scanf("%d %d", &M, &N);
    for(int i = 0, a, b; i < M; i++){
        char c1, c2;
        scanf(" %c %d %c %d", &c1, &a, &c2, &b);
        add_edge(c1, a, c2, b);
    }

    //push numbers to stack
    for(int i = 1; i <= 2*N; i++)
        if(!vis[i])
            dfs1(i);

    fill(vis+1, vis+2*N+1, false);
    reverse(ord.begin(), ord.end());
    //find connected components
    for(int u : ord){
        //for each connected component
        if(!vis[u]){
            dfs2(u);
            K++;
            //mark all nodes with id
            for(int v : comp){
                rt[v] = K; //id array
                C[K].push_back(v);
            }
            comp.clear();
        }
    }

    // Impossible iff x and not(x) belong to same SCC
    for(int i = 1; i <= N; i++){
        if(rt[2*i] == rt[2*i-1]){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    //create a graph of the connected components
    for(int u = 1; u <= 2*N; u++){
        for(int v : G[u]){
            if(rt[u] != rt[v]){
                SCC[rt[u]].push_back(rt[v]);
                in[rt[v]]++; //indegree of connected component
            }
        }
    }

    //find all starting points of topological sort
    queue<int> Q;
    ord.clear();
    for(int u = 1; u <= K; u++){
        //indegree of 0 means no other component must be visited first
        //thus we can start off with this one
        if(in[u] == 0){
            ord.push_back(u);
            Q.push(u);
        }
    }

    //topological
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : SCC[u]){
            in[v]--;
            if(in[v] == 0){
                ord.push_back(v);
                Q.push(v);
            }
        }
    }

    fill(vis+1, vis+N+1, false);
    reverse(ord.begin(), ord.end());
    //for each component in ord
    for(int k : ord){
        //for each node in component
        for(int u : C[k]){
            int i = (u+1)/2; //convert the neg or pos back to orig index
            //we only compute answer on our first encouter of node, so either neg or pos, afterwards discard the other
            if(!vis[i]){
                //if odd put neg, else put +
                ans[i] = (u&1 ? '-' : '+');
                vis[i] = true;
            }
        }
    }

    //output
    for(int i = 1; i <= N; i++)
        printf("%c%c", ans[i], (" \n")[i==N]);
}
*/