/*

2014 S3 - Geneva Confection

Difficulty: Easy

Type: Ad Hoc/Implementation

No special algorithm or key realization to be made, quite literaly just program the scenario.
This question is extremely easy for an S3.

*/

#include <iostream>
#include <vector>

int main(){

    int T, N;

    std::cin >> T;

    std::vector<int> branch, ingredient_line; //Store ingredients in branch and the actual dropdown line
    int cart, current_ingredient; //cart represents the next ingredient to be dropped, current ingredient represents what ingredients have been added to Lake Geneva
    bool possible;

    //For each test case
    for (int i = 0; i < T; i++){

        //Reset for each case so that leftover values from previous tests will not carry over
        possible = true;
        current_ingredient = 0;
        branch.clear();
        ingredient_line.clear();

        std::cin >> N;

        //Collect ingredient line, note that the first element to go is the last element in the vector since we're using push_back()
        for (int j = 0; j < N; j++){

            std::cin >> cart;

            ingredient_line.push_back(cart);

        }

        while (ingredient_line.size() > 0){

            //If this ingredient is the next one to be added to the lake
            if (ingredient_line[ingredient_line.size() - 1] == current_ingredient + 1){
                ingredient_line.pop_back();
                current_ingredient++;
            }

            //If not, check the branch if it's possible to continue
            else if (branch.size() > 0 && branch[branch.size() - 1] == current_ingredient + 1){
                branch.pop_back();
                current_ingredient++;
            }

            //If neither of the above, add ingredient to the branch
            else{
                branch.push_back(ingredient_line[ingredient_line.size() - 1]);
                ingredient_line.pop_back();
            }

        }

        //For the remaining ingredients that are still in the branch
        while (branch.size() > 0){

            if (branch[branch.size() - 1] == current_ingredient + 1){
                branch.pop_back();
                current_ingredient++;
            }

            else{
                break;
            }
            
        }

        if (current_ingredient != N){
            possible = false;
        }

        if (possible){
            std::cout << "Y" << std::endl;
        }

        else{
            std::cout << "N" << std::endl;
        }

    }

    return 0;

}