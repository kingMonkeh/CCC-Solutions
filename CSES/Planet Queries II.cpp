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



*/

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n, q;
        std::cin >> n >> q;

        vi next (n + 1);
        std::vector<vi> before (n + 1);
        for (int i = 1; i <= n; i++){
            std::cin >> next[i];
            before[next[i]].push_back(i);
        }

        /*

        Mark all connect components and cycles

        cycle_id meaning:
        -3 = currently processing
        -2 = not processed
        -1 = not in cycle
        0 >= cycle, along with id
        
        */
        
        vi cycle_id (n + 1, -2);
        // vector containing the different cycles
        // cycles represented as maps with map[node] --> index in cycle
        std::vector<std::map<int, int>> cycles;
        for (int i = 1; i <= n; i++){

            if (cycle_id[i] != -2) continue;

            vi path {i};
            int pos = i;
            while (cycle_id[next[pos]] == -2){
                pos = next[pos];
                cycle_id[pos] = -3; // leave trace
                path.push_back(pos); // add to path
            }

            bool in_cycle = false;
            std::map<int, int> cycle;
            for (auto& p: path){
                in_cycle = in_cycle || p == next[pos]; // determine if we're in cycle yet
                if (in_cycle) cycle[p] = cycle.size(); // mark index in cycle if we're in cycle
                cycle_id[p] = in_cycle ? cycles.size() : -1; // mark id
            }

            cycles.push_back(cycle);
            
        }

        // For every non cycle node, determine distance to respective cycle

        vi cyc_dist (n + 1);
        for (int i = 1; i <= n; i++){

            // we want to start at node just before cycle begins
            if (cycle_id[i] != -1 || cycle_id[next[i]] == -1) continue;

            std::stack<int> s;
            s.push(i);
            cyc_dist[i] = 1;
            while (!s.empty()){
                int cur = s.top();
                s.pop();
                for (auto& p: before[cur]){
                    cyc_dist[p] = cyc_dist[cur] + 1;
                    s.push(p);
                }
            }
            
        }

        // Quick Binary jumping which we use later to determine if two nodes share the same cycle

        std::vector<vi> dest (n + 1, vi (19));
        for (int i = 1; i <= n; i++) dest[i][0] = next[i];
        for (int pow = 1; pow < 19; pow++){
            for (int i = 1; i <= n; i++){
                dest[i][pow] = dest[dest[i][pow - 1]][pow - 1];
            }
        }
        
        while (q--){
            int a, b;
            std::cin >> a >> b;

            //if they dont share same cycle, impossible
            if (cycle_id[dest[a][18]] != cycle_id[dest[b][18]]){
                std::cout << -1 << '\n';
                continue;
            }

            //if atleast one is in a cycle
            if (cycle_id[a] != -1 || cycle_id[b] != -1){

                //if b is not in cycle but a is, a can never exit the cycle, therefore can never reach b
                if (cycle_id[b] == -1){
                    std::cout << -1 << '\n';
                    continue;
                }

                //move to cycle
                int dist = cyc_dist[a];
                for (int i = 0; i < 18; i++){
                    if (dist & (1 << i)) a = dest[a][i];
                }

                int a_ind = cycles[cycle_id[a]][a];
                int b_ind = cycles[cycle_id[b]][b];

                int diff = a_ind <= b_ind ? b_ind - a_ind : (cycles[cycle_id[a]].size() + b_ind) - a_ind;

                std::cout << dist + diff << '\n';
                
            }

            // both are in tree
            else{

                if (cyc_dist[b] > cyc_dist[a]){
                    std::cout << -1 << '\n';
                    continue;
                }

                int diff = cyc_dist[a] - cyc_dist[b];

                for (int i = 0; i < 18; i++){
                    if (diff & (1 << i)) a = dest[a][i];
                }

                std::cout << (a == b ? diff : -1) << '\n';
                
            }
            
        }
        
    }
    
    return 0;
    
}