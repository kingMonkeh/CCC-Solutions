#include <cstdio>
#include <iostream>
#include <utility>

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    std::pair<int, int> buckets [3];
    std::cin >> buckets[0].first >> buckets[0].second >> buckets[1].first >> buckets[1].second >> buckets[2].first >> buckets[2].second;
    int cur1 = 0, cur2 = 1;
    for (int i = 0; i < 100; i++){
        if (buckets[cur2].second + buckets[cur1].second > buckets[cur2].first){
            int milkadded = buckets[cur2].first - buckets[cur2].second;
            buckets[cur2].second = buckets[cur2].first;
            buckets[cur1].second -= milkadded;
        }
        else{
            buckets[cur2].second += buckets[cur1].second;
            buckets[cur1].second = 0;
        }
        cur1++; cur2++;
        cur1 %= 3; cur2 %= 3;
    } 
    for (int i = 0; i < 3; i++) std::cout << buckets[i].second << '\n';
    return 0;
}