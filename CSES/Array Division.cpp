#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

int n, k, ans = LONG_LONG_MAX;
vi x;

bool good (int mx){
    int seg = 1, sum = 0;
    for (int i = 0; i < n; i++){
        if (x[i] > mx) return false;
        sum += x[i];
        if (sum > mx){
            seg++;
            if (seg > k) return false;
            sum = x[i];
        }
    }
    ans = std::min(ans, mx);
    return true;
}

signed main (){

    std::ios_base::sync_with_stdio(false);
    
    std::cin >> n >> k;

    x.resize(n);
    for (int i = 0; i < n; i++){
        std::cin >> x[i];
    }

    int l = 0, r = 1e14 * 2 + 1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (good(mid)) r = mid - 1;
        else l = mid + 1;
    }

    std::cout << ans;
    
    return 0;
    
}