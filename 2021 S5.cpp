#include <iostream>
#include <vector>

/*
This is my scrapped solution for 2021 S5
The goal of this solution was to only get 3 marks since the GCD would only be 1 and 2
The idea is that for the subsequence to have GCD 2, all of its terms have to be 2
If the GCD is 1, then there must be a single instance of 1, more than one instance is fine but there must be at least one 1

Thus our algorithm was to make a list of 1's and change indices X to Y equal to 2 if Z = 2
Afterwards we just check if each requirement still works according to the rules above

If all requirements are satisfied we output the sequence
Otherwise we output Impossible
*/

int main(){
    //Collect Inputs
    int N, M;
    std::cin >> N >> M;

    //Collect requirements
    std::vector<int> X(M);
    std::vector<int> Y(M);
    std::vector<int> Z(M);

    std::vector<int> divisors[150001];

    for (int i = 0; i < M; i++){
        std::cin >> X[i] >> Y[i] >> Z[i];

        for (int a = X[i]; a <= Y[i]; a++){
            divisors[a].push_back(Z[i]);
        }

    }

    //Initialize sequence
    std::vector<int> seq(N+1, 1); 

    for (int i = 1; i <= N; i++){
        //Something
    }

    bool valid = true;
    for (int i = 0; i < M; i++){

        for (int a = X[i]; a <= Y[i]; a++){
            //something
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