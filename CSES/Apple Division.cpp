#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

std::vector<int> nums;
int ans = 1e10;
void solve (int i, int s1, int s2){

    if (i == nums.size()){
        ans = std::min(ans, llabs(s1 - s2));
        return;
    }

    solve (i + 1, s1 + nums[i], s2);
    solve (i + 1, s1, s2 + nums[i]);
    
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        nums.resize(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        solve (0, 0, 0);

        std::cout << ans << '\n';
        
    }

    return 0;
    
}