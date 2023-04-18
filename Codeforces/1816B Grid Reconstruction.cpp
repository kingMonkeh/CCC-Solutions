#include <iostream>

int main(){

    int t;
    std::cin >> t;

    while (t--){

        int n;
        std::cin >> n;

        int max = 2 * n, min = 2;
        for (int i = 0; i < n; i++){
            if (!(i % 2)){
                std::cout << max << ' ';
                max -= 2;
            }

            else{
                std::cout << min << ' ';
                min += 2;
            }
        }

        std::cout << '\n';

        max = 2 * n - 3, min = 1;
        for (int i = 0; i < n - 1; i++){
            if (i % 2){
                std::cout << max << ' ';
                max -= 2;
            }

            else{
                std::cout << min << ' ';
                min += 2;
            }
        }

        std::cout << 2 * n - 1 << '\n';

    }

    return 0;

}