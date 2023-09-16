#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    vi cur (n);
    for (int i = 1; i <= n; i++) cur[i - 1] = i;

    while (true){

        if (cur.size() == 1){
            std::cout << cur[0];
            break;
        }
        
        vi after;
        for (int i = 0; i < cur.size(); i++){
            if (i % 2 == 0){
                after.push_back(cur[i]);
            }
            else std::cout << cur[i] << ' ';
        } 
        if (cur.size() % 2 == 0){
            cur = after;
        }
        else{
            int starter = after.back();
            after.pop_back();
            cur = after;
            cur.insert(cur.begin(), starter);
        }
    }
        
    return 0;
    
}