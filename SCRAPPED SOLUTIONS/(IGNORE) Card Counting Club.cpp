/*

UAPC 2023 - Card Counting Club

Ignore this solution for now, I can't even test if it works because Kattis is such a trash judge

*/

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

int main(){

    int N, M, P;
    std::cin >> N >> M >> P;

    std::map<std::string, std::multiset<int>> hands;

    for (int i = 0; i < N; i++){

        std::string player;
        std::cin >> player;
        hands[player];

        for (int j = 0; j < M; j++){
            int card; std::cin >> card;
            hands[player].insert(card);
        }

    }

    std::vector<std::string> playersOut;
    int playersLeft = N;
    while (playersLeft > 1){

        int min = 2147483647;
        for (auto it = hands.begin(); it != hands.end(); it++){
            min = std::min(min, *it->second.begin());
        }

        std::string persontoIgnore;
        for (auto it = hands.begin(); it != hands.end(); it++){

            if (*it->second.begin() == min){

                it->second.erase(*it->second.begin());
                persontoIgnore = it->first;

                if (it->second.size() == 0){
                    playersLeft--;
                    playersOut.push_back(it->first);
                    hands.erase(it->first);
                }

                break;

            }

        }

        for (auto it = hands.begin(); it != hands.end(); it++){

            if (it->first != persontoIgnore){

                int lowestcard = *it->second.begin();
                it->second.erase(it->second.find(lowestcard));
                it->second.insert(lowestcard + P);
                
            }

        }

        /*
        for (auto it = hands.begin(); it != hands.end(); it++){

            std::cout << it->first << ' ';
            for (int card: it->second) std::cout << card << ' ';
            std::cout << '\n';

        }
        
        std::cout << '\n';
        */

    }

    for (std::string person: playersOut){
        std::cout << person << ' ';
    }

    std::cout << hands.begin()->first;

}