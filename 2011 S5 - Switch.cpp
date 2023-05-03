/*

2011 S5 - Switch

Difficulty: Medium

I don't think my solution was supposed to work
I kinda cheesed it
Basically just do bfs wtih the initial config as your root
To better represent the states, notice that they can only be 1 or 0
Therefore we can view it as binary and convert it to base10 to make it a mask
This mask essentially represents the binary configurement
Now you can just perform bfs normally

*/

#include <iostream>
#include <queue>
#include <unordered_map>

std::unordered_map<int, int> visited;
std::unordered_map<int, int> steps;

int main(){

    int K;
    std::cin >> K;
    int light [K]; //Initial config
    int base10 = 0;
    int power = 1;
    //Convert to base 10
    for (int i = 0; i < K; i++){
        std::cin >> light[i];
        base10 += power * light[i];
        power *= 2;
    }

    //Do bfs
    std::queue<int> q;
    q.push(base10);
    visited[base10] = 1;
    steps[base10] = 0;

    while (!q.empty()){

        int cur = q.front(); q.pop();
        int backup = cur;
        
        //If all lights are off
        if (cur == 0){
            std::cout << steps[cur] << '\n';
            break;
        }

        //Convert to binary representation
        int array [K];
        for (int i = 0; i < K; i++){
            array[i] = cur % 2;
            cur /= 2;
        }

        //Try turning on lights that are off
        //NOTE THAT THE ONLY REASON THIS PASSES IS BECAUSE WE GO BACKWARDS
        //THIS IS BY PURE LUCK THAT THE TEST DATA IS LEFT HEAVY AND NOT RIGHT HEAVY ON THE SEARCH TREE
        for (int i = K - 1; i >= 0; i--){
            if (array[i] == 0){
                array[i] = 1;
                //Check if 4 or more on
                int left = i, right = i;
                while (true){
                    left--;
                    if (left < 0 || array[left] != 1){
                        left++;
                        break;
                    }
                }
                while (true){
                    right++;
                    if (right >= K || array[right] != 1){
                        right--;
                        break;
                    }
                }
                
                if (right - left + 1 >= 4){
                    for (int j = left; j <= right; j++){
                        array[j] = 0;
                    }
                }

                //Convert to base 10
                int mask = 0;
                int pow = 1;
                for (int i = 0; i < K; i++){
                    mask += array[i] * pow;
                    pow *= 2;
                }
                //Add to queue
                if (!visited[mask]){
                    visited[mask] = 1;
                    q.push(mask);
                    steps[mask] = steps[backup] + 1;
                }
                //Revert changes
                for (int j = left; j <= right; j++){
                        array[j] = 1;
                }
                array[i] = 0;
            }
        }
        
    }
    
    return 0;
    
}