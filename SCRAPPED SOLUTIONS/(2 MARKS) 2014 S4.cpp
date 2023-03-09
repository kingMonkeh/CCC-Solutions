/*

2014 S4 - Tinted Glass Window

Brute force approach, generate a 2-D array representing the area, update tint values accordingly

Obviously very inefficient, can most likely be optimized.

*/
#include <iostream>
#include <map>
#include <utility>

int main(){
    
    long long N, T;
    std::cin >> N >> T;
    
    std::map<std::pair<int, int>, long long> window;
    
    for (int i = 0; i < N; i++){
        
        int x1, y1, x2, y2, t;
        
        std::cin >> x1 >> y1 >> x2 >> y2 >> t;
        
        for (int x = x1; x < x2; x++){
            
            for (int y = y1; y < y2; y++){
                
                window[std::make_pair(x, y)] += t;
                
            }
            
        }
        
    }
    
    int goodArea = 0;
    
    for (auto it = window.begin(); it != window.end(); it++){
        if (it->second >= T) goodArea++;
    }
    
    std::cout << goodArea;
    
    return 0;
    
}
