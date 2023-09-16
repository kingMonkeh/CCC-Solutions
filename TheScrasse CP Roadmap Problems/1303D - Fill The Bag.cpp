#include <bits/stdc++.h>

/*

Observations: 

1. Worst case, we divide all the boxes into 1's and just add them all up, this is the maximum value we can possibly attain
if this sum < n, its not possible

2. If we convert n into binary, we notice that only the bits that are 1 in n, need to be acquired

*/

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        long long n, m, sum = 0;
        std::cin >> n >> m;
        std::vector<int> a (m);
        std::map<int, int> cnt;
        for (int i = 0; i < m; i++){
            std::cin >> a[i];
            for (int j = 0; j < 60; j++){
                if ((1 << j) & a[i]){
                    cnt[j]++;
                    break;
                }
            }
            sum += a[i];
        }

        if (sum < n){
            std::cout << -1 << '\n';
            continue;
        }

        int i = 0, ans = 0;
        while (i < 60){
            //bit is required
            if (((long long) 1 << i) & n){
                //we already have the bit required, we don't need to divide
                if (cnt[i]){
                    cnt[i]--; //use the bit
                }
                //we have to divide to get this bit
                else{
                    //Note that we can also skip all the i values that we iterate across, since in the process of dividing this bit, we will obtain every bit smaller than it as well, meaning whether or not we needed them, we can use them without any additional cost
                    while (i < 60 && cnt[i] == 0){
                        i++;
                        ans++;
                    }
                    cnt[i]--;
                    continue;
                }
            }
            //we have leftover bits, we can combine them into a greater bit, note it takes 2 of a bit to convert into a higher bit, by binary addition, 1 + 1 = 10
            cnt[i + 1] += cnt[i] / 2;
            i++;
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}