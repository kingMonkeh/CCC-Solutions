/*

2005 S5 - Pinball Ranking

Difficulty: Hard

This problem is a very interesting use of Fenwick tree
Basically take in all the numbers
After, sort them in descending order
Afterward, create a map and map each score to its corresponding index, note: please use 1 indexing to make your life easier

From here, imagine you have an array [0, 0, 0, 0, 0]
In this array, the only possible values for a number are 0 or 1
0 indicating this score has not yet been added yet
Or 1 indicating this score has been added
array[i] tells us whether or not score i from our descending score list has been added or not

From here, we can generate a Fenwick Tree of this state array
Then to determine the rank of an element
We calculate the prefix sum up until the index of this element
This prefix sum would tell us the total number of scores higher than the queried score

Updating the tree is equally as simple, just add 1 to all affected pieces of the tree

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int t;
std::vector<int> BIT; //Tree
std::map<int, int> valToKey; //Map score to index in sorted array

//Update tree
void update(int index){
    while (index <= t){
        BIT[index]++;
        index += index & (-index);
    }
}

//Query tree
int query(int index){
    int rank = 0;
    while (index > 0){
        rank += BIT[index];
        index -= index & -index;
    }
    return rank;
}

int main(){
    scanf("%d", &t);
    BIT.resize(t + 1, 0);
    //Get numbers in array, keep one where numbers are in the order they were originally inputted.
    //Keep another to sort them in descending order and map their values to keys
    std::vector<int> original (t + 1);
    std::vector<int> copy (t + 1);
    original[0] = -9999;
    copy[0] = -9999;
    for (int i = 1; i <= t; i++){
        scanf("%d", &original[i]);
        copy[i] = original[i];
    }
    //Sort descending
    std::sort(copy.begin(), copy.end(), std::greater<int>());
    //Map values
    for (int i = 1; i <= t; i++){
        valToKey[copy[i - 1]] = i;
    }
    //Calculate total
    double answer = 0.0;
    for (int i = 1; i <= t; i++){
        int score = original[i];
        //Query, remember to query(index - 1), since query is inclusive and we don't actually want to include the current index
        answer += query(valToKey[score] - 1) + 1;
        //Update tree
        update(valToKey[score]);
    }
    //Print answer rounded to 2 decimal places
    printf("%.2f", answer / t);
    return 0;
}