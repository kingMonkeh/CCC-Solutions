#include <iostream>

int main(){
    int N;
    std::cin >> N;
    if (N <= 1){
        std::cout << "not\n";
        return 0;
    } 
    bool prime = true;
    for (int i = 2; i < N; i++){
        if (N % i == 0){
            prime = false;
            break;
        }
    }
    if (prime){
        std::cout << "prime\n";
    }
    else{
        std::cout << "not\n";
    }
    return 0;
}