#include <bits/stdc++.h>

int main (){ 
    int tests;
    std::cin >> tests;
    while (tests--){
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> segments (m);
        for (int i = 0; i < m; i++){
            int l, r;
            std::cin >> l >> r;
            segments[i] = std::make_pair(l, r);
        }
        int q;
        std::cin >> q;
        std::vector<int> queries (q);
        for (int i = 0; i < q; i++){
            std::cin >> queries[i];
        }
        //Binary Search
        //If you've applied q queries:
        //And you have 0 beautiful, then any # of queries less than q will also not work
        //If you have some amount of beautiful segments, any # of queries > q will be a waste
        int low = 0, high = q;
        while (low != high){
            int mid = (low + high) / 2;
            std::vector<int> psa (n + 1, -1); //Default -1, as if you're placing 0, 1's - 0's
            //Apply queries
            for (int i = 0; i <= mid; i++){
                psa[queries[i]] = 1;
            }
            //Create Prefix Sum Array
            psa[0] = 0;
            for (int i = 1; i <= n; i++){
                psa[i] += psa[i - 1];
            }
            //Check segments
            bool beautiful = false;
            for (int i = 0; i < m; i++){
                if (psa[segments[i].second] - psa[segments[i].first - 1] > 0){
                    beautiful = true;
                }
            }
            if (beautiful){high = mid;}
            else {low = mid + 1;}
        }
        //No beautiful segments
        if (low == q) low = -2;
        std::cout << low + 1 << '\n';
    }
    return 0;
}