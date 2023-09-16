#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n, x;
    std::cin >> n >> x;

    std::vector<std::pair<int, int>> a (n);

    for (int i = 0; i < n; i++){
        std::cin >> a[i].f;
        a[i].s = i + 1;
    }

    std::sort(a.begin(), a.end());

    // a + b + c
    //lets fix a, and solve for b and c
    for (int i = 0; i < n; i++){
        int l = 0, r = n - 1;
        int twosum = x - a[i].f;
        while (l != r){
            if (l != i && r != i && a[l].f + a[r].f == twosum){
                std::cout << a[i].s << ' ' << a[l].s << ' ' << a[r].s;
                return 0;
            }
            if (a[l].f + a[r].f < twosum){
                l++;
            }
            else{
                r--;
            }
        }
    }

    std::cout << "IMPOSSIBLE";
    
    return 0;
    
}