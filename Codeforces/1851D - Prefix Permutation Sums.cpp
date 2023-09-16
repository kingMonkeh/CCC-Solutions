#include <bits/stdc++.h>
 
int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {
 
        long long n;
        std::cin >> n;
 
        std::vector<int> used (n + 1, 0);
        std::vector<long long> a (n - 1);
        for (int i = 0; i < n - 1; i++) std::cin >> a[i];

        long long final = n * (n + 1) / 2;
        if (a[n - 2] > final){
            std::cout << "NO\n";
        }
        else if (a[n - 2] == final){
            std::vector<long long> extra;
            if (a[0] > n) extra.push_back(a[0]);
            else used[a[0]] = true;
            for (int i = 0; i < n - 2; i++){
                long long diff = llabs(a[i] - a[i + 1]);
                if (diff <= n && !used[diff]){
                    used[diff] = true;
                }
                else{
                    extra.push_back(diff);
                }
            }
            if (extra.size() > 1){
                std::cout << "NO\n";
            }
            else if (extra.size() == 1){
                std::string ans = "NO\n";
                for (int i = 1; i <= n; i++){
                    if (!used[i] && llabs(extra[0] - i) <= n && !used[llabs(extra[0] - i)]){
                        ans = "YES\n";
                        break;
                    }
                }
                std::cout << ans;
            }
            else std::cout << "YES\n";
        }
        else{
            a.push_back(final);
            if (a[0] > n){
                std::cout << "NO\n";
            }
            else{
                std::string ans = "YES\n";
                for (int i = 0; i < n - 1; i++){
                    long long diff = llabs(a[i] - a[i + 1]);
                    if (diff <= n && !used[diff]){
                        used[diff] = true;
                    }
                    else{
                        ans = "NO\n";
                        break;
                    }
                }
                std::cout << ans;
            }
        }
        
    }
 
    return 0;
    
}