#include <iostream>
 
int main(){
 
    int t;
    std::cin >> t;
 
    while (t--){
        
        int n;
        std::cin >> n;
        int array1 [n];
        int array2 [n];
        for (int i = 0; i < n; i++){
            std::cin >> array1[i];
        }
        for (int i = 0; i < n; i++){
            std::cin >> array2[i];
        }
 
        int l, r, length = 1;
 
        int index, min, max;
        for (int i = 0; i < n; i++){
            if (array1[i] != array2[i]){
                l = i;
                min = array2[i];
                index = i;
            }
        }
        for (int i = n - 1; i >= index; i--){
            if (array1[i] != array2[i]){
                r = i;
                max = array2[i];
                index = i + 1;
            }
        }
 
        bool update = true;
        while (update){
            update = false;
            if (l > 0 && array2[l - 1] <= min){
                update = true;
                l--;
                min = array2[l];
            }
            if (r < n - 1 && array2[r + 1] >= max){
                update = true;
                r++;
                max = array2[r];
            }
        }
        
        std::cout << l + 1 << ' ' << r + 1 << '\n';
        
    }
    
    return 0;
    
}