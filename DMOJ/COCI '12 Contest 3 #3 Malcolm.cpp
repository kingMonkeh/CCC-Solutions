/*

Keep like a sliding window containing frequency of each name length for the previous K people
This makes updates occur in O(1) time

*/

#include <iostream>
#include <string>
#include <string.h>

int main(){
    long long N, K;
    std::cin >> N >> K;
    std::string ranking [N];
    long long frequency [21];
    memset(frequency, 0, sizeof(frequency));
    long long goodFriends = 0;
    for (int i = 0; i < N; i++){
        std::cin >> ranking[i];
        goodFriends += frequency[ranking[i].length()];
        frequency[ranking[i].length()]++;
        if (i >= K){
            frequency[ranking[i - K].length()]--;
        }
    }
    std::cout << goodFriends << '\n';
    return 0;
}