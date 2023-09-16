#include <bits/stdc++.h>

/*

Break string into segments of 0...1...

Reasons for this is because they're already sorted
If the l and r of a query are in the same segment, nothing changes, therefore we have to original string
We want to count this only once

Otherwise
We notice that from each segment, regardless of what 0 you start in that segment
The resulting string will always be the same, since all the 0's will be stacked together

Therefore we can set the l value to the far left value of the segment
Edge case: We notice that if we're on the first 1 of a segment, it's also equivalent to a 0, since when we sort it, it will append 0's as well to our original group of 0's

We notice that if our l is on a 1 however, that each 1 excluding the first, will create a unique string seperated by the previous wall of 1's

We also notice that if our r is on a 1, it doesn't matter the position of r in that segment
Since there will be the same number of 0's before it, and after sorting, it will still have the group of 1's following

*/

struct seg{
    int l, r, last_zero;
};

int main() {
	std::ios::sync_with_stdio(false);
    int tests;
    std::cin >> tests;
	while (tests--) {
		int n, m;
        std::cin >> n >> m;
        std::string s;
        std::cin >> s;
        std::vector<seg> segs;
        std::vector<int> block (n);
        int i = 0;
        int cur_seg = 0;
        if (s[0] == '1'){
            seg cur;
            cur.l = 0, cur.last_zero = -1;
            for (; i < n; i++){
                if (s[i] != '1'){
                    cur.r = i - 1;
                    break;
                }
                block[i] = cur_seg;
            }
            segs.push_back(cur);
            cur_seg++;
            //std::cout << cur.l << ' ' << cur.r << ' ' << cur.last_zero << '\n';
        }
        while(i < n){
            seg cur;
            cur.l = i;
            bool one = false;
            for (; i < n; i++){
                if (s[i] == '1' && !one){
                    one = true;
                    cur.last_zero = i - 1;
                }
                else if (s[i] == '0' && one){
                    cur.r = i - 1;
                    break;
                }
                block[i] = cur_seg;
            }
            if (!one){
                cur.last_zero = i - 1;
                cur.r = i - 1;
            }
            segs.push_back(cur);
            cur_seg++;
            //std::cout << cur.l << ' ' << cur.r << ' ' << cur.last_zero << '\n';
        }
        //for (int i = 0; i < n; i++) std::cout << block[i] << ' '; std::cout << '\n';
        std::map<std::pair<int ,int>, int> cross_seg;
        int ans = 0;
        bool orig = false;
        while (m--){
            int l, r;
            std::cin >> l >> r;
            l--; r--;
            if (block[l] == block[r]){
                if (!orig){
                    ans++;
                    orig = true;
                }
            }
            else{
                if (s[l] == '0' || segs[block[l]].last_zero + 1 == l){
                    l = segs[block[l]].l;
                }
                if (s[r] == '1'){
                    r = segs[block[r]].last_zero;
                }
                if (!cross_seg[std::make_pair(l, r)]){
                    ans++;
                }
                cross_seg[std::make_pair(l, r)] = 1;
            }
        }
        std::cout << ans << '\n';
	}
	return 0;
}