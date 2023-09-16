#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int ans = 0;
    std::vector<int> a (n + 1);
    vi psa (n + 1);
    std::map<int, int> modcnt;
    psa[0] = 0;
    modcnt[0] = 1;
    for (int i = 1; i <= n; i++){
        std::cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
        //don't forget about negatives, imagine n = 4, and psa[i] % n = -3 and psa[j] % n = 1
        //-3 - 1 = -4, -4 % 4 = 0
        modcnt[(psa[i] % n + n) % n]++;
    }

    //(x - y) % mod = (x % mod - y % mod) % mod
    //therefore, for x % mod - y % mod to equal 0
    //x % mod must equal y % mod
    //therefore n * (n - 1) / 2
    for (auto& rem: modcnt){
        ans += rem.second * (rem.second - 1) / 2;
    }

    std::cout << ans;
    
    return 0;
    
}