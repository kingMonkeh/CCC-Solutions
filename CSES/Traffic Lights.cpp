#include <bits/stdc++.h>
 
#define int long long
#define vi std::vector<int>
 
struct seg{
    int l, r;
    bool operator < (const seg& x) const{
        return l < x.l;
    }
};
 
signed main (){
 
    std::ios_base::sync_with_stdio(false);
 
    int x, n;
    std::cin >> x >> n;
 
    std::multiset<int> lens;
    std::set<seg> segs;
    seg start; start.l = 0, start.r = x;
    segs.insert(start);
    lens.insert(x);
    
    int p;
    for (int i = 0; i < n; i++){  
        std::cin >> p;
        seg target; target.l = p, target.r = p;
        auto affected = segs.lower_bound(target);
        affected--;
        int l = affected->l, r = affected->r;
        lens.erase(lens.find(affected->r - affected->l));
        segs.erase(affected);
        seg first, second;
        first.l = l, first.r = p;
        second.l = p, second.r = r;
        lens.insert(p - l); lens.insert(r - p);
        segs.insert(first); segs.insert(second);
        std::cout << *lens.rbegin() << '\n';
    }
        
    return 0;
    
}