/*

2020 S4 - Swapping Seats

Difficulty: Medium/Hard

I had to look up a solution to this problem.

The reason this problem is rated Medium is because it's an extension to 2021 J4 "Arranging Books". Nonetheless, it's still quite a challenging problem and definitely an S4

Key insights to solving:

Due to the time limit on this problem, a time complexity of O(N) will be needed since the table can be up to 1 000 000 people

It's best to do swaps that get 2 people in the right place at the same time first
Afterwards you must do inefficient swaps. Aka only one person ends up in the right place after swapping

To know what needs to be swapped, we will be dividing the table into sections, section A, section B and section C with each section being where all the corresponding letters should be
However, these sections can be placed anywhere and in any order, therefore we must check all possible section arrangements

There are 6 permutations of ABC which are
ABC
ACB
BAC
BCA
CAB
CBA

Note however that since the table is circular, ABC == CAB == BCA, and ACB == CBA == BAC. This means we only need to check these two orders of ABC

As for checking section offset, we will be using a rolling window.

I will be using a map to store the number of A's, B's and C's in a section

Finally, the minimum number of swaps for a certain section arrangment is:
# of non A's in section A + # of non B's in section B - min(# of A's in section B, # of B's in section A)

This formula is quite intuitive since it first calculates the total amount of inefficient swaps needed and then subtracts the total amount of optimal swaps that can be made.
Note that C is not needed in this formula because if A and B are sorted, then C must be sorted as well

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

int main(){

    std::string table; //Represent table
    std::cin >> table;

    int table_size = table.size();

    table += table; //Since the table is circular, we need to connect it's ends for our sliding window to work. You could try to accomplish a rolling window with negative indexing but that's too much work

    int countA = 0; //Total number of A's
    int countB = 0; //Total number of B's
    int countC = 0; //Total number of C's

    //Count each letter frequency
    for (int i = 0; i < table_size; i++){

        if (table[i] == 'A'){
            countA++;
        }

        else if (table[i] == 'B'){
            countB++;
        }

        else{
            countC++;
        }

    }

    //Our sections, the key is the letter in that section and the corresponding value is the frequency of that letter
    //For example sectionA['A'] == 5 means that there are 5 A's in section A
    std::map<char, int> sectionA;
    std::map<char, int> sectionB;
    std::map<char, int> sectionC;

    sectionA['A'] = 0, sectionA['B'] = 0, sectionA['C'] = 0;
    sectionB['A'] = 0, sectionB['B'] = 0, sectionB['C'] = 0;
    sectionC['A'] = 0, sectionC['B'] = 0, sectionC['C'] = 0;

    //Calculate letter frequency in each section

    //Section A
    for (int i = 0; i < countA; i++){

        sectionA[table[i]]++;

    }

    //Section B
    for (int i = countA; i < countA + countB; i++){

        sectionB[table[i]]++;

    }

    //Section C
    for (int i = countA + countB; i < countA + countB + countC; i++){

        sectionC[table[i]]++;

    }

    //Calculate minimum number of swaps for initial arrangement (no offset)
    int num_of_swaps = sectionA['B'] + sectionA['C'] + sectionB['A'] + sectionB['C'] - std::min(sectionA['B'], sectionB['A']);
    std::set<int> swaps; //I will just be inserting all values into a set, sets are ordered therefore at the end I will print the minimum value of the set
    swaps.insert(num_of_swaps);

    //Rolling window begin
    for (int i = 0; i < table_size - 1; i++){

        sectionA[table[i]]--; //Remove first part of section A
        sectionA[table[i + countA]]++; //Add to section A
        sectionB[table[i + countA]]--; //Remove first part of section B
        sectionB[table[i + countA + countB]]++; //Add to section B
        sectionC[table[i + countA + countB]]--; //Remove first part of section C
        sectionC[table[i + countA + countB + countC]]++; //Add to section C

        //Calculate minimum number of swaps for this particular arrangement and positioning
        num_of_swaps = sectionA['B'] + sectionA['C'] + sectionB['A'] + sectionB['C'] - std::min(sectionA['B'], sectionB['A']);
        swaps.insert(num_of_swaps);

    }

    //
    // Previously, we just calculated all possible possitions for arrangement ABC, we must now do the same for CBA 
    //

    //Reset sections
    sectionA['A'] = 0, sectionA['B'] = 0, sectionA['C'] = 0;
    sectionB['A'] = 0, sectionB['B'] = 0, sectionB['C'] = 0;
    sectionC['A'] = 0, sectionC['B'] = 0, sectionC['C'] = 0;

    //Count frequencies once more, except in CBA order now

    //Section C
    for (int i = 0; i < countC; i++){

        sectionC[table[i]]++;

    }

    //Section B
    for (int i = countC; i < countC + countB; i++){

        sectionB[table[i]]++;

    }

    //Section A
    for (int i = countC + countB; i < countC + countB + countA; i++){

        sectionA[table[i]]++;

    }

    num_of_swaps = sectionA['B'] + sectionA['C'] + sectionB['A'] + sectionB['C'] - std::min(sectionA['B'], sectionB['A']);
    swaps.insert(num_of_swaps);

    //Rolling window once again
    for (int i = 0; i < table_size - 1; i++){

        sectionC[table[i]]--; //Remove first part of section C
        sectionC[table[i + countC]]++; //Add to section C
        sectionB[table[i + countC]]--; //Remove first part of section B
        sectionB[table[i + countC + countB]]++; //Add to section B
        sectionA[table[i + countC + countB]]--; //Remove first part of section A
        sectionA[table[i + countC + countB + countA]]++; //Add to section A

        num_of_swaps = sectionA['B'] + sectionA['C'] + sectionB['A'] + sectionB['C'] - std::min(sectionA['B'], sectionB['A']);
        swaps.insert(num_of_swaps);

    }

    //Output minimum number of swaps
    std::cout << *swaps.begin();

    return 0;

}