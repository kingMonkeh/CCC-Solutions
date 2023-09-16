#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>



signed main (){

    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    ordered_set s;
    for (int i = 1; i <= n; i++) s.insert(i);

    int rmv = 0;
    while (s.size()){
        rmv = (rmv + k) % s.size();
        int p = *s.find_by_order(rmv);
        std::cout << p << ' ';
        s.erase(p);
    }
        
    return 0;
    
}