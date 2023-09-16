//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>

/*

Greedy idea: Its always optimal to close a bracket as soon as possible so long as it follows the rules of the intervals

By closing a bracket as soon as possible, you allow other brackets more time to begin and end

*/

int main(){

    int tests;
    std::cin >> tests;
    //tests = 1;
    while (tests--){

        int N, K;
        std::cin >> N >> K;
        std::stack<int> s;

        for (int i = 0; i < N; i++){
            int P;
            std::cin >> P;
            if (s.empty()){
                s.push(P);
            }
            else if (s.top() != P){
                s.push(P);
            }
            else s.pop();
        }

        std::cout << (s.empty() ? 1 : 0) << '\n';
        
    }
    
    return 0;
    
}