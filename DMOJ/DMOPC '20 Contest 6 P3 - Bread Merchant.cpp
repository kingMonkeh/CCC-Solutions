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

Idea:

how to mark node

assuming we have processed all adjacent nodes before hand

if there is police:
if there is even one adj node that leads to capture
police can force us there, therefore ans = 1, else ans = 0

if no police
the only way we lose
is that all adj nodes lead to capture
then regardless of where we went, we lose

*/

int n, m;
int p [500001], done [500001] = {0}, ans [500001], out [500001];
vi graph [500001], rgraph [500001];
std::queue<int> q;

void trypush (int cur){

    //If the current node will lead to us getting captured
    if (ans[cur]){
        for (auto& radj: rgraph[cur]){
            //if either all adj nodes have been processed or it has police
            //then we can solve it
            if (--out[radj] == 0 || p[radj]){
                q.push(radj);
            }
        }
    }
    else{
        for (auto& radj: rgraph[cur]){
            //if all adj nodes have been processed, we can solve
            if (--out[radj] == 0){
                q.push(radj);
            }
        }
    }
    
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) std::cin >> p[i];

        for (int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            rgraph[b].push_back(a);
            out[a]++;
        }

        //start off by solving all the cities with no out edges, since they gurantee capture
        for (int i = 1; i <= n; i++){
            if (out[i] == 0){
                ans[i] = 1;
                done[i] = 1;
                trypush(i);
            }
        }

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            if (done[cur]) continue;
            done[cur] = true;

            if (p[cur]){
                for (auto& adj: graph[cur]){
                    //if atleast one adj leads to getting captured
                    //then police can always force us that way
                    ans[cur] |= ans[adj];
                }
            }
            else{
                //only way to get captured if police cant force us
                //is that all adj lead to getting captured, meaning ggs regardless
                ans[cur] = 1;
                for (auto& adj: graph[cur]){
                    ans[cur] &= ans[adj];
                }
            }

            trypush(cur);
        }

        for (int i = 1; i <= n; i++){
            std::cout << ans[i] << (i == n ? "\n" : " ");
        }
        
    }
    
    return 0;
    
}