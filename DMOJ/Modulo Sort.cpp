#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

std::map<int, std::vector<int>> mod; //mod[remainder] --> std::vector<int> containing all numbers where number % K == remainder

//just like uh implement it
int main(){
    int N, K;
    std::cin >> N >> K;
    for (int i = 0; i < N; i++){
        int num;
        std::cin >> num;
        int remainder = num % K;
        mod[remainder].push_back(num);
    }
    for (auto& remainder: mod){
        if (remainder.second.size() > 1){
            std::sort(remainder.second.begin(), remainder.second.end());
        }
        for (int& i: remainder.second){
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}