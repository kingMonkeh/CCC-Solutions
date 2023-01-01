/*

2022 S3 Scrapped Solution

Algorithm: Complete search/Brute force

3/15 Marks

Completes Subtask 1

*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

std::vector< std::vector<int> > possibleSequences;

void generateSequences (std::vector<int> seq, int term, int i, int size){

    if (i == size - 1){
        seq.push_back(term);
        possibleSequences.push_back(seq);
    }

    else{
        seq.push_back(term);
        i++;

        generateSequences(seq, 1, i, size);
        generateSequences(seq, 2, i, size);
    }
    

}

int main(){

    double N, M, K;

    std::cin >> N >> M >> K;

    //Number of possible samples
    double totalSamples = (N / 2) * (N + 1);

    //Ensure that a sequence is even possible before beginning
    if (K > totalSamples){
        std::cout << -1;
        return 0;
    }

    int size = pow(2, N);
    std::vector<int> e;
    generateSequences(e, 1, 0, N);
    generateSequences(e, 2, 0, N);

    

    for (int i = 0; i < size; i++){

        int x = 0, y = N, d = 0, good = 0;

        for (int j = 0; j < N; j++){

            for (int m = 0; m <= d; m++){

                std::set<int> subseq;

                for (int k = x + m; k < y + m; k++){
                    subseq.insert(possibleSequences[i][k]);
                }

                if (subseq.size() == y - x){
                    good += 1;
                }  

            }

            y -= 1;
            d += 1;

        }

        if (good == K){
            for (int j = 0; j < N; j++){
                std::cout << possibleSequences[i][j] << ' ';
            }

            return 0;
        }

    }

    std::cout << -1;

    return 0;

}