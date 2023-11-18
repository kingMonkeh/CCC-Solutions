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

/*

we take note that from any two rooms, after some time they will always meet

does this necessarily mean that node a can directly reach node b?
no, but what it does mean is that after some number of iterations

a and b will have to enter a cycle and eventually meet

the fact that every room will eventually meet every other starting room tells us that there is 1 big cycle in the graph, and there may be outer paths that lead into this cycle

By this logic, we can greedily choose to place the minotaur as far away from the cycle as possible
maximizing the time before the cycle

once the minotaur is in the cycle however
we must now decide how to place the adventurer

idk how to prove this, but if you just simulated the game
you would have noticed that it takes 2 * (distance from adventurer to minotaur once both are in cycle) minutes for the minotaur and adventurer to meet

therefore to maximize the time in cycle, we'd want to put the adventurer as far away as possible from the minotaur, which is (cycle size - 1) nodes away from the minotaur

our answer then = 2 * (max length path to enter the main cycle) + 2 * (cycle size - 1)

to find the cycle, we can use topological sort
to find the max distance to cycle, try dfs from all nodes with an indegree of 0 (aka no nodes point to this node)

*/

vi graph, cycle;
vi vis, on_stack;

bool dfs (int cur){

    vis[cur] = on_stack[cur] = true;

    int adj = graph[cur];
    if (on_stack[adj]){
        on_stack[adj] = false;
        on_stack[cur] = false;
        cycle.push_back(cur);
        return true;
    }
    else if (!vis[adj]){
        if (dfs(adj)){
            if (on_stack[cur]){
                on_stack[cur] = false;
                cycle.push_back(cur);
                return true;
            }
            else{
                cycle.push_back(cur);
                return false;
            }
        }
    }

    on_stack[cur] = false;
    return false;
    
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n;
        std::cin >> n;

        vi cnt (n + 1, 0);

        graph.resize(n + 1);
        for (int i = 1; i <= n; i++){
            std::cin >> graph[i];
            cnt[graph[i]]++;
        }

        vis.resize(n + 1, 0);
        on_stack.resize(n + 1, 0);
        dfs(1);

        vi on_cycle (n + 1, 0);
        for (auto& room: cycle) on_cycle[room] = true;

        int mx = 0;
        for (int i = 1; i <= n; i++){
            if (!cnt[i]){
                int pos = i, dist = 0;
                while (!on_cycle[pos]){
                    dist++;
                    pos = graph[pos];
                }
                mx = std::max(mx, dist);
            }
        }

        std::cout << 2 * mx + 2 * (cycle.size() - 1);
        
    }
    
    return 0;
    
}