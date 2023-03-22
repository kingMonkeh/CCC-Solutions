/*

2008 S4 - Twenty-four

Difficulty: Medium

This problem is kinda simple. Since there's only 4 cards, you can essentially just brute force through every combination of operations

To do this, write a recursive function that selects 2 cards at a time and applies some operation to them (+, -, *, /)

Watch out for non zero remainder division and dividing by 0 in general

*/

#include <iostream>
#include <set>

int max = 0; //Maximum amount that can be created
std::multiset<int> hand; //Multset storing the hand, I tried with vectors but i suck so I just switched to multiset for easy insertion and deletion

//Solve function, takes in a hand and selects 2 cards to apply operations to
void solve(std::multiset<int> h){

    //If all cards have been combined, check if it's greater than max
    if (h.size() == 1){
        if (*h.begin() > max && *h.begin() <= 24){
            max = *h.begin();
        }
    }

    else{

        //For each card1
        for (auto it = h.begin(); it != h.end(); it++){
            
            auto itt2 = it;
            itt2++;

            //For each card2
            for (auto it2 = itt2; it2 != h.end(); it2++){

                int card1 = *it;
                int card2 = *it2;

                //Create a temporary multiset to apply changes to
                std::multiset<int> temp = h;

                //Erase the cards that are to be combined
                //Remember to use .find() to ensure only a single element is erased and not several duplicates
                temp.erase(temp.find(card1));
                temp.erase(temp.find(card2));

                //Addition
                int addition = card1 + card2;
                temp.insert(addition);
                solve(temp);
                temp.erase(temp.find(addition));

                //Subtraction, remember it results in different values depending on the order so just do both
                int subtraction1 = card1 - card2;
                temp.insert(subtraction1);
                solve(temp);
                temp.erase(temp.find(subtraction1));

                int subtraction2 = card2 - card1;
                temp.insert(subtraction2);
                solve(temp);
                temp.erase(temp.find(subtraction2));

                //Multiplication, order doesnt matter
                int multiplication = card2 * card1;
                temp.insert(multiplication);
                solve(temp);
                temp.erase(temp.find(multiplication));

                //Division, order does matter so do both
                //Ensure that the denominator is not 0 otherwise you get floating point error
                //Remember that no remainder is allowed
                if (card2 != 0 && card1 % card2 == 0){
                    int division1 = card1 / card2;
                    temp.insert(division1);
                    solve(temp);
                    temp.erase(temp.find(division1));
                }

                if (card1 != 0 && card2 % card1 == 0){
                    int division2 = card2 / card1;
                    temp.insert(division2);
                    solve(temp);
                    temp.erase(temp.find(division2));
                }

            }

        }

    }

}

int main(){

    int N;
    std::cin >> N;

    //For each hand
    for (int i = 0; i < N; i++){

        //Get hand
        for (int j = 0; j < 4; j++){
            int card;
            std::cin >> card;
            hand.insert(card);
        }

        solve(hand); //Solve

        std::cout << max << '\n';

        //Reset for next hand
        max = 0;

        hand.clear();

    }

    return 0;

}