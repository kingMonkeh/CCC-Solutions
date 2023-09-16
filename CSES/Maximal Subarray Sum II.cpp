#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

signed main (){

    int n, a, b;
    std::cin >> n >> a >> b;

    vi x (n + 1), pref (n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++){
        std::cin >> x[i];
        pref[i] = pref[i - 1] + x[i];
    }

    //we do sliding window of size b
    //lets say that element i is the last element of the current subarray we're looking at
    //there would be (b - a + 1) different sized subarrays we can find within the bigger window
    //we can quickly determine the best one to choose by picking the smallest prefix sum
    //since we can view the window as the p[i] - p[j] for some beginning element j
    //since we've fixed p[i], we must minimize p[j] to maximize our sum
    int ans = -LONG_LONG_MAX;
    std::multiset<int> ms;
    for (int i = a; i <= n; i++){
        //once our window becomes bigger than b, we need to get rid of the front element as its no longer a possible prefix candidate
        if (i > b){
            //do not delete dupes
            ms.erase(ms.find(pref[i - b - 1])); //remember we want to keep the front part, meaning we have remove the prefix right before it, hence - 1
        }
        ms.insert(pref[i - a]);
        ans = std::max(ans, pref[i] - *ms.begin());
    }

    std::cout << ans << '\n';
        
    return 0;
    
}