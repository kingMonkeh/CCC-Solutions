#include <bits/stdc++.h>

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n, m;
        std::cin >> n >> m;

        long long c [n][m];
        std::vector<long long> sum (m, 0);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                std::cin >> c[i][j];
                sum[j] += c[i][j];
            }
        }

        long long ans = 0;
        //for each column
        for (int j = 0; j < m; j++){
            //for each row
            std::vector<long long> col;
            for (int i = 0; i < n; i++){
                col.push_back(c[i][j]);
            }
            //sort great to least
            std::sort(col.begin(), col.end(), [](long long& x, long long& y){
                return x > y;
            });
            //idea is that we can get rid of the absolute value, by ensuring that the biggest number is first
            //since it just becomes regular subtraction
            for (int i = 0; i < n; i++){
                sum[j] -= col[i];
                ans += (col[i] * (n - i - 1) - sum[j]);
            }
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}