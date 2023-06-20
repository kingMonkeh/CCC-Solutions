#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::map<int, int> occ;

int main (){
    int N;
    std::cin >> N;
    std::set<int> wheats;
    int distinct = 0;
    for (int i = 0; i < N; i++){
        int wheat;
        std::cin >> wheat;
        wheats.insert(wheat);
        occ[wheat]++;
        if (occ[wheat] == 1){
            distinct++;
        }
    }
    //Simulate the game
    //Mirko will always take from the front
    //Slavko will always take from the back
    //You can essentially just completely remove one number at a time
    //Increment the next by however much you decreased
    //And perform the same for the other side
    auto front = wheats.begin();
    auto back = wheats.end(); back--;
    std::string winner = "";
    while (distinct >= 3){
        if (occ[*front] > occ[*back]){
            int carryover = occ[*back];
            back--;
            distinct--;
            if (distinct < 3){
                winner = "Slavko";
            }
            occ[*back] += carryover;
            occ[*front] -= carryover;
            front++;
            occ[*front] += carryover;
            front--;
        }
        else if (occ[*front] < occ[*back]){
            int carryover = occ[*front];
            front++;
            distinct--;
            if (distinct < 3){
                winner = "Mirko";
            }
            occ[*front] += carryover;
            occ[*back] -= carryover;
            back--;
            occ[*back] += carryover;
            back++;
        }
        else{
            int carryover = occ[*back];
            back--; front++;
            distinct -= 2;
            if (distinct < 3){
                winner = "Slavko";
            }
            occ[*back] += carryover;
            occ[*front] += carryover;
        }
    }
    if (winner == ""){
        std::cout << "Slavko\n";
    }
    else{
        std::cout << winner << '\n';
    }
    std::cout << *front << ' ' << *back << '\n';
    return 0;
}