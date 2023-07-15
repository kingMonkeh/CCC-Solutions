#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct segment{
    int l, r;
};

bool operator <(const segment& a, const segment& b){
    return a.l < b.l;
}

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        
        //GET INPUT//
        int n; long long m;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }
        std::cin >> m;
        //INPUT END//

        /*
        We will be moving from bottom up, counting all the white cell segments that are divided by black cell pillars
        */
        
        //MAIN//
        std::vector<int> order (n);
        for (int i = 0; i < n; i++) order[i] = i;
        //Imagine we assign each black cell pillar in a, an index
        //In order, we will then sort these indices by decreasing height based on the height of each black cell pillar in a
        //If a = {1, 4, 3, 2}, then order = {1, 2, 3, 0} since a[1] > a[2] > a[3] > a[0]
        std::sort(order.begin(), order.end(), [&a](int x, int y) {
            return a[x] > a[y];
        });
        //We will keep track of how many segments of each there are
        std::vector<long long> count (n + 1, 0); //count[i] = # of segments with size i
        //Current_segments will keep track of what segments are currently alive
        //current_segments[segment] = height of this segment, note the height convention below
        std::map<segment, int> current_segments;
        current_segments[{0, n}] = n; //We initially start with a segment the n wide, that starts at height n
        //We will now start at the bottom which we consider as height n, at the top of the matrix is height 0
        for (int i = n, j = 0; i >= 0; i--){
            //As we go up, we're going to encounter the biggest pillars first, hence why why we sorted them big -> small
            //This condition is true so long as we're colliding with a pillar
            while (j < n && a[order[j]] >= i){
                //This obtains the segment after the first segment that has a[order[j]] as its left
                auto it = current_segments.upper_bound({order[j], -1});
                it--; //We went past one segment, therefore we go back one
                auto seg = it->first; //Obtain the segment itself
                //Count[segment length] += segment height - current height
                count[seg.r - seg.l] += it->second - i;
                current_segments.erase(it); //Erase this segment since it has now been split by a black cell
                //Add the new segments that have been created by the split
                //If the pillar is not the left of the current segment, we can continue further down on the left side
                if (seg.l != order[j]){
                    current_segments[{seg.l, order[j]}] = i;
                }
                //If the black cell pillar is not the right of the current segment, we can go further down on the right side
                if (seg.r != order[j] + 1){
                    current_segments[{order[j] + 1, seg.r}] = i;
                }
                j++; //We've finished processing this pillar, go to the next
            }
        }

        //CALCULATING ANSWER//
        //Using the segment chunks, we realize we want to put the m numbers continously (j and j + 1 rule)
        //Not only that we want to do this in the biggest segments first 
        //Imagine we have m = 3, we can either do {1, 2, 3} or {1, 2} and {3, _} 
        //Notice that we get more value by putting in the bigger chunks first
        long long beauty = 0;
        for (int i = n; i > 0; i--){
            long long segs = std::min(count[i], m / i); //There are chunks of size i, how many chunks can we actually make with m though? (m / i)
            beauty += segs * 1LL * (i - 1); //Segments of length i when filled, yield i - 1 beauty
            m -= segs * 1LL * i; //Update m
            //If we weren't able to fill up all the segments using m and we still have some m leftover
            if (segs != count[i] && m > 0){
                beauty += m - 1; //Use the remaining m
                m = 0;
            }
        }
        //Output answer
        std::cout << beauty << '\n';
    }
    return 0;
}