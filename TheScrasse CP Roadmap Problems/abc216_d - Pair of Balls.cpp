//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

int main(){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n, m;
        std::cin >> n >> m;

        std::queue<int> q;
        std::vector<std::vector<int>> freq (n + 1); //maintain current cylinders that have this color ball at the top
        std::vector<std::queue<int>> cyl (m);
        for (int i = 0; i < m; i++){
            int k;
            std::cin >> k;
            for (int j = 0; j < k; j++){
                int a;
                std::cin >> a;
                cyl[i].push(a);
            }
            freq[cyl[i].front()].push_back(i);
        }

        for (int i = 1; i <= n; i++){
            if (freq[i].size() == 2) q.push(i);
        }

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (auto& c: freq[cur]){
                cyl[c].pop();
                if (!cyl[c].empty()){
                    freq[cyl[c].front()].push_back(c);
                    if (freq[cyl[c].front()].size() == 2){
                        q.push(cyl[c].front());
                    }
                }
            }
        }

        bool ans = 1;
        for (auto& c: cyl){
            if (!c.empty()) ans = 0;
        }

        std::cout << (ans ? "Yes\n" : "No\n");
        
    }
    
    return 0;
    
}