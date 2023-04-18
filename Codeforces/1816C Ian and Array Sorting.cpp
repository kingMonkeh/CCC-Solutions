#include <iostream>
#include <array>

int main(){

    int t;
    std::cin >> t;

    while (t--){

        int n;
        std::cin >> n;

        long long arr [n];

        for (int i = 0; i < n; i++){
            std::cin >> arr[i];
        }

        if (n % 2 == 1){
            std::cout << "YES" << '\n';
        }

        else{
            
            for (int i = 0; i < n - 3; i++){
                long long diff = arr[i] - arr[i + 1];
                arr[i + 1] += diff;
                arr[i + 2] += diff; 
            }

            if (arr[n - 2] <= arr[n - 1]){
                std::cout << "YES" << '\n';
            }

            else{
                std::cout << "NO" << '\n';
            }

        }

    }

    return 0;

}