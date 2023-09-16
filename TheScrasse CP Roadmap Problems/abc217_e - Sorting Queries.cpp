//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>

int main(){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        int Q;
        std::cin >> Q;

        std::deque<int> q;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        while (Q--){
            int type;
            std::cin >> type;
            if (type == 1){
                int x;
                std::cin >> x;
                q.push_back(x);
            }
            else if (type == 2){
                //notice that after we sort an array, even if we append stuff after it
                //the first numbers to go out will still be the sorted array, and then it continues with the original queue
                if (!pq.empty()){
                    std::cout << pq.top() << '\n';
                    pq.pop();
                }
                else{
                    std::cout << q.front() << '\n';
                    q.pop_front();
                }
            }
            else{
                //although it may seem inefficient, you can just transfer it over
                int s = q.size();
                while (s--){
                    pq.push(q.front());
                    q.pop_front();
                }
            }
        }
        
    }
    
    return 0;
    
}