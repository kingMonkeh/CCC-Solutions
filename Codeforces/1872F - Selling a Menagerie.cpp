#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

/*

basically, if an animal has no one fearing it
just sell it first
do this until only animals that have some other animal fearing it are left
its guranteed that this will form a cycle (every animal is pointing to another and has another animal pointing at it)

afterward, we recognize that every animal can be sold for double value
except for the last animal sold in a cycle
therefore, we want to ensure the last animal we sell in a cycle is the cheapest one

rinse and repeat for all disjoint cycles

*/

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){
    
        int n;
        std::cin >> n;

        vi a (n + 1), c (n + 1), back (n + 1, 0);
        for (int i = 1; i <= n; i++){
            std::cin >> a[i];
            back[a[i]]++;
        }
        for (int i = 1; i <= n; i++) std::cin >> c[i];

        //eliminate the animals with no one fearing them
        vi vis (n + 1, 0);
        vi ans;
        for (int i = 1; i <= n; i++){
            if (back[i] == 0 && !vis[i]){
                ans.push_back(i);
                vis[i] = true;
                back[a[i]]--;
                //its possible that after selling an animal, the animal that this one was scared of
                //has no more fearful animals left, therefore you can just sell that one as well
                if (back[a[i]] == 0){
                    std::stack<int> s;
                    s.push(a[i]);
                    vis[a[i]] = true;
                    while (!s.empty()){
                        int cur = s.top();
                        s.pop();
                        ans.push_back(cur);
                        back[a[cur]]--;
                        if (back[a[cur]] == 0 && !vis[a[cur]]){
                            s.push(a[cur]);
                            vis[a[cur]] = true;
                        }
                    }
                }
            }
        }

        //deal with cycles
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                vi path; //keep track of path
                std::stack<int> s;
                s.push(i);
                vis[i] = true;
                //keep track of cheapest animal on path
                int ii = 0, ind = 0, mn = inf;
                while (!s.empty()){
                    int cur = s.top();
                    s.pop();
                    path.push_back(cur);
                    if (!vis[a[cur]]){
                        s.push(a[cur]);
                        vis[a[cur]] = true;
                    }
                    //keep track of index of cheapest animal
                    if (c[cur] < mn){
                        ind = ii;
                        mn = c[cur];
                    }
                    ii++;
                }
                //start from animal after the cheapest one
                for (int j = 0; j < path.size(); j++){
                    ind++;
                    ind %= path.size();
                    ans.push_back(path[ind]);
                }
            }
        }

        //output
        for (int i = 0; i < n; i++){
            std::cout << ans[i] << ' ';
        }

        std::cout << '\n';
        
    }
    
    return 0;
    
}