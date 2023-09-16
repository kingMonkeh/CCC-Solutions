#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n, x;
    std::cin >> n >> x;

    int ans = 0;
    std::vector<int> a (n + 1);
    vi psa (n + 1);
    std::map<int, int> cnt;
    psa[0] = 0;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
        if (psa[i] == x) ans++;
        ans += cnt[psa[i] - x];
        cnt[psa[i]]++;
    }

    std::cout << ans;
    
    return 0;
    
}