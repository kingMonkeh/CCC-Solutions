#include <bits/stdc++.h>

int main(){
    
    std::ios_base::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while (tests--) {

        int n; char d;
        std::string num;
        std::cin >> n >> d >> num;

        bool used = false;
        for (int i = 0; i < n; i++){
            if (d > num[i] && !used){
                std::cout << d; used = true;
            }
            std::cout << num[i];
        } 
        if (!used) std::cout << d;
        std::cout << '\n';
        
    }

    return 0;
    
}