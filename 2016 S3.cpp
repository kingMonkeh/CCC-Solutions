/*

2016 S3 - Phenomenal Reviews

Difficulty: Hard

This question requires good understanding of graph theory. If you're not comfortable with graph theory, I recommend you practice some easier problems before continuing.

How to solve the problem:
Which restaurants do we have to traverse?
We only need to traverse the restaurants that are pho restaurants or are in between pho restaurants. We will never visit non-pho restaurants that are not in between pho restaurants.
That's why step 1 to this problem is trimming the tree, you must trim the tree such that only pho restaurants make up the leaf nodes of the tree

After doing so, imagine the following:
Start at any arbitrary point in this new tree. To have visited every pho restaurant, Jo would have to walk to each leaf node in tree.
Let's say for now that she must return to her starting position after each visit to a leaf node. What is the total distance she must walk?
Answer: She must walk the total distance of all the roads of the new tree and then repeat this to undo her steps. Therefore 2 * number of roads

But, in the question, Jo does not have to return to her starting position. Once she reaches the last pho restaurant she's done.
Therefore, the actual distance is 2 * number of roads - the distance it would take for her to walk back from the last restaurant

Since the question is asking us for the minimum time required. We'd like to maximise the distance between the last restaurant she visits and her starting point.
The longest distance between any 2 leaf nodes in a tree is called the diameter of the tree. The diameter of a tree can be found by taking any random point in the tree, determining the furthest point from the original point. Then finding the furthest point from the previously found point.
The distance between these two found points is the maximum diameter of a tree.

Therefore the answer to the problem is 2 * # of roads in trimmed tree - Max diameter of new tree

*/

#include <iostream>
#include <vector>

std::vector<bool> isPhoRestaurant; //isPhoRestaurant[i] = true means that restaurant i is a pho restaurant
std::vector<std::vector<int>> roads; //Represent the paths between the restaurants
int numberOfRoads, diameter = 0, vertexA; //Total number of roads, diameter of tree, furthest point from random starting point. VertexA will be used in determining the diameter

//Cutting the tree, I say cut but really we're not deleting anything, we're just going to ignore useless restaurants
bool cut (int current, int previous, int depth = 0){

    bool connectedToPho = false; //If the current restaurant is a mandatory step to another pho restaurant or is a pho restaurant

    //For all connecting restaurants
    for (const int nextRestaurant: roads[current]){

        //Prevent going backwards
        if (nextRestaurant != previous){

            //Continue traversing the graph, when the recursion ends, it will tell us whether the current restaurant connects to a pho restaurant
            if (cut (nextRestaurant, current, depth + 1)){
                connectedToPho = true;
            }

        }

    }

    // If we hit a leaf node/dead end and it's a pho restaurant
    if (isPhoRestaurant[current] == true){
        connectedToPho = true;
    }

    //If we find a point that is not connected to a pho restaurant and is not a pho restaurant itself
    if (!connectedToPho){
        numberOfRoads--;
        return false;
    }

    //We can safely assume the current restaurant is connectedToPho because we've passed the previous if statement. Depth tells us our current distance. Remember we want to find the furthest point from the random point where we started.
    if (depth > diameter){
        diameter = depth;
        vertexA = current;
    }

    return true;

}

//Essentially same thing as cut, except we're no longer removing roads, we're just ignoring them
bool findDiameter (int current, int previous, int depth = 0){

    bool connectedToPho = false;
    for (const int nextRestaurant: roads[current]){

        if (nextRestaurant != previous){

            if (findDiameter (nextRestaurant, current, depth + 1)){
                connectedToPho = true;
            }

        }

    }

    if (isPhoRestaurant[current] == true){
        connectedToPho = true;
    }

    //No cutting
    if (!connectedToPho){
        return false;
    }

    //Recall the method I explained in the beginning as to how to find the max diameter, max diameter = distance between vertexA and furthest point from vertexA
    if (depth > diameter){
        diameter = depth;
    }

    return true;

}

int main(){

    int N, M;
    std::cin >> N >> M;

    numberOfRoads = N - 1;

    isPhoRestaurant.resize(N, false);
    roads.resize(N);

    int phoRestaurant;
    for (int i = 0; i < M; i++){

        std::cin >> phoRestaurant;
        isPhoRestaurant[phoRestaurant] = true; //Mark Pho Restaurants

    }

    for (int i = 0; i < N - 1; i++){

        int restaurant1, restaurant2;
        std::cin >> restaurant1 >> restaurant2;
        //Remember the roads go both ways
        roads[restaurant1].push_back(restaurant2);
        roads[restaurant2].push_back(restaurant1);

    }

    cut (phoRestaurant, -1); //Cut the tree, determine vertexA
    findDiameter(vertexA, -1); //Perform a secondary dfs using vertexA as a starting point to find the furthest point, distance between the found point and vertexA is the max diameter

    int answer = numberOfRoads * 2 - diameter;

    std::cout << answer;

    return 0;

}