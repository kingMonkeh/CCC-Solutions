#include <bits/stdc++.h>

/*

question is basically asking to maximize the # of prefix sums = 0

observation #1
when we change the value of 0 --> x
All numbers before 0 dont get affected
Zero and all numbers after it will be increased by x

Therefore, we keep track of the freq of each prefix sum after a 0
Then the one that is most frequent, we will set 0 equal to it
So that it cancels out all of that most frequent prefix sum

When multiple 0's are introduced, we just split it up into segments
Each 0 responsible for all the numbers after it up until the next 0
Notice that what we change one 0 to doesn't affect the next

if we change one 0 to x
All prefixes after it will only be affected by a constant amount
so if in the next segment, the most frequent prefix is y
then the new most frequent prefix will just be y + x, which is still the same # of prefixes

*/

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        bool init = true;
        int ans = 0, max_freq = 0;
        long long prefixSum = 0;
        std::map<long long, int> freq;

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++){
            
            std::cin >> a[i];

            //segment start or end
            if (a[i] == 0){

                if (init){
                    init = false;
                    ans += freq[0];
                }

                else ans += max_freq;
                
                freq.clear();
                max_freq = 0;
                
            }
            
            prefixSum += a[i];
            freq[prefixSum]++;
            max_freq = std::max(max_freq, freq[prefixSum]);
            
        }

        if (init == false)
            ans += max_freq;
        else
            ans += freq[0];

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}