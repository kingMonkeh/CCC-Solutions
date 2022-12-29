#include <iostream>
#include <vector>
#include <string>

/*
Ad Hoc Problem
Difficulty: Easy-Medium
This question is not difficult, it's just annoying to implement. Decent knowledge of array manipulation is required to answer this question because of all the indices.
General algorithm to solve this problem:
1. Collect input - I'm using several vectors for the basic info and one 2D vector for the pairs, note that there are more optimal data structures that what I'm using
2. For each reference:
3. Determine the corresponding index with the array name
4. Collect the index values (i)
5. Calculate C[N]
6. Calculate C[d] to C[N] not including C[N] using the formula provided
7. Calculate C[0] using the information you previously calculated
8. Calculate the address
9. Print out the address formatted properly

Be careful of accessing the wrong index when making calculations. Make sure your expressions are correct and work for all positive integers
*/

int main(){

    //Collect input
    int N, R;
    std::cin >> N >> R;

    std::vector<int> bases;
    std::vector<int> elem_sizes;
    std::vector<int> dimensions;
    std::vector<std::vector<int>> pairs;
    std::vector<std::string> names;

    std::string name;
    int base, elem_size, dimension, pair1, pair2; 

    for (int i = 0; i < N; i++){
        std::cin >> name >> base >> elem_size >> dimension;
        names.push_back(name);
        bases.push_back(base);
        elem_sizes.push_back(elem_size);
        dimensions.push_back(dimension);

        std::vector<int> p;
        pairs.push_back(p);

        for (int d = 0; d < dimension; d++){
            std::cin >> pair1 >> pair2;
            pairs[i].push_back(pair1);
            pairs[i].push_back(pair2);
        }
    }


    int nameindex, index, address; //index corresponding to name, index will be used for appending i values, address is memory address
    std::vector<int> indices; //For storing i values
    std::vector<int> C(11); //Can't be more than 10 dimensions, remember C0 exist

    //For each requirement
    for (int i = 0; i < R; i++){

        std::cin >> name;

        //Find corresponding index to name
        for (int z = 0; z < N; z++){
            if (names[z] == name){
                nameindex = z;
            }
        }

        //Get in indices
        for (int d = 0; d < dimensions[nameindex]; d++){
            std::cin >> index;
            indices.push_back(index);
        }

        //Calculate C[1] to C[D]
        C[dimensions[nameindex]] = elem_sizes[nameindex];
        for (int d = dimensions[nameindex] - 1; d > 0; d--){
            C[d] = C[d + 1] * (pairs[nameindex][d * 2 + 1] - pairs[nameindex][d * 2] + 1);
        }

        //Calculate C0
        C[0] = bases[nameindex];
        for (int d = 1; d <= dimensions[nameindex]; d++){
            C[0] -= (C[d] * pairs[nameindex][(d - 1) * 2]);
        }

        //Calculate address

        address = C[0];

        for (int c = 1; c <= dimensions[nameindex]; c++){
            address += (C[c] * indices[c - 1]);
        }

        //Print out address
        std::cout << names[nameindex] << '[' << indices[0];

        for (int i = 1; i < indices.size(); i++){
            std::cout << ", " << indices[i];
        }

        std::cout << "] = " << address << std::endl;

        //Clean up for next requirement
        indices.clear();


    }

    return 0;
}