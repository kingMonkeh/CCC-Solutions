/*

General idea, Josh must have lexicographically largest array from left to right
since he can only add to the left and take away from the right

Nils must be the largest lexicographically from right to left
Since he can only add to the right and take from the left

The last guy remaining is mike 

*/

#include <iostream>
#include <vector>

int main(){
    int T;
    std::cin >> T;
    while (T--){
        int N;
        std::cin >> N;
        long long vaults [3][N];
        //for each room
        for (int j = 0; j < 3; j++){
            //for each vault
            for (int k = 0; k < N; k++){
                std::cin >> vaults[j][k];
            }
        }
        std::vector<int> remaining; //which banks remain
        std::string order [3]; //who robbed which bank
        //lexicographically largest is Josh
        long long room1 = 0, room2 = 0, room3 = 0;
        for (int i = 0; i < N; i++){
            room1 += vaults[0][i] - 100; //subtract 100 to avoid long long overflow
            room2 += vaults[1][i] - 100;
            room3 += vaults[2][i] - 100;
            if (room1 > room2 && room1 > room3){
                order[0] = "Josh"; remaining = {1, 2}; break;
            }
            else if (room2 > room1 && room2 > room3){
                order[1] = "Josh"; remaining = {0, 2}; break;
            }
            else if (room3 > room2 && room3 > room1){
                order[2] = "Josh"; remaining = {0, 1}; break;
            }
        }
        //lexicographically largest in reverse must be Nils
        //therefore remaining one is Mike
        long long rroom1 = 0, rroom2 = 0;
        for (int i = N - 1; i >= 0; i--){
            rroom1 += vaults[remaining[0]][i] - 100;
            rroom2 += vaults[remaining[1]][i] - 100;
            if (rroom1 > rroom2){
                order[remaining[0]] = "Nils"; order[remaining[1]] = "Mike"; break;
            }
            else if (rroom2 > rroom1){
                order[remaining[1]] = "Nils"; order[remaining[0]] = "Mike"; break;
            }
        }
        //Output answer
        for (int i = 0; i < 3; i++){
            std::cout << order[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}