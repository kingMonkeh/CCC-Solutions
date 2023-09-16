#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

struct movie{
    int a, b;
    bool operator < (movie& x) {return b < x.b;}
};

signed main (){

    int n, x;
    std::cin >> n >> x;

    vi a (n);
    std::map<int, std::vector<int>> idx;
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
        idx[a[i]].push_back(i + 1);
    }

    for (int i = 0; i < n; i++){
        int b = x - a[i];
        if (b == a[i]){
            if (idx[b].size() >= 2){
                std::cout << idx[b][0] << ' ' << idx[b][1];
                return 0;
            }
        }
        else if (!idx[b].empty()){
            std::cout << i + 1 << ' ' << idx[b][0];
            return 0;
        }
    }

    std::cout << "IMPOSSIBLE";
        
    return 0;
    
}