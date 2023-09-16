#include <bits/stdc++.h>

int main (){

    std::string DNA;
    std::cin >> DNA;

    int s = DNA.size(), sz = 0, ans = 0;
    char cur = DNA[0];
    for (int i = 0; i < s; i++){
        if (DNA[i] == cur) sz++;
        else{
            ans = std::max(ans, sz);
            cur = DNA[i];
            sz = 1;
        }
    } ans = std::max(ans, sz);

    std::cout << ans;
    
    return 0;
    
}