#include <bits/stdc++.h>

#define vi std::vector<int>
#define int long long

/*

greedy/optimal is to choose to change all numbers in window to median of window

we can find median by maintaining lower half and higher half

to calculate cost, we can do in O(1)

for the lower half
the cost would be 
med - a
med - b
med - c
med - med 

for upper half
cost would be
d - med
e - med
f - med
...

since size lower = size upper
med would cancel out

leaving the sum of upper - sum of lower
if k is odd, lower will have size 1 greater, so we have to add an extra med in again

*/

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n, k;
        std::cin >> n >> k;

        vi x (n);
        for (int i = 0; i < n; i++){
            std::cin >> x[i];
        }

        if (k == 1){
            for (int i = 0; i < n - k + 1; i++) std::cout << 0 << ' ';
            continue;
        }

        int s1 = 0, s2 = 0;
        std::multiset<int> half1, half2;
        vi temp;
        for (int i = 0; i < k; i++) temp.push_back(x[i]);
        std::sort(temp.begin(), temp.end());

        for (int i = 0; i < k / 2; i++){
            half1.insert(temp[i]);
            s1 += temp[i];
        }
        if (k & 1){
            half1.insert(temp[k / 2]); 
            s1 += temp[k / 2]; 
        }
        for (int i = (k & 1 ? k / 2 + 1 : k / 2); i < k; i++){
            half2.insert(temp[i]);
            s2 += temp[i];
        }

        for (int l = 0, r = k; r < n; l++, r++){
            std::cout << (s2 - (s1 - (k % 2 == 0 ? 0 : *half1.rbegin()))) << ' ';
            if (half1.find(x[l]) != half1.end()){
                s1 -= x[l];
                half1.erase(half1.find(x[l]));
                if (x[r] < *half2.begin()){
                    s1 += x[r];
                    half1.insert(x[r]);
                }
                else{
                    s1 += *half2.begin();
                    half1.insert(*half2.begin());
                    s2 -= *half2.begin();
                    half2.erase(half2.begin());
                    s2 += x[r];
                    half2.insert(x[r]);
                }
            }
            else{
                s2 -= x[l];
                half2.erase(half2.find(x[l]));
                if (x[r] >= *half1.rbegin()){
                    half2.insert(x[r]);
                    s2 += x[r];
                }
                else{
                    half2.insert(*half1.rbegin());
                    s2 += *half1.rbegin();
                    s1 -= *half1.rbegin();
                    half1.erase(half1.find(*half1.rbegin()));
                    s1 += x[r];
                    half1.insert(x[r]);
                }
            }
        } std::cout << (s2 - (s1 - (k % 2 == 0 ? 0 : *half1.rbegin()))) << ' ';
        
    }
    
    return 0;
    
}