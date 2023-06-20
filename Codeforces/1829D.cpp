#include <iostream>
#include <algorithm>
#include <string>

int n, m;
bool solve(int size){
    if (size == m){
        return true;
    }
    if (size % 3 != 0){
        return false;
    }
    else{
        int x = size / 3;
        int y = 2 * x;
        return (solve(x) | solve(y));
    }
}

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::cin >> n >> m;
        if (solve(n)){
            std::cout << "Yes\n";
        }
        else{
            std::cout << "No\n";
        }
    }
    return 0;
}