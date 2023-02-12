/*

MOCK J3 - Pairing Gifts

Difficulty: Easy/Medium

This problem is like an easier version of 2017 J5/S3 - Nailed It!

Since the values of each gift are distinct, you can map them to their gift number.
From this, iterate through one list, for each element, determine the corresponding amount needed to create M.
Determine if this corressponding gift exists, if it does, make sure it satisfies the K rule using the mapped gift numbers.

*/

#include <iostream>
#include <set>
#include <vector>
#include <map>

int main(){

    long long answer = 0;
    long long N, K, M;
    std::cin >> N >> K >> M;

    //Set allows quick look up time to see if it exists
    std::set<long long> christmasSorted;
    std::set<long long> newYearsSorted;
    //Iterate through regular vector
    std::vector<long long> christmas (N + 1);
    std::vector<long long> newYears (N + 1);
    //Map gift value to gift number
    std::map<int, int> christmasMap;
    std::map<int, int> newYearsMap;

    for (int i = 1; i <= N; i++){
        std::cin >> christmas[i];
        christmasSorted.insert(christmas[i]);
        christmasMap[christmas[i]] = i;
    }

    for (int i = 1; i <= N; i++){
        std::cin >> newYears[i];
        newYearsSorted.insert(newYears[i]);
        newYearsMap[newYears[i]] = i;
    }

    //Itearate through christmas gifts
    for (int i = 1; i <= N; i++){

        long long partner = M - christmas[i]; //Find required corresponding gift value

        //If it exists
        if (newYearsSorted.count(partner) == 1){

            long long diff = std::abs(i - newYearsMap[partner]); //Check K Rule

            //If perfect gift, add
            if (diff >= K){
                answer++;
            }

        }

    }

    std::cout << answer << '\n';

    return 0;

}