#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

/*

notice that if a given number x moves, the only other numbers that get affected are x - 1 and x + 1

*/

signed main (){

    int n, m;
    std::cin >> n >> m;

    vi x (n + 1);
    vi idx (n + 1);
    for (int i = 1; i <= n; i++){
        std::cin >> x[i];
        idx[x[i]] = i;
    }

    vi state (n + 1, 0);
    int ans = 1;
    for (int i = 2; i <= n; i++){
        if (idx[i] < idx[i - 1]){
            ans++;
            state[i] = 1;
        }
    }

    for (int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        std::swap(x[a], x[b]);
        idx[x[a]] = a, idx[x[b]] = b;
        int x1 = x[a], x2 = x[b];
        if (x1 - 1 > 0 && idx[x1] < idx[x1 - 1] && state[x1] == 0){
            ans++;
            state[x1] = 1;
        }
        else if (x1 - 1 > 0 && idx[x1] > idx[x1 - 1] && state[x1] == 1){
            ans--;
            state[x1] = 0;
        }
        if (x1 + 1 <= n && idx[x1 + 1] < idx[x1] && state[x1 + 1] == 0){
            ans++;
            state[x1 + 1] = 1;
        }
        else if (x1 + 1 <= n && idx[x1 + 1] > idx[x1] && state[x1 + 1] == 1){
            ans--;
            state[x1 + 1] = 0;
        }
        if (x2 - 1 > 0 && idx[x2] < idx[x2 - 1] && state[x2] == 0){
            ans++;
            state[x2] = 1;
        }
        else if (x2 - 1 > 0 && idx[x2] > idx[x2 - 1] && state[x2] == 1){
            ans--;
            state[x2] = 0;
        }
        if (x2 + 1 <= n && idx[x2 + 1] < idx[x2] && state[x2 + 1] == 0){
            ans++;
            state[x2 + 1] = 1;
        }
        else if (x2 + 1 <= n && idx[x2 + 1] > idx[x2] && state[x2 + 1] == 1){
            ans--;
            state[x2 + 1] = 0;
        }
        std::cout << ans << '\n';
    }

    
        
    return 0;
    
}