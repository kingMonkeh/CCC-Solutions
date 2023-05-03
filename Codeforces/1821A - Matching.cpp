#include <iostream>
#include <string>
 
int main(){
 
    int t;
    std::cin >> t;
 
    while (t--){
        std::string s;
        std::cin >> s;
        int possibilities = 1;
        
        if (s[0] == '0'){
            std::cout << 0 << '\n';
            continue;
        }
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '?'){
                if (i == 0){
                    possibilities *= 9;
                }
                else{
                    possibilities *= 10;
                }
            }
        }
        std::cout << possibilities << '\n';
    }
    
    return 0;
    
}