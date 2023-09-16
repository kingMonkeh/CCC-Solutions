#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define f first
#define s second
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int n, k;
vi x;

signed main (){

    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> k;

    x.resize(n);
    for (int i = 0; i < n; i++){
        std::cin >> x[i];
    }

    ordered_set s;
    for (int i = 0; i < k; i++){
        s.insert({x[i], i});
    }

    for (int l = 0, r = k; r < n; r++, l++){
        if (k & 1) std::cout << s.find_by_order(k / 2)->f << ' ';
        else std::cout << s.find_by_order(k / 2 - 1)->f << ' ';
        s.erase({x[l], l});
        s.insert({x[r], r});
    } 
    if (k & 1) std::cout << s.find_by_order(k / 2)->f << ' ';
    else std::cout << s.find_by_order(k / 2 - 1)->f << ' ';
    
    return 0;
    
}