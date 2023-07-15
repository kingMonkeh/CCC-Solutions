#include <bits/stdc++.h>

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        std::vector<long long> a (n);
        long long sum = 0, operations = 0;
        bool segment = false;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            sum += llabs(a[i]);
            if (a[i] < 0 && !segment){
                segment = true;
            }
            else if (a[i] > 0 && segment){
                segment = false;
                operations++;
            }
        }
        if (segment) operations++;
        std::cout << sum << ' ' << operations << '\n';
    }
    return 0;
}