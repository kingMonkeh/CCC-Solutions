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

std::vector<vi> graph, rgraph, SCC_graph, SCC;
vi vis, comp, id, in;
std::stack<int> s;
vi ord, pos;

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
        if (!vis[adj]) dfs2(adj);
    }
}

void dfs3 (int cur, int level){
    vis[cur] = true;
    for (auto& a: SCC[cur]) pos[a] = level;
    for (auto& adj: SCC_graph[cur]){
        if (!vis[adj]) dfs3(adj, level + 1);
    }
    ord.push_back(cur);
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

        graph.resize(2 * m + 5);
        rgraph.resize(2 * m + 5);
        id.resize(2 * m + 5);
        in.resize(2 * m + 5, 0);

        //create graph
        for (int i = 0; i < n; i++){
            char like1, like2;
            int t1, t2;
            std::cin >> like1 >> t1 >> like2 >> t2;
            add_edge(like1, t1, like2, t2);
        }

        //dfs and add to stack
        vis.resize(2 * m + 5, false);
        for (int i = 1; i <= 2 * m; i++) if (!vis[i]) dfs1(i);

        //find each SCC
        SCC.resize(2 * m + 5);
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
        SCC_graph.resize(2 * m + 5);
        for (int i = 1; i <= 2 * m; i++){
            for (auto& adj: graph[i]){
                if (id[i] != id[adj]){
                    SCC_graph[id[i]].push_back(id[adj]);
                    in[id[adj]]++;
                }
            }
        }

        //Topological sort of SCC graph
        pos.resize(2 * m + 5);
        for (int i = 1; i <= 2 * m; i++) vis[i] = false;
        for (int i = 1; i <= 2 * m; i++){
            if (in[i] == 0) dfs3(i, 0);
        }

        std::vector<char> ans (m + 1);
        for (int i = 1; i <= 2 * m; i++) vis[i] = false;
        std::reverse(ord.begin(), ord.end());
        for(auto& cur: ord){
            //int cur = s.top();
            //s.pop();
            for (auto& a: SCC[cur]){
                int i = (a + 1) / 2;
                if (!vis[i]){
                    //neg first
                    if (a & 1){
                        if (pos[flip(a)] > pos[a]){
                            ans[i] = '+';
                        }
                        else{
                            ans[i] = '-';
                        }
                    }
                    //pos first
                    else{
                        if (pos[a] > pos[flip(a)]){
                            ans[i] = '+';
                        }
                        else{
                            ans[i] = '-';
                        }
                    }
                    vis[i] = true;
                }
            }
        }

        for (int i = 1; i <= m; i++) std::cout << ans[i] << ' ';
        
    }
    
    return 0;
    
}