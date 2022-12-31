/*
Difficuly: Easy/Medium

Subtasks 1 to 3 can all be brute forced, a.k.a traverse the entire canvas via 2-D list and swap black and gold with each instruction

For subtask 4, the input is greatly increased. Thus, we must optimize subtasks 1 to 3. To do this, a key realization must be made.
Note that the amount of times an index on the canvas has been painted over tells us whether it's gold or black.
For example if its been painted over once B -> G, if it's been painted over twice, B -> G -> B, here we note a pattern that if it has been painted over an even amount of times, it's black. If odd, then gold
Now to know how many times a cell has been painted over without constantly updating the canvas, we note that all cells in a particular row or column get painted over.
Therefore it's only important to note how many times the entire row or column was painted since index [i][j] on our canvas has been painted over by the number of paints over row[i] + the number of paints over column[j]
*/

#include <iostream>
#include <vector>

int main(){
    
    //Collect input
    int M, N, K;

    std::cin >> M >> N >> K;

    //Initialize vectors containing information as to how many times row[i] or column[i] has been painted over
    std::vector<int> row(M + 1, 0);
    std::vector<int> column(N + 1, 0);

    char instruction; //Storing whether the painter chooses a row or a column
    int num; //Storing row or column number

    for (int i = 0; i < K; i++){
        
        std::cin >> instruction >> num;

        if (instruction == 'R'){

            row[num] += 1;

        }

        else{

            column[num] += 1;

        }

    }

    //Calculate number of gold cells
    int gold = 0;
    for (int i = 1; i <= M; i++){

        for (int j = 1; j <= N; j++){

            //The number of times a cell has been painted over is the number of times its row and column have been painted together
            if ( (row[i] + column[j]) % 2 == 1 ){
                gold += 1;
            }

        }

    }

    std::cout << gold;

    return 0; 
}