#include <iostream>
#include <algorithm>

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        int a [n];
        int length = 0;
        int prev = -1, counter = 0;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            if (prev != 0 && a[i] == 0){
                counter = 1;
                length = std::max(length, counter);
            }
            else if (a[i] == 1){
                if (prev == 0){
                    length = std::max(length, counter);
                }
            }
            else{
                counter++;
            }
            prev = a[i];
        }
        length = std::max(length, counter);
        std::cout << length << '\n';
    }
    return 0;
}