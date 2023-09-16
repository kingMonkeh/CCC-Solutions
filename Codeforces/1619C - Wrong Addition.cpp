#include <bits/stdc++.h>

int main() {
    
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
	while (tests--) {

        long long a, s;
        std::cin >> a >> s;

        std::vector<int> b;
        
        while (s > 0){
            int slast = s % 10;
            int alast = a % 10;
            if (alast <= slast){
                b.push_back(slast - alast);
            }
            else{
                s /= 10;
                slast += (s % 10) * 10;
                if (slast >= 10 && slast <= 18){
                    b.push_back(slast - alast);
                }
                else{
                    std::cout << -1 << '\n';
                    goto nxt;
                }
            }
            s /= 10;
            a /= 10;
        }

        if (a) std::cout << -1 << '\n';
        else{
            while (b.back() == 0) b.pop_back();
            for (int i = b.size() - 1; i >= 0; i--){
                std::cout << b[i];
            }
            std::cout << '\n';
        }

        nxt:;
        
	}
	return 0;
}