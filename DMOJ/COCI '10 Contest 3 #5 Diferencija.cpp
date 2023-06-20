/*
(4) 2 1 3 4 (1)
(3) 2 1 3   (1)
(4)   1 3 4 (1)
(2) 2 1     (1)
(3)   1 3   (1)
(4)     3 4 (3)
(2) 2       (2)
(1)   1     (1)
(3)     3   (3)
(4)       4 (4)
*/

#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;
    int seq [N + 1];
    for (int i = 1; i <= N; i++){
        std::cin >> seq[i];
    }
    //Calculate all max
    long long total_max = 0;
    long long cur_max = 0;
    seq[0] = 2147000000;
    std::deque<int> deq = {0};
    for (int i = 1; i <= N; i++){
        while (seq[deq.back()] <= seq[i]){
            int back = deq.back();
            deq.pop_back();
            int backback = deq.back();
            //Subtracting because there exists no more subsequences in which this specific element is the maximum
            //Therefore we remove it from cur_max by making use of the fact that we saved the original subsequences that we counted of it
            cur_max -= (long long) (back - backback) * seq[back];
        }
        //Basically, element * (cur_index - first element which is greater than current)
        //This indicates the number of subsequences before it that contain it as max
        //To count the subsequences after, notice that we only subtract if the next element is even bigger than the curr
        //SEQ = 1, 2, 3, 1
        //when i = 3
        //cur_max += 3 * (3 - 0) = 9
        //This represents the subsequences:
        //1 2 3
        //  2 3
        //    3
        //When i = 4
        //we add 1 * (4 - 3) = 1
        //This represents the subsequence 1
        //Notice that 3 can still be the max element of subsequnces including this 1 as well
        //Which is why we haven't subtracted it, instead we added another 9
        //This 9 represents the subsequences:
        //1 2 3 1
        //  2 3 1
        //    3 1
        cur_max += (long long) (i - deq.back()) * seq[i];
        total_max += cur_max;
        deq.push_back(i);
    }
    //Calculate all min
    //Exact same logic as the max version, but we just check if the prev element is larger or not
    long long total_min = 0;
    long long cur_min = 0;
    seq[0] = -2147000000;
    deq.clear(); deq.push_back(0);
    for (int i = 1; i <= N; i++){
        while (seq[deq.back()] > seq[i]){
            int back = deq.back();
            deq.pop_back();
            int backback = deq.back();
            cur_min -= (long long) (back - backback) * seq[back];
        }
        cur_min += (long long) (i - deq.back()) * seq[i];
        total_min += cur_min;
        deq.push_back(i);
    }
    std::cout << total_max - total_min << '\n';
    return 0;
}