#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

//DP[ind][prev][leading zero][limited by max]
int DP [19][10][2][2];
std::string a, b;

int solve (std::string& num, int len, int ind, int prev, bool leadingzero, bool limit){

    //end
    if (ind == len) return 1;

    //recall
    if (prev != -1 && DP[ind][prev][leadingzero][limit] != -1) return DP[ind][prev][leadingzero][limit];

    //iterate
    int& ans = DP[ind][prev][leadingzero][limit] = 0;
    int upperbound = (limit ? num[ind] - '0' : 9);
    for (int i = 0; i <= upperbound; i++){
        //adjacent digit is same, illegal
        if (i == prev && prev != 0) continue;
        //"00" is in the middle of number and not leading, illegal
        if (i == prev && prev == 0 && !leadingzero) continue;
        ans += solve(num, len, ind + 1, i, leadingzero && i == 0, limit && i == upperbound);
    }

    return ans;
    
}

//check if number has adj digits that are the same, true = no, false = yes
bool good (std::string& num){
    bool ret = true;
    for (int i = 1; i < num.size(); i++){
        if (num[i] == num[i - 1]) ret = false;
    }
    return ret;
}

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> a >> b;

        //find number of ways to build numbers from 0 --> b
        memset(DP, -1, sizeof(DP));
        int ans = solve (b, b.size(), 0, -1, true, true);
        //subtract amount of ways from 0 --> a, this gives us the range between a and b
        memset(DP, -1, sizeof(DP));
        ans -= solve (a, a.size(), 0, -1, true, true);
        //if a was a valid number, we need to add it back since we just removed it earlier
        ans += good(a) ? 1 : 0;

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}