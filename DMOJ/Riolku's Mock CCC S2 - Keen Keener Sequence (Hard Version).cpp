#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#define int long long
#define vi std::vector<int>
#define pii std::pair<int, int>
#define f first
#define s second
#define inf LONG_LONG_MAX / 2
#define ordered_set tree<std::pair<int, int>, null_type, std::less<std::pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int MOD = 1e9 + 7;

/*

Idea:

imagine 

index: 1 2 3 4 5
array: 1 1 2 2 4

lets count them assuming that all pairs are distinct (this is not the case however)
lets also say that order doesnt matter and that (i, j) (k, l) is the same as (k, l) (i, j)

if there are 6 pairs
then 1st pair can go with the 5 others
the second can match with 4 other
...
the second last can match with the last

using index:
(1, 3) and (1, 4) are counted, although we shouldnt have counted these
therefore we must subtract

to exclude these we count nCr (# repeat number, 2)
since 2 repeats twice, nCr(2, 2) is 1

for every number other than 2, it will have 1 quadruplet i j k l
that reuses the same initial, with these two 2's

*/

signed main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int n;
        std::cin >> n;

        int a [n];
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::sort(a, a + n);

        std::vector<int> p;

        int ans = 0;
        int total_bad_pairs = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                p.push_back(a[i] * a[j]);
                if (a[i] == a[j])
                    total_bad_pairs++;
            }
        }

        std::sort(p.begin(), p.end());

        int cnt = 0;
        for (int i = 0; i < p.size(); i++){
            if (i > 0 && p[i] != p[i - 1])
                cnt = 1;
            else
                cnt++;
            ans += cnt - 1;
        }

        for (int i = 0; i < n; i++){
            //bad pairs that include a[i] shouldnt be counted, since we're fixing a[i]
            //and counting the other 2 numbers that make bad
            int x = 0;
            for (int j = 0; j < n; j++){
                if (i != j && a[i] == a[j])
                    x++;
            }
            ans -= total_bad_pairs - x;
        }

        std::cout << ans * 8 << '\n';

    }

    return 0;

}
