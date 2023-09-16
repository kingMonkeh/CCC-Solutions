#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

//fenwick tree range query
//sort be lefts least to greatest
//if same left, sort rights greatest to least, this way when going backwards, the smaller rights are added first
//making our answer correct when calculating for the bigger rights

int s;
std::vector<int> fenwick (200000 + 1, 0);

void update (int ind){
    while (ind <= s){
        fenwick[ind]++;
        ind += ind & (-ind);
    }
}

int query (int x){
    int ret = 0;
    while (x > 0){
        ret += fenwick[x];
        x -= x & -x;
    }
    return ret;
}

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::pair<std::pair<int, int>, int>> segs (n);
    std::set<int> rights;
    std::map<int, int> order;
    for (int i = 0; i < n; i++){
        segs[i].s = i;
        std::cin >> segs[i].f.f >> segs[i].first.s;
        rights.insert(segs[i].f.s);
    }

    int ind = 0;
    for (auto& a: rights){
        order[a] = ++ind;
    } s = ind;

    vi ans (n, 0);
    std::sort(segs.begin(), segs.end(), [](std::pair<std::pair<int,int>,int>& a, std::pair<std::pair<int,int>,int>& b){
        return (a.f.f == b.f.f ? a.f.s > b.f.s : a.f.f < b.f.f);
    });

    for (int i = n - 1; i >= 0; i--){
        ans[segs[i].s] = query(order[segs[i].f.s]);
        update(order[segs[i].f.s]);
    }

    for (auto& a: ans) std::cout << (a > 0 ? 1 : 0) << ' '; std::cout << '\n';

    for (int i = 0; i <= s; i++) fenwick[i] = 0;
    for (int i = 0; i < n; i++) ans[i] = 0;
    
    for (int i = 0; i < n; i++){
        ans[segs[i].s] = i - query(order[segs[i].f.s] - 1);
        update(order[segs[i].f.s]);
    }

    for (auto& a: ans) std::cout << (a > 0 ? 1 : 0) << ' '; std::cout << '\n';
        
    return 0;
    
}