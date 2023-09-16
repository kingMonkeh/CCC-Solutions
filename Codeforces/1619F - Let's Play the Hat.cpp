#include <bits/stdc++.h>

struct num{
    int a, cnt;
};

int main() {
    
	std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
	while (tests--) {

        int n, m, k;
        std::cin >> n >> m >> k;

        //Find valid ratio of floors to ceilings that add up to n
        int f = floor((double) n / m), c = ceil((double) n / m);
        int fcnt, ccnt;
        for (int i = 1; i <= m && c * i <= n; i++){
            if ((n - i * c) % f == 0 && (n - i * c) / f == m - i){
                ccnt = i;
                fcnt = m - i;
            }
        }

        //We kinda just keep putting the people at the ceil tables
        //by going 1 2 3 4 5 6 ... n
        //then just looping through, the idea is that the total number of people playing at ceil tables in a round < n
        //therefore even if we wrap around, its guranteed that no person will be 2 tables ahead of another
        //since that would require people at ceil table > n, which isn't possible
        int player = 1;
        while (k--){

            for (int i = 0; i < ccnt; i++){
                std::cout << c << ' ';
                for (int j = 0; j < c; j++){
                    std::cout << player++ << ' ';
                    if (player % (n + 1) == 0){
                        player = 1;
                    }
                } std::cout << '\n';
            }

            int temp = player;
            for (int i = 0; i < fcnt; i++){
                std::cout << f << ' ';
                for (int j = 0; j < f; j++){
                    std::cout << temp++ << ' ';
                    if (temp % (n + 1) == 0){
                        temp = 1;
                    }
                } std::cout << '\n';
            }
            
        }

        std::cout << '\n';
        
	}
    
	return 0;
    
}