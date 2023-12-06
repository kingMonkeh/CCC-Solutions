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

consider the vertex where the triangles meet

since the legs must be parallel to axis

it stands that the points that form the legs must be directly above or to the side of the vertex

then it just stands to calculate all their possible combinations for each vertex

*/

std::map<int, vi> x, y;

int great (vi& v, int sz, int cur){
    int bot = 0, top = sz;
    int mid;
    while (bot < top){
        mid = (bot + top) / 2;
        if (v[mid] <= cur) bot = mid + 1;
        else top = mid;
    }
    return bot;
}

int less (vi& v, int sz, int cur){
    int bot = 0, top = sz;
    int mid;
    while (bot < top){
        mid = (bot + top) / 2;
        if (v[mid] < cur) bot = mid + 1;
        else top = mid;
    }
    return bot;
}

signed main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        std::vector<pii> p (n);
        for (int i = 0; i < n; i++){
            std::cin >> p[i].f >> p[i].s;
            x[p[i].f].push_back(p[i].s); //vertical lines on x =
            y[p[i].s].push_back(p[i].f); //horizontal lines on y = 
        }

        for (auto& v: x) std::sort(v.s.begin(), v.s.end());
        for (auto& v: y) std::sort(v.s.begin(), v.s.end());

        int ans = 0;
        for (int i = 0; i < n; i++){
            int above = x[p[i].f].size() - great(x[p[i].f], x[p[i].f].size(), p[i].s);
            int below = less(x[p[i].f], x[p[i].f].size(), p[i].s);
            int right = y[p[i].s].size() - great(y[p[i].s], y[p[i].s].size(), p[i].f);
            int left = less(y[p[i].s], y[p[i].s].size(), p[i].f);;
            ans += above * right * below * left;
            ans += above * left * below * right;
        }       

        std::cout << ans << '\n';

    }

    return 0;

}