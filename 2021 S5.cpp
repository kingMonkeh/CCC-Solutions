/*
Difficulty: Hard
Topics: Intermediate Math + Data Structures

Important concepts to solving the problem:
Segment tree, difference arrays, GCD, LCM, LCM formula

Key things to note about the question
Subtask 1:
1. Subtask 1 could have been coded using only 1's and 2's, whenver Z = 2, just set the terms in range(X, Y) to Z and then check each requirement to ensure the sequence is still valid

Subtask 2:
1. Note that each term A, in the sequence must be divisible by all Z's that pass through it. This means that A must be a multiple of the LCM of all the Z's that pass through it
2. But with so many choices how do we choose the correct multiple of the LCM? Answer: It's always optimal to take the LCM because as A become larger, it gains more and more divisors, thus our goal is to minimize A
3. Therefore, generating the sequence linearly using the rules above and checking the requirements works due to the small input size

Time Complexity O(N * M)

Subtask 3:
With the greatly increased input size, we must optimize subtask 2.
Note that 1 <= Z <= 16, this means we can implement 16 difference arrays.
1. When collecting the requirements and determining which Z's pass through term A, instead of traversing our array linearly and changing each value for each requirement, we can use difference arrays to store all the changes quickly and then perform one LCM calculation at the end for each term A.
2. Checking the requirements after generating our list is a bit more tricky to optimize.
3. For this, we will use a segment tree which will allow us to efficiently query many large ranges

General algorithm:
0. Create segment tree functions (build and query)
1. Collect inputs, update difference array indexes accordingly
2. Implement requirements on difference arrays
3. Generate sequence using LCM formula
4. Check requirements via query function.
5. Output "Impossible" or the sequence depending on the return value of the query function
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <vector>

int sequence[150001];
int segmentTree[150001 * 4]; //Generally a segment tree will never be larger than 4 times the size of the original array, read proof online if you're curious as to why

//Build function for segment tree with 1 indexing
void build (int i = 1, int treeleft = 1, int treeright = 150001){

    //When we encounter a leaf node
    if (treeleft == treeright){

        segmentTree[i] = sequence[treeleft];

    }

    else{

        //Calculate midpoint, use int division to discard remainder
        int mid = treeleft + (treeright - treeleft) / 2;
        build (i * 2, treeleft, mid);
        build (i * 2 + 1, mid + 1, treeright);
        segmentTree[i] = std::gcd(segmentTree[i * 2], segmentTree[i * 2 + 1]);

    }

}

//Query function for segment tree
int query (int left, int right, int i = 1, int treeleft = 1, int treeright = 150001){

    //Out of range
    if (left > right){
        return 0;
    }

    //Segment of the tree is a part of the range
    if (left == treeleft && right == treeright){
        return segmentTree[i];
    }
    
    //Calculate mid
    int mid = treeleft + (treeright - treeleft) / 2;
    
    //If segment is partially in range, recurse deeper down the segment tree until corresponding nodes are found
    //The min and max functions are important here to ensure that the proper range is being queried with each recurse
    return std::gcd(query (left, std::min(mid, right), i * 2, treeleft, mid), query (std::max(mid + 1, left), right, i * 2 + 1, mid + 1, treeright));

}

int main(){

    //Difference arrays, size 150002 because of 1 indexing and the final index padding as well
    std::map<int, std::vector<int>> diffarrays;
    diffarrays[1] = std::vector<int> (150002, 0);
    diffarrays[2] = std::vector<int> (150002, 0);
    diffarrays[3] = std::vector<int> (150002, 0);
    diffarrays[4] = std::vector<int> (150002, 0);
    diffarrays[5] = std::vector<int> (150002, 0);
    diffarrays[6] = std::vector<int> (150002, 0);
    diffarrays[7] = std::vector<int> (150002, 0);
    diffarrays[8] = std::vector<int> (150002, 0);
    diffarrays[9] = std::vector<int> (150002, 0);
    diffarrays[10] = std::vector<int> (150002, 0);
    diffarrays[11] = std::vector<int> (150002, 0);
    diffarrays[12] = std::vector<int> (150002, 0);
    diffarrays[13] = std::vector<int> (150002, 0);
    diffarrays[14] = std::vector<int> (150002, 0);
    diffarrays[15] = std::vector<int> (150002, 0);
    diffarrays[16] = std::vector<int> (150002, 0);

    //Main code
    int N, M;

    std::cin >> N >> M;

    //For storing requirements
    int x[150000];
    int y[150000];
    int z[150000];

    //Collect requirements
    for (int i = 0; i < M; i++){
        std::cin >> x[i] >> y[i] >> z[i];

        //Update difference array
        diffarrays[z[i]][x[i]] += 1;
        diffarrays[z[i]][y[i] + 1] -= 1;
        
    }

    //Final iteration over difference arrays
    int sum;
    for (int i = 1; i <= 16; i++){

        sum = 0;
        
        for (int j = 1; j <= 150000; j++){
            sum += diffarrays[i][j];
            diffarrays[i][j] = sum;
        }

    }


    //Generate sequence
    for (int i = 1; i <= N; i++){

        //Determine LCM
        int lcm = 1;
        for (int z = 1; z <= 16; z++){

            if (diffarrays[z][i] > 0){

                //Formula of lowest common multiple of a, b is the absolute of (a * b) / gcd(a, b), in this case there's no negatives so I discard the absolute value part
                lcm = lcm * z / std::gcd(lcm, z);

            }

        }

        //Add to sequence
        sequence[i] = lcm;

    }

    //Build segment tree
    build();

    //Check requirements via query function we created
    for (int i = 0; i < M; i++){

        //If GCD of range(x, y) != z
        if (query(x[i], y[i]) != z[i]){
            std::cout << "Impossible";
            return 0;
        }

    }

    //Output sequence
    for (int i = 1; i <= N; i++){
        std::cout << sequence[i] << ' ';
    }

    return 0;
}