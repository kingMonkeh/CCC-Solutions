/*

2022 S3 Good Samples

Difficulty: Medium

Ad Hoc Problem, Greedy

Subtask 1:
You could have done a complete search, generating every possible sequence and then searching all subsequences to determine if a valid sequence existed

Subtask 2:
Complete search is very inefficient given our input size of 1 000 000. Therefore we must improve our algorithm.
Note that the minimum number of good samples a piece has is N since each sample of length 1 is unique
Therefore we must ensure that there are K - N other good samples of length 2 or greater
Key realization: if M = 2, the largest possible good sample is of length 2 a.k.a (1, 2) or (2, 1)
Therefore, start out by placing a filler number for piece[0], either 1 or 2 and then if you still need more good samples, insert the opposite number.
Otherwise, insert the same number as the previous index.

Subtask 3 + 4:
For subtask 3, we must expand on our idea from subtask 2.
Note that each time we add a distinct number for the first time, it creates its index - 1 good samples
For example adding 2 to the piece 1 creates the sequence 1 2. We note that 1 good sample has been created (Remember that samples of length 1 are already accounted for).

Now what if we add a number that already exists in the piece once again?
Consider the piece 1 2 3 4
If we add 2, we get 1 2 3 4 2
We note that 2 good samples have been created (3 4 2) and (4 2)
Now if we add 1 to this new sequence, we get 1 2 3 4 2 1
We note that 4 good samples have been created (2 3 4 2 1), (3 4 2 1), (4 2 1) and (2 1)

From this, we can see that if an already present number is added once again, the number of good samples created is the difference between their indices - 1 (i1 - i2 - 1 = # of good samples created where i1 is current index, i2 is previous occurence of number)

FINAL TIP: Remember that K can surpass the integer limit, therefore it's advised to use larger data types such as double

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    
    //Collect input
    double N, M, K;

    std::cin >> N >> M >> K;

    std::vector<int> seq (N, 0); //For storing the sequence, I initialize with 0's so that I can perform std::find later
    seq[0] = 1; //Initiate first element in sequence to 1, 1 is a very safe number since it's always guranteed to work
    K -= N; //Accounting for all good samples of length 1 which is equal to N

    
    //Adding DISTINCT numbers to our piece, i < M since pitch cannot surpass M, i = 1 since we've already made seq[0] = 1
    for (int i = 1; i < M; i++){

        //To make sure we don't create too many good samples and to ensure we're producing N notes
        if (K - i >= 0 && i < N){
            seq[i] = i + 1; //Because of 0 indexing
            K -= i;
        }

        //If we can't add anymore distinct numbers, exit the loop
        else{
            break;
        }

    }

    int checkpoint; //To know which index we left off at to see if it's still possible to continue generating
    auto it = std::find(seq.begin(), seq.end(), 0);

    if (it != seq.end()){
        checkpoint = it - seq.begin();
    }
    
    else{
        checkpoint = N;
    }

    //After adding distinct numbers, we will generate the remainder of the sequence, starting off at checkpoint
    for (int i = checkpoint; i < N; i++){
        
        //If we still need to create more good samples
        if (K > 0){

            //j = M, since we can only go M notes back
            for (int j = M; j > 0; j--){

                if (K - j + 1 >= 0){
                    seq[i] = seq[i - j];
                    K -= (j - 1);
                    break;
                }

            }

        }

        //Otherwise just put filler numbers if K has already been satisfied
        else{
            seq[i] = seq[i - 1];
        }

    }

    //If exactly K good samples have been created:
    if (K == 0){
        for (int i = 0; i < N; i++){
            std::cout << seq[i] << ' ';
        }
    }

    //No piece exists
    else{
        std::cout << -1;
    }

    return 0;

}