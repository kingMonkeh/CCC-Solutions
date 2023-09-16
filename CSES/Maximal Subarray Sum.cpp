#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
const int MOD = 1e9 + 7;

/*

1 * 9
2 * 90
3 * 900
4 * 9000
5 * 90000

*/

int kadane (vi& x){
    int best = x[0], sum = x[0];
    for (int i = 1; i < x.size(); i++){
        sum = std::max(sum + x[i], x[i]);
        best = std::max(best, sum);
    }
    return best;
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        vi x (n);
        for (int i = 0; i < n; i++) std::cin >> x[i];

        std::cout << kadane(x) << '\n';

    }

    return 0;
    
}