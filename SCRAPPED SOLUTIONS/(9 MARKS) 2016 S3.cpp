/*

2016 S3 - Phenomenal Reviews

INCOMPLETE SOLUTION
9/15 MARKS

*/

#include <iostream>
#include <queue>
#include <vector>
#include <set>

int N, M;
std::vector<bool> visitedPhoRestaurants;
std::vector<int> phoRestaurants;
std::set<int> walking_times;
std::vector<std::vector<int>> distances;


void walking_time (int current, int distance = 0, int depth = 1){

    for (const int phoRestaurant: phoRestaurants){

        if (!visitedPhoRestaurants[phoRestaurant]){
            visitedPhoRestaurants[phoRestaurant] = true;
            distance += distances[current][phoRestaurant];
            walking_time(phoRestaurant, distance, depth + 1);
            distance -= distances[current][phoRestaurant];
            visitedPhoRestaurants[phoRestaurant] = false;
        }

    }

    if (depth == M){
        walking_times.insert(distance);
    }

}

int main(){

    std::cin >> N >> M;

    visitedPhoRestaurants.resize(N, false);
    phoRestaurants.resize(M);
    distances.resize(N, std::vector<int> (N));

    for (int i = 0; i < M; i++){

        std::cin >> phoRestaurants[i];

    }

    //roads[i] is a vector containing all restaurants connecting to restaurant i
    std::vector<std::vector<int>> roads (N);

    for (int i = 0; i < N - 1; i++){
        int restaurant1, restaurant2;
        std::cin >> restaurant1 >> restaurant2;
        roads[restaurant1].push_back(restaurant2);
        roads[restaurant2].push_back(restaurant1);
    }

    //BFS FROM ALL PHO RESTAURANTS
    for (int i = 0; i < M; i++){

        std::vector<bool> alreadyVisited (N, false);
        std::queue<int> q;

        q.push(phoRestaurants[i]);
        alreadyVisited[phoRestaurants[i]] = true;

        distances[phoRestaurants[i]][phoRestaurants[i]] = 0;

        while (!q.empty()){

            int current_restaurant = q.front();
            q.pop();

            for (const int restaurant: roads[current_restaurant]){

                if (!alreadyVisited[restaurant]){
                    q.push(restaurant);
                    distances[phoRestaurants[i]][restaurant] = distances[phoRestaurants[i]][current_restaurant] + 1;
                }

                alreadyVisited[restaurant] = true;

            }

        }

    }

    for (const int phoRestaurant: phoRestaurants){

        visitedPhoRestaurants[phoRestaurant] = true;
        walking_time(phoRestaurant);
        visitedPhoRestaurants[phoRestaurant] = false;

    }

    std::cout << *walking_times.begin();

    return 0;

}