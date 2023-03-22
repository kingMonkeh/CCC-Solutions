/*

2005 S4 - Pyramid Message Scheme

Difficluty: Easy/Medium

Basically, the difference in cost is just the original cost - 2 * (the height of the tree minus 1)

*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

int main(){

    int L; std::cin >> L;

    for (int i = 0; i < L; i++){

        int n; std::cin >> n;

        std::vector<std::string> input (n); //String holding the names in the order they were inputted. Note that the root of the tree is not always called "Home"
        std::map<std::string, int> level; //Tells us how many levels the tree has, level[name] -> what level this person is at on the tree

        //Get input
        for (int j = 0; j < n; j++){
            std::cin >> input[j];
        }

        int max = 0; //Max level attained

        std::string start = input[n - 1]; //The root node, is the last name entered since all mail must go back to the root in the end
        level[start] = 1; //The root is at level 1

        //To get the level of a person, we make their level the level of the previous person in the input + 1
        std::string previous;
        //Set up for the first person, since they will be the previous for the second
        if (input.size() > 1){
            level[input[0]] = 2;
            previous = input[0];
            max = std::max(max, level[input[0]] - 1); //Update max accordingly
        }   

        //For the remaining people
        for (int j = 1; j < n; j++){

            //If we've never met this person before, (note that maps with int values default with 0 upon creation)
            if (!level[input[j]]){
                level[input[j]] = level[previous] + 1;
                max = std::max(max, level[input[j]] - 1);
            }

            previous = input[j];

        }

        std::cout << n * 10 - max * 20 << '\n'; //Output difference

    }

    return 0;

}