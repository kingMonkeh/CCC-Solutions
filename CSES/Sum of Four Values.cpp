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
 
    std::unordered_map<int, std::pair<int, int>> fnd;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int twosum = x - a[i] - a[j];
            if (fnd[twosum].f){
                std::cout << i + 1 << ' ' << j + 1 << ' ' << fnd[twosum].f << ' ' << fnd[twosum].s;
                return 0;
            }
        }
        for (int j = i - 1; j >= 0; j--){
            fnd[a[i] + a[j]] = {i + 1, j + 1};
        }
    }
 
    std::cout << "IMPOSSIBLE";
    
    return 0;
    
}