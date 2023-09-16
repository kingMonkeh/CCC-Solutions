#include <bits/stdc++.h>

/*

We notice that if we go from mountains
a -> b -> c -> d

The energy used is
h[b] - h[a] + h[c] - h[b] + h[d] - h[c]

This cancels to
h[d] - h[a] <= e

Rearranging gives us
h[d] <= h[a] + e

By this logic, a path starting at mountain a is valid so long as for every mountain i that it crosses
h[i] <= h[a] + e

We will create DSU and answer queries by increasing h[a] + e

*/

int par [200001];
int sizee [200001];

int root (int x){
    //return par[x] == x ? x : root(par[x]);
    return (par[x] == x) ? x : (par[x] = root(par[x]));
}

void merge (int x, int y){
    x = root(x), y = root(y);
    par[x] = y;
    /*
    if (sizee[x] < sizee[y]){
        par[x] = y;
        sizee[y] += sizee[x];
    }
    else{
        par[y] = x;
        sizee[x] += sizee[y];
    }
    */
}

int main (){

    std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--){
        
        int n, m;
        std::cin >> n >> m;
        
        int h [n + 1];
        for (int i = 1; i <= n; i++){
            std::cin >> h[i];
            par[i] = i;
            sizee[i] = i;
        }

        struct edge{
            int u, v, maxx;
            bool operator < (edge& x){
                return this->maxx < x.maxx;
            }
        };
        std::vector<edge> edges (m);
        for (int i = 0; i < m; i++){
            std::cin >> edges[i].u >> edges[i].v;
            edges[i].maxx = std::max(h[edges[i].u], h[edges[i].v]);
        }
        //Sort edges by max(u, v)
        std::sort(edges.begin(), edges.end());

        //for (auto& edge: edges) std::cout << std::max(h[edge.first], h[edge.second]) << '\n';

        int q;
        std::cin >> q;
        struct que{
            int a, b, e, ind;
        };
        std::vector<que> queries (q); //a, b, e, query #
        for (int i = 0; i < q; i++){
            std::cin >> queries[i].a >> queries[i].b >> queries[i].e;
            queries[i].ind = i;
        }

        //Sort queries by increasing h[a] + e
        std::sort(queries.begin(), queries.end(), [&](que& x, que& y){
            return h[x.a] + x.e < h[y.a] + y.e;
        });

        std::vector<int> ans (q, 0);
        for (int i = 0, j = 0; i < q; i++){
            //for (auto& x: queries[i]) std::cout << x << ' '; std::cout << '\n';
            while (j < m && edges[j].maxx <= h[queries[i].a] + queries[i].e){
                merge(edges[j].u, edges[j].v);
                j++;
            }
            if (root(queries[i].a) == root(queries[i].b)) ans[queries[i].ind] = 1;
        }

        for (int i = 0; i < q; i++) std::cout << (ans[i] == 1 ? "YES\n" : "NO\n");
        
    }
    
    return 0;
    
}