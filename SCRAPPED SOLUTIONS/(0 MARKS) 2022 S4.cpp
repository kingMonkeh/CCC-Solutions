/*

2022 S4 - Good Triplets

0/15 Marks

Algorithm always produces a correct answer, except TLE and SIGNAL 6 occur

*/

#include <iostream>
#include <vector>
#include <set>

typedef std::vector<int> vi;

int N;
double C;
int goodTriplets = 0;

vi coords (1000001);

void generateTriplets (vi remainingIndices, vi triplet = {0, 0, 0, 0}, int depth = 1){

    if (depth <= 3){

        for (int i = 1; i <= remainingIndices.size(); i++){

            if (remainingIndices[i] > triplet[depth - 1]){
                triplet[depth] = remainingIndices[i];
                depth++;
                int backup = remainingIndices[i];
                remainingIndices[i] = 0;
                generateTriplets(remainingIndices, triplet, depth);
                depth--;
                remainingIndices[i] = backup;
            }

        }

    }

    else{
        double point1 = triplet[1];
        double point2 = triplet[2];
        double point3 = triplet[3];

        std::set<int> tripletcoords;
        tripletcoords.insert(coords[point1]);
        tripletcoords.insert(coords[point2]);
        tripletcoords.insert(coords[point3]);

        auto it = tripletcoords.begin();
        double coord1 = *it;
        it++;
        double coord2 = *it;
        it++;
        double coord3 = *it;

        if (tripletcoords.size() == 3 && coord2 - coord1 < C/2 && coord3 - coord2 < C/2 && coord1 + C - coord3 < C/2){
            goodTriplets++;
        }
        
    }

}

int main(){

    std::cin >> N >> C;

    vi indices (N + 1);

    for (int i = 1; i <= N; i++){
        std::cin >> coords[i];
        indices[i] = i;
    }

    generateTriplets(indices);

    std::cout << goodTriplets;

    return 0;

}