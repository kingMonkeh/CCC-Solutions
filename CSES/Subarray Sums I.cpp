#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> a (n);

    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int l = 0, r = 0, sum = a[0], ans = 0;
    while (r < n){
        if (sum == x) ans++;
        if (r < n - 1 && sum + a[r + 1] > x){
            sum -= a[l];
            l++;
            if (l > r){
                r++;
                sum = a[l];
            }
        }
        else{
            r++;
            if (r != n) sum += a[r];
        }
    }

    std::cout << ans;
    
    return 0;
    
}