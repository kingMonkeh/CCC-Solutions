#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

int main(){
    int N; char owner;
    std::cin >> owner >> N;
    std::set<char> owners = {owner};
    for (int i = 0; i < N; i++){
        char Z1, Z2;
        std::cin >> Z1 >> Z2;
        if (owner == Z2) owner = Z1;
        owners.insert(owner);
    }
    std::cout << owner << '\n' << owners.size();
    return 0;
}