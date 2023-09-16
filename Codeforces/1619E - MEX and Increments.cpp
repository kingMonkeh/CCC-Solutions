#include <bits/stdc++.h>

struct num{
    int a, cnt;
};

int main() {
    
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
	while (tests--) {

        int n;
        std::cin >> n;

        std::vector<long long> freq (n + 1, 0);
        for (int i = 0; i < n; i++){
            int a;
            std::cin >> a;
            freq[a]++;
        }

        bool possible = true;
        long long pre_moves = 0;
        std::stack<int> s;
        for (int i = 0; i <= n; i++){

            if (!possible){
                std::cout << -1 << ' ';
                continue;
            }

            if (freq[i] != 0){
                std::cout << freq[i] + pre_moves << ' ';
                for (int j = 1; j < freq[i]; j++) s.push(i);
            }

            else{
                std::cout << pre_moves << ' ';
                if (!s.empty()){
                    pre_moves += i - s.top();
                    s.pop();
                }
                else{
                    possible = false;
                }
            }
            
        }

        std::cout << '\n';
        
	}
    
	return 0;
    
}