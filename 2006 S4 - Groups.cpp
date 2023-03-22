/*

2006 S4 - Groups

Difficulty: Medium

The hardest part about this problem is understanding the problem statement

Basically the problems asking us to check 3 things about a group

First its identity

Essentially, for a group to have an identity
there has to be some cross of 1 2 3 4 5 6 ... n up and down like this

  1                           1
1 2 3 4 5 6                   2
  3                           3
  4           OR        1 2 3 4 5 6
  5                           5
  6                           6

The identity is just the intersection number, aka 2 for the first example and 4 for the second

We can easily do this in a nested for loop checking horizontall and vertically

2. Checking inverse, essentially, every row needs to have the identity somewhere in it

If we find the identity at [i][j], then the identity must also be at [j][i], otherwise it wouldnt be an inverse

Once again, this can be accomplished using another nested for loop

Lastly, checking associativity
For this, all its basically saying is that
group[x][group[y][z]] must equal to group[group[x][y]][z]

There's really no other way of checking this besides a triple for loop with N^3 time complexity, luckily the input isnt that big so its fine

*/

#include <iostream>
#include <vector>

int main(){

    while (true){

        //Get vector size, if 0 terminate
        int n; std::cin >> n;

        if (n == 0){
            break;
        }

        //Create group
        std::vector<std::vector<int>> group (n, std::vector<int> (n));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                std::cin >> group[i][j];
            }
        }

        //Find identity

        int identity = -1; //Stores the identity of the group, if no identity found, its default is -1

        for (int i = 0; i < n; i++){

            bool identityFound = true;

            for (int j = 0; j < n; j++){

                //Check horizontally
                if (group[i][j] != j + 1){
                    identityFound = false;
                    break;
                }

                //Check vertically
                if (group[j][i] != j + 1){
                    identityFound = false;
                    break;
                }

            }

            //If the identity is found
            if (identityFound){
                identity = i + 1;
                break;
            }

        }

        //If no identity, the group is impossible
        if (identity == -1){
            std::cout << "no\n";
            continue;
        }

        //Check inverse
        bool inverseCheck = true;

        for (int i = 0; i < n && inverseCheck; i++){

            bool iFound = false; //Remember, each row must contain i, if no identity is found, then there's no inverse then

            for (int j = 0; j < n && inverseCheck; j++){

                if (group[i][j] == identity){
                    iFound = true;

                    //If group[i][j] equals identity so must group[j][i]
                    if (group[j][i] != identity){
                        inverseCheck = false;
                    }

                }

            }

            if (!iFound){
                inverseCheck = false;
            }

        }

        if (!inverseCheck){
            std::cout << "no\n";
            continue;
        }

        //Check associativity

        bool good = true;

        for (int x = 0; x < n && good; x++){

            for (int y = 0; y < n && good; y++){

                for (int z = 0; z < n && good; z++){

                    //Literaly implementing the problem
                    if (group[x][group[y][z] - 1] != group[group[x][y] - 1][z]){
                        good = false;
                    }

                }

            }

        }

        if (!good){
            std::cout << "no\n";
            continue;
        }

        std::cout << "yes\n";

    }

    return 0;

}