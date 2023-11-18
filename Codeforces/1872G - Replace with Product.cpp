#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

/*

greedy intuition, once the product gets big enough
it intuitively makes sense to just choose the first number > 1 and last number > 1
and make them your l and r

if the product isnt that big however, you can just try every combination
since if the numbers were minimized to be 2's

it would take only 60 2's before the product is 2^60 which is very large
therefore worst case to brute force each one

it would take 60^2 which isnt that bad

*/

const int MOD = 1e9 + 7;

signed main (){
 
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){
    
        int n;
        std::cin >> n;

        int limit = 2 * n;
        
        vi a (n);
        vi pref (n + 1); pref[0] = 0;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }

        int product = 1;
        for (int i = 0; i < n; i++){
            product *= a[i];
            if (product > limit) break;
        }

        int l, r;

        if (product == 1){
            std::cout << 1 << ' ' << 1 << '\n';
            continue;
        }

        //product is very big
        if (product > limit){
            l = 1, r = n;
            while (a[l - 1] == 1){
                l++;
            }
    
            while (a[r - 1] == 1){
                r--;
            }
            
            std::cout << l << ' ' << r << '\n';
        }

        else{

            //brute force

            //mark index of all a[i] such that a[i] > 1
            vi ind;
            for (int i = 0; i < n; i++){
                if (a[i] > 1) ind.push_back(i);
            }

            int mx = 0;
            for (int i = 0; i < ind.size(); i++){
                int p = 1;
                int s = 0;
                for (int j = i; j < ind.size(); j++){
                    int ll = ind[i], rr = ind[j];
                    p *= a[rr];
                    //use psa to calculate sums on left and right
                    if (pref[ll] + p + pref[n] - pref[rr + 1] > mx){
                        mx = pref[ll] + p + pref[n] - pref[rr + 1];
                        l = ll + 1;
                        r = rr + 1;
                    }
                }
            }

            std::cout << l << ' ' << r << '\n';
            
        }
        
    }
    
    return 0;
    
}