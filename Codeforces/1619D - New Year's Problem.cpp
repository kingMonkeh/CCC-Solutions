/*

Binary Search

Basically we notice that if a max min joy value of x can be obtained
Then any lower value of x can also be attained

If x cannot be attained, any larger x value cannot also be obtained

Therefore we can binary search on the possible answer

How do we check if a value of x can be obtained?

Notice that since we can only visit n - 1 shops, and we have n people we need to buy gifts for
There must exist a shop that has 2 gifts or more that have a value of x or greater

If such a shop exists, then everyone else can go to whatever shops they please and buy from there

Edge Case: There's only one shop, everyone has to buy from there, doesn't matter about pairs

*/

#include <bits/stdc++.h>

int m, n;
std::vector<std::vector<int>> p;

bool possible (int x){

    std::vector<bool> satisfied (n, false);
    bool pair = false;
    
    for (int i = 0; i < m; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (p[i][j] >= x){
                satisfied[j] = true;
                cnt++;
            }
        }
        if (cnt > 1) pair = true;
    }

    if (!pair && m > 1) return false;
    else{
        bool ret = true;
        for (bool person: satisfied){
            ret = ret && person;
        }
        return ret;
    }
    
}

int main() {
    
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
	while (tests--) {

        std::cin >> m >> n;
        p.resize(m, std::vector<int> (n));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                std::cin >> p[i][j];
            }
        }

        int l = 1, r = 1e9 + 1;
        while (l < r){
            int mid = (l + r) / 2;
            if (possible(mid)){
                l = mid + 1;
            }
            else r = mid;
        }

        std::cout << --r << '\n';

        p.clear();
        
	}
    
	return 0;
    
}