#include <bits/stdc++.h>

int main (){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> segments (n);
        for (int i = 0; i < n; i++){
            int l, r;
            std::cin >> l >> r;
            segments[i] = std::make_pair(l, r);
        }
        //Create pairs of pairs only if they intersect
        //As we combine pairs, we basically create a larger overall segment
        std::vector<std::pair<int, int>> unions; 
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (std::max(segments[i].first, segments[j].first) <= std::min(segments[i].second, segments[j].second)){
                    unions.push_back(std::make_pair(std::min(segments[i].first, segments[j].first), std::max(segments[i].second, segments[j].second)));
                }
            }
        }
        //Sort only by increasing right border
        std::sort(unions.begin(), unions.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){return a.second < b.second;});
        //Greedy choose the first ones available, idea is that by sorting by right border, if we choose the one that takes the least right border, then we give more room for more unions that we can fit
        int pairpairs = 0, right = -1;
        for (auto u: unions){
            if (u.first > right){
                pairpairs++;
                right = u.second;
            }
        }
        //Remember we counted the pairs of pairs that we used, therefore to get the actual number of pairs used, we * 2
        std::cout << n - pairpairs * 2 << '\n';
    }
    return 0;
}