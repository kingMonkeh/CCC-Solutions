/*
2021 S5 Scrapped Solution
7/15 Marks
Brute Force, time complexity O(N^2)
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>

int main(){

    //Collect sequence length and number of requirements
    int N, M;
    std::cin >> N >> M;

    //Collect requirements and generate sequence at the same time
    //For storing the requirements:
    std::vector<int> X(M);
    std::vector<int> Y(M);
    std::vector<int> Z(M);

    //Prime factorization of 1 to 16:
    std::map<int, std::multiset<int>> primeFactorization;
    primeFactorization[1] = {1};
    primeFactorization[2] = {2};
    primeFactorization[3] = {3};
    primeFactorization[4] = {2, 2};
    primeFactorization[5] = {5};
    primeFactorization[6] = {2, 3};
    primeFactorization[7] = {7};
    primeFactorization[8] = {2, 2, 2};
    primeFactorization[9] = {3, 3};
    primeFactorization[10] = {2, 5};
    primeFactorization[11] = {11};
    primeFactorization[12] = {2, 2, 3};
    primeFactorization[13] = {13};
    primeFactorization[14] = {2, 7};
    primeFactorization[15] = {3, 5};
    primeFactorization[16] = {2, 2, 2, 2};

    //Storing factors
    std::vector< std::multiset<int> > factors(150001, {1});
    std::multiset<int> factor;

    for (int i = 0; i < M; i++){
        std::cin >> X[i] >> Y[i] >> Z[i];

        //Merge sets of prime factorizations to obtain LCM
        for (int a = X[i]; a <= Y[i]; a++){

            int count1, count2, diff;
            factor = primeFactorization[Z[i]];

            for (int z = 1; z <= 16; z++){
                count1 = factors[a].count(z);
                count2 = factor.count(z);
                diff = count2 - count1;

                if (diff > 0){

                    for (int y = 0; y < diff; y++){

                        factors[a].insert(z);

                    }
                    
                }
            }

        }

    }

    //Initialize and generate sequence
    std::vector<int> seq(150001, 1);
    int lcm;

    for (int i = 1; i <= N; i++){
        lcm = 1;

        for (std::multiset<int>::iterator it = factors[i].begin(); it != factors[i].end(); it++){
            lcm *= *it;
        }

        seq[i] = lcm;

    }

    //Check requirements
    bool valid = true;
    bool gcdfound = true;
    int min, gcd;
    for (int i = 0; i < M; i++){

        min = 200000000;

        for (int a = X[i]; a <= Y[i]; a++){
            if (seq[a] < min){
                min = seq[a];
            }
        }

        for (int m = min; m > 0; m--){

            gcdfound = true;

            for (int a = X[i]; a <= Y[i]; a++){
                if (seq[a] % m != 0){
                    gcdfound = false;
                    break;
                }
            }

            if (gcdfound == true){
                gcd = m;
                break;
            }
        }

        if (gcd != Z[i]){
            valid = false;
        }

    }

    if (valid == false){
        std::cout << "Impossible";
    }

    else{
        for (int i = 1; i <= N; i++){
            std::cout << seq[i] << ' ';
        }
    }

    return 0;
}