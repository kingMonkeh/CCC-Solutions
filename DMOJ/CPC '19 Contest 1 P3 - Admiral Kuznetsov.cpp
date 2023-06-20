/*

Basically 1-D DP array

Let DP[i] tell us amount of time to make the first i slots match

Simple cases, if init[i] == final[i]
No need to do anything, DP[i] = DP[i - 1]

if init[i] == '0' && final[i] == '1'
DP[i] = DP[i - 1] + 1
since all you have to do is call the 3rd order

Otherwise, things get tricky
imagine the case
001
110
If init[i] == '1' and final[i] == '0'
We realize that we must fill up the previous slots to be able to call the 1st or 2nd order
Therefore we count how many open slots we need to fill out (let's call it x)
Then after we clear, everything will be 0, but some of the slots we just cleared out should actually be 1's
So we have to call 3 again to put them back correctly
Therefore we count the number of ending ships we should have (lets call it y)
DP[i] = min(DP[i], DP[i - 3] + 1 + x + y)
Note that we need the extra 1, since calling the clear itself, takes 1 unit of time

We can then apply the same logic to a range of 4 ships to obtain
DP[i] = min(DP[i], DP[i - 4] + 1 + x + y)
where x and y also consider a 4th previous ship

Special problems we need to deal with
What if i < 3
That is, we still need to flip it, but we can't go back 3 ships without going out of bounds
In this case
We will just deal with this by going rightwards, and pretending that to the right is all zeros
Meaning we need to fill those slots up as well, causing x to go up by (size of group - i)

then we just apply the same algorithm

*/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> DP (9999999, 1000001);

int toInt(char x){
    return x - '0';
}

int main(){
    int N;
    std::cin >> N;
    std::string init, final;
    std::cin >> init >> final;
    init = ' ' + init; //1 indexing
    final = ' ' + final;
    DP[0] = 0;
    bool plane = false;
    int origEmpty = 0, finalPlanes = 0;
    //First 3, special case as they can smaller than group
    for (int i = 1; i <= 3; i++){
        if (init[i] == final[i]){
            DP[i] = DP[i - 1];
        }
        else if (init[i] == '0' && final[i] == '1'){
            DP[i] = DP[i - 1] + 1;
        }
        else{
            plane = true;
        }
        origEmpty += init[i] == '0';
        finalPlanes += final[i] == '1';
        if (plane){
            DP[i] = std::min(DP[i], DP[0] + (origEmpty + 3 - i) + 1 + finalPlanes);
        }
    }
    //Handle the rest normally
    for (int i = 4; i <= N; i++){
        if (init[i] == final[i]){
            DP[i] = DP[i - 1];
        }
        else if (init[i] == '0' && final[i] == '1'){
            DP[i] = DP[i - 1] + 1;
        }
        else{
            DP[i] = std::min(DP[i], DP[i - 3] + 1 + (3 - toInt(init[i - 2]) - toInt(init[i - 1]) - toInt(init[i])) + toInt(final[i - 2]) + toInt(final[i - 1]) + toInt(final[i]));
            DP[i] = std::min(DP[i], DP[i - 4] + 1 + (4 - toInt(init[i - 3]) - toInt(init[i - 2]) - toInt(init[i - 1]) - toInt(init[i])) + toInt(final[i - 3]) + toInt(final[i - 2]) + toInt(final[i - 1]) + toInt(final[i]));
        }
    }
    std::cout << DP[N];
    return 0;
}