#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    int ans = 0;
    vi x (n);

    for (int i = 0; i < n; i++){
        std::cin >> x[i];
    }

    std::map<int, int> cnt;
    std::set<int> s;
    int l = 0, r = 0;
    //each iteration, we count how many subarrays with <= k distinct start at index l
    while (l < n){
        //push boundary as far as possible
        while (r < n && s.size() + (s.count(x[r]) == 0) <= k){
            cnt[x[r]]++;
            s.insert(x[r]);
            r++;
        }
        //push l
        ans += r - l;
        cnt[x[l]]--;
        if (cnt[x[l]] == 0){
            s.erase(x[l]);
        }
        l++;
    }

    std::cout << ans;
    
    return 0;
    
}