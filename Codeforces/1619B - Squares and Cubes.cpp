#include <bits/stdc++.h>

int main() {
    
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
	while (tests--) {

        long long n;
        std::cin >> n;

        std::map<long long, int> found;
        int ans = 0;
        for (long long i = 1; i <= floor(sqrt(n)); i++){
            if (!found[i * i] && i * i <= n) ans++;
            found[i * i] = true;
            if (!found[i * i * i] && i * i * i <= n) ans++;
            found[i * i * i] = true;
        }

        std::cout << ans << '\n';
        
	}
	return 0;
}