#include <bits/stdc++.h>
 
int main(){
 
    int tests;
    std::cin >> tests;
    while (tests--){
 
        int a, b;
        std::cin >> a >> b;
 
        if (a > 1 && b > 1){
            std::cout << 1 << '\n';
        }
 
        else if (a == 1 && b == 2){
            std::cout << 3 << '\n';
        }
 
        else{
            std::cout << 2 << '\n';
        }
        
    }
 
    return 0;
    
}