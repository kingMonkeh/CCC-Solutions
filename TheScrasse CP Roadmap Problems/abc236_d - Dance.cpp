//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

int N;
long long ANS = 0;
std::vector<std::pair<int, int>> paired;
std::vector<std::vector<long long>> A;
std::vector<int> vis;

//try every pair set lmao
void solve (int person){

    if (paired.size() == N){
        long long ans = 0;
        for (auto& p: paired){
            ans ^= A[p.first][p.second];
        }
        ANS = std::max(ANS, ans);
        return;
    }
    
    if (vis[person]) solve (person + 1);
    
    for (int i = person + 1; i < 2 * N; i++){
        if (!vis[person] && !vis[i]){
            vis[person] = true;
            vis[i] = true;
            paired.push_back(std::make_pair(person, i));
            solve (person + 1);
            paired.pop_back();
            vis[person] = false;
            vis[i] = false;
        }
    }
    
}

int main(){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        std::cin >> N;
        vis.resize(2 * N);
        A.resize(2 * N - 1, std::vector<long long> (2 * N));

        for (int i = 0; i < 2 * N - 1; i++){
            for (int j = i + 1; j < 2 * N; j++){
                std::cin >> A[i][j];
            }
        }

        solve(0);

        std::cout << ANS << '\n';
        
    }
    
    return 0;
    
}