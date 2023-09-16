#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

signed main (){

    int n;
    std::cin >> n;

    int ans = 0;
    std::deque <int> k;
    std::map<int, int> fnd;
    for (int i = 0; i < n; i++){
        int num;
        std::cin >> num;
        if (fnd[num]){
            ans = std::max(ans, (int) k.size());
            while (!k.empty()){
                if (k.front() == num){
                    k.pop_front();
                    break;
                }
                fnd[k.front()] = false;
                k.pop_front();
            }
        }
        fnd[num] = true;
        k.push_back(num);
    } ans = std::max(ans, (int) k.size());

    std::cout << ans << '\n';
        
    return 0;
    
}