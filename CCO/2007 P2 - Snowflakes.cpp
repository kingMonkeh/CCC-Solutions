/*

CCO 2007 P2 - Snowflakes

Basically, we don't need to check every rotation of every snowflake

Instead, we will find the minimum arm of each snowflake and determine its values clockwise and counter clockwise and add it to a set

If there are multiple, we add all of them, a bit costly, but still dramatically reduces memory usage overall

Keep track of how many variations are added to the set, if at the end, the amount in the set does not match with how much should be in the set, then there must have been a duplicate

*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main(){

    int n;
    std::cin >> n;

    std::set<std::vector<int>> snowflakes; //Our snowflakes
    int theoretical = 0; //How many variations should be in the set

    for (int i = 0; i < n; i++){

        std::vector<int> snowflake (12); //I'm gonna be doubling the snowflake to make it easier to wrap around the vector
        int minimum = 2147483647;

        for (int j = 0; j < 6; j++){
            std::cin >> snowflake[j];
            snowflake[j + 6] = snowflake[j];
            
            //Keep track of minimum arm length
            if (snowflake[j] < minimum){
                minimum = snowflake[j];
            }
        }

        std::set<std::vector<int>> count; //Vector holding all unique variations of this snowflake that have been generated

        //For each arm, if it's equal to min, generate the clockwise and counterclock wise versions
        for (int j = 0; j < 6; j++){

            if (snowflake[j] == minimum){

                std::vector<int> temp (6);
                std::vector<int> reversed (6);
                
                //Clockwise
                for (int k = j; k < j + 6; k++){
                    temp[k - j] = snowflake[k];
                }

                snowflakes.insert(temp);

                //Other way
                for (int k = j + 6, w = 0; k > j; k--, w++){
                    reversed[w] = snowflake[k];
                }

                snowflakes.insert(reversed);

                //Add to count, this is just to make sure that duplicates are not counted, for example imagine the snowflake 1 1 1 1 1 1
                count.insert(temp);
                count.insert(reversed);

            }

        }

        theoretical += count.size(); //Add to theoretical amount

    }

    //If it matches up
    if (snowflakes.size() == theoretical){
        std::cout << "No two snowflakes are alike.\n";
    }

    //Otherwise
    else{
        std::cout << "Twin snowflakes found.\n";
    }

    return 0;

}