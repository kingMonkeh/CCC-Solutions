#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

int n, t;
int ans = LONG_LONG_MAX;
vi k (200000);

bool good (int s){
    int tot = 0;
    for (int i = 0; i < n; i++){
        tot += s / k[i];
        if (tot >= t){
            ans = std::min(ans, s);
            return true;
        }
    }
    return false;
}

signed main (){

    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> t;

    for (int i = 0; i < n; i++) std::cin >> k[i];

    int l = 0, r = 1e18 + 1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (good(mid)) r = mid - 1;
        else l = mid + 1;
    }

    std::cout << ans;
        
    return 0;
    
}