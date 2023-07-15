/*

notice that bitwise AND only ever makes the number the same or decreases it
Therefore min sum, is to group all vampires in one group and take that bitwise &, lets call it b

if b > 0, you can only have 1 group, since all nubmers share the same bit, meaning if you try splitting into more groups, each group will also have strength b

if b == 0 however, creating more groups of strength b will not change the sum
Therefore we want to maximize the number of groups with strength 0

To do this, notice groups must be contiguous
meaning we can just greedily go through left to right
keep track of our bitwise AND, and when it becomes 0, terminate the group and start a new one
You only require one 0, to make the entire group zero strength

*/

#include <bits/stdc++.h>

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        
        int b = a[0];
        for (int i = 1; i < n; i++) b = b & a[i];

        if (b > 0){
            std::cout << 1 << '\n';
        }

        else{
            int ans = 1;
            int cur = a[0];
            for (int i = 1; i < n; i++){
                if (cur == 0){
                    ans++;
                    cur = a[i];
                }
                else{
                    cur = cur & a[i];
                }
            }
            if (cur != 0) ans--;
            std::cout << ans << '\n';
        }
        
    }

    return 0;
    
}