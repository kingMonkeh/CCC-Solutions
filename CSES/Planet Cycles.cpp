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

very similar to previous problem
in fact it is simpler

find all cycles and trees of graph

ans = cyc_dist + cycle.size

*/

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){
    
        int n;
        std::cin >> n;

        vi next (n + 1);
        std::vector<vi> before (n + 1);
        for (int i = 1; i <= n; i++){
            std::cin >> next[i];
            before[next[i]].push_back(i);
        }

        //-3 = processing
        //-2 = not processed
        //-1 = not in cycle
        //0 >= cycle id

        //divide graph into trees and cycles
        std::vector<std::map<int, int>> cycles;
        vi cycle_id (n + 1, -2);
        for (int i = 1; i <= n; i++){
            if (cycle_id[i] != -2) continue; //already processed
            vi path {i};
            int at = i;
            while (cycle_id[next[at]] == -2){
                at = next[at];
                cycle_id[at] = -3; //leave trace
                path.push_back(at);
            }
            std::map<int, int> cycle;
            bool in_cycle = false;
            for (auto& p: path){
                in_cycle = in_cycle || p == next[at];
                cycle_id[p] = in_cycle ? cycles.size() : -1;
                if (in_cycle) cycle[p] = cycle.size();
            }
            cycles.push_back(cycle);
        }

        //calculate cyc dist
        vi cyc_dist (n + 1, 0);
        for (int i = 1; i <= n; i++){
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

        //Binary jump array
        std::vector<vi> dest (n + 1, vi (19));
        for (int i = 1; i <= n; i++) dest[i][0] = next[i];
        for (int pow = 1; pow < 19; pow++){
            for (int i = 1; i <= n; i++){
                dest[i][pow] = dest[dest[i][pow - 1]][pow - 1];
            }
        }

        //Compute answer
        for (int i = 1; i <= n; i++){
            int at = i;
            for (int pow = 0; pow < 19; pow++){
                if (cyc_dist[i] & 1 << pow) at = dest[at][pow];
            }
            std::cout << cyc_dist[i] + cycles[cycle_id[at]].size() << ' ';
        }
        
    }
    
    return 0;
    
}