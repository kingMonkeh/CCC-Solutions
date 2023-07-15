#include <bits/stdc++.h>

/*
Basic idea:
Notice that if you want the mex of something to be x
You must include all values less than x in your segment
We basically check how many segments of each mex there are and add them to our answer
maintain a segment with left and right denoting the minimum size segment that contains all numbers less than the desired mex within both p and q

Afterwards, see how far you can stretch this segment in each direction, without including mex in the set
As that would change the mex of the total set

This works for all mex > 1
For mex == 1, notice that you just want to count the total number of segments that don't include 1
3 cases
far left of 1
far right of 1
in between the 1's

*/

int main(){
    int n;
    std::cin >> n;
    std::map<int, int> i_in_p, i_in_q; //maintain index of each number in each permutation
    int p [n], q [n];
    for (int i = 0; i < n; i++){
        std::cin >> p[i];
        i_in_p[p[i]] = i + 1;
    }
    for (int i = 0; i < n; i++){
        std::cin >> q[i];
        i_in_q[q[i]] = i + 1;
    }
    //SOLUTION START//
    long long ans = 0;
    //CALCULATE MEX = 1, n * (n + 1) / 2
    ans += 1LL * (std::min(i_in_p[1], i_in_q[1]) - 1) * std::min(i_in_p[1], i_in_q[1]) / 2;
    ans += 1LL * (n - std::max(i_in_p[1], i_in_q[1])) * (n - std::max(i_in_p[1], i_in_q[1]) + 1) / 2;
    ans += 1LL * (std::max(i_in_p[1], i_in_q[1]) - std::min(i_in_p[1], i_in_q[1]) - 1) * (std::max(i_in_p[1], i_in_q[1]) - std::min(i_in_p[1], i_in_q[1])) / 2;
    //Segment, mex > 1
    int l = std::min(i_in_p[1], i_in_q[1]), r = std::max(i_in_p[1], i_in_q[1]);
    for (int i = 2; i <= n; i++){
        //mex is trapped in the segment, no possibilities
        if (i_in_p[i] >= l && i_in_p[i] <= r){
            l = std::min(l, std::min(i_in_p[i], i_in_q[i])), r = std::max(r, std::max(i_in_p[i], i_in_q[i]));
            continue;   
        }
        else if (i_in_q[i] >= l && i_in_q[i] <= r){
            l = std::min(l, std::min(i_in_p[i], i_in_q[i])), r = std::max(r, std::max(i_in_p[i], i_in_q[i]));
            continue;
        }
        //if segment is in between min(pos i) and max (pos i)
        else if (l > std::min(i_in_p[i], i_in_q[i]) && r < std::max(i_in_p[i], i_in_q[i])){
            ans += 1LL * (l - std::min(i_in_p[i], i_in_q[i])) * (std::max(i_in_p[i], i_in_q[i]) - r);
        }
        //if segment is far right
        else if (l > std::max(i_in_p[i], i_in_q[i])){
            ans += 1LL * (l - std::max(i_in_p[i], i_in_q[i])) * (n - r + 1);
        }
        //if segment is far left
        else{
            ans += 1LL * l * (std::min(i_in_p[i], i_in_q[i]) - r);
        }
        //Update borders, aka include this mex now
        l = std::min(l, std::min(i_in_p[i], i_in_q[i])), r = std::max(r, std::max(i_in_p[i], i_in_q[i]));
    }
    //SOLUTION END//
    std::cout << ++ans << '\n'; //++ans, since final segment is the segment [1, n], which has mex > n
    return 0;
}