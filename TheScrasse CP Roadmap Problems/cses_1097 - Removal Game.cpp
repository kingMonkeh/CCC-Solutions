#include <bits/stdc++.h>

/*



*/

long long DP [5000][5000];
std::vector<int> x;

long long solve (int l, int r){
    //Can't take
    if (l > r){
        return 0;
    }
    //Look up
    if (DP[l][r] != -1) return DP[l][r];
    //Take from left
    long long takeleft = x[l] + std::min(solve(l + 2, r), solve(l + 1, r - 1));
    //Take from right
    long long takeright = x[r] + std::min(solve(l, r - 2), solve(l + 1, r - 1));

    return DP[l][r] = std::max(takeleft, takeright);
    
}

int main (){

    int n;
    std::cin >> n;
    x.resize(n);
    memset(DP, -1, sizeof(DP));
    
    for (int i = 0; i < n; i++) std::cin >> x[i];

    long long ans = solve(0, n - 1);

    std::cout << ans << '\n';
    
    return 0;
    
}