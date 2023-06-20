#include <iostream>
#include <algorithm>
#include <string>

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        int skill1 = 999999999, skill2 = 999999999, combined = 999999999;
        for (int i = 0; i < n; i++){
            int time;
            std::string book;
            std::cin >> time >> book;
            if (book[0] == '1' && book[1] == '1'){
                combined = std::min(combined, time);
                continue;
            }
            if (book[0] == '1'){
                skill1 = std::min(skill1, time);
            }
            if (book[1] == '1'){
                skill2 = std::min(skill2, time);
            }
        }
        if ((skill1 == 999999999 || skill2 == 999999999) && combined == 999999999){
            std::cout << -1 << '\n';
            continue;
        }
        std::cout << std::min(skill1 + skill2, combined) << '\n';
    }
    return 0;
}