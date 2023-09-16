#include <bits/stdc++.h>

int main (){

    int n;
    std::cin >> n;

    std::map<int, int> found;
    for (int i = 0; i < n - 1; i++){
        int num;
        std::cin >> num;
        found[num] = true;
    }

    for (int i = 1; i <= n; i++){
        if (!found[i]){
            std::cout << i;
            break;
        }
    }
    
    return 0;
    
}