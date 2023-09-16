#include <bits/stdc++.h>

/*

idea is greedy, to minimize the operations
we want to find the 2 closest elements with the smallest absolute difference
then just increment and decremenet them until theyre no longer sorted

*/

int main() {
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--){
		int n;
        std::cin >> n;
        std::vector<int> a (n);
        bool sorted = true;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            if (i > 0 && a[i] < a[i - 1]) sorted = false;
        }
        if (!sorted){
            std::cout << 0 << '\n';
            continue;
        }
        int bestFirst, bestSecond, diff = INT_MAX;
        int prev = a[0];
        for (int i = 1; i < n; i++){
            if (abs(a[i] - prev) < diff){
                bestFirst = prev, bestSecond = a[i];
                diff = abs(a[i] - prev);
            }
            prev = a[i];
        }
        std::cout << (abs(bestFirst - bestSecond) / 2) + 1 << '\n';
	}
}