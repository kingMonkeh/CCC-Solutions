#include <bits/stdc++.h>
 
/*

Key observation

you can only combine even index with even index

and odd index with odd index

pick which is better

edge case:
all negative
ans = max(particle in particles)

*/

int main (){
 
    int tests;
    std::cin >> tests;
    while (tests--){
 
        int n;
        std::cin >> n;
 
        std::vector<int> particles (n);
        
        bool all_negative = true;
        for (int i = 0; i < n; i++){
            std::cin >> particles[i];
            if (particles[i] >= 0){
                all_negative = false;
            }
        }
 
        if (all_negative){
            std::cout << *std::max_element(particles.begin(), particles.end()) << '\n';
        }
 
        else{
            long long odd_sum = 0, even_sum {0};
            for (int i = 0; i < n; i++){
                if (i % 2 == 0){
                    odd_sum += std::max(particles[i], 0); // we dont want to add negative particles so we can just erase them
                }
                else{
                    even_sum += std::max(particles[i], 0);
                }
            }
            std::cout << std::max(odd_sum, even_sum) << '\n';
        }
        
    }
    
    return 0;
    
}