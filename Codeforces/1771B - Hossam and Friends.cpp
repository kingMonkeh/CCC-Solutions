#include <bits/stdc++.h>

/*

view pair as segment of array with left, right
if you include left, you can include all people up until the right person, but not including the right person

go through friend 1 --> n

starting from friend a, you can extend the segment until the first right part of a segment
note that segments that have their left, behind a dont count, as the left is never included in the segment

*/

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){
        
        int n, m;
        std::cin >> n >> m;

        std::set<std::pair<int, int>> seg;
        for (int i = 0; i < m; i++){
            int x, y;
            std::cin >> x >> y;
            //insert(right, left)
            seg.insert({std::max(x, y), std::min(x, y)});
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++){
            auto right = seg.upper_bound({i, -1});
            //Remove segments that have left before i
            while (right != seg.end() && right->second < i){
                auto it = right;
                right++;
                seg.erase(it);
            }
            //bounded by a segment
            if (right != seg.end()){
                ans += right->first - i;
            }
            //not bounded
            else{
                ans += n - i + 1;
            }
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}