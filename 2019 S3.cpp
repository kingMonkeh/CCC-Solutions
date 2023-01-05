/*

Difficulty: Medium-Hard

CCC Grader - 15/15 Marks
DMOJ - 16/16 Marks

Key realizations:
If there are 3 X's or less, you can mathematically solve for each X using knowledge of arithmetic sequences.
As long as you know the value of 2 numbers in any row or column, you can always calculate the third term.
If there's 9 X's, you can output a square of all the same number, with the common difference between all terms being 0.
If there's 8 X's, you can set all the X's in the square equal to the given value, common difference = 0 as well.

If the number of X's is between 4 and 7, things become a bit tricky since some possible square arrangements, prevent us from calculating all X's using only the given numbers of math.
For these situations, we must randomly fill in some X's following the rule of arithmetic sequences, and then attempt to fill in the remaining X's under our assumption.

I have chosen to do the RNG method. But another completely valid method involves breaking down the problem case by case and using knowledge of matrices to solve it.
I recommend reading the DMOJ editorial if you're interested in this solution.

As for what I'm implementing:
1. Collect Input, fill out square and also create a back up square
2. If X >= 8, output square using idea mentioned above.
3. Otherwise, we will attempt to fill in the square to the best of our ability using only math
4. If the square is complete, output it, otherwise, begin randomly filling X's and attempting to fill in the remaining X's
5. Repeat this step using different numbers until a valid square is found.

This question is difficult if you're not just greedily throwing in random numbers hoping you'll get the right answer.

I hate this question mainly because I wasted 2 hours trying to fix a bug in my code that was the result of me accidentally right i instead of j in a for loop

I do want to give credit to Kytabyte and his solution since mine is based off of it.

*/

#include <iostream>
#include <vector>
#include <string>

//Defining X so that I don't have to type it out over and over and over. Note that you can choose other values, just make sure its out of input range.
#define X -1000001

int some_num; //Some_num represent the random number that I will be using to fill out X's in worst case scenario.

std::vector< std::vector<int> > square (3, std::vector<int> (3)); //Square
std::vector< std::vector<int> > backup_square (3, std::vector<int> (3)); //Backup square, in case I need to reset changes

//Function to check if the square is full
bool complete () {

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (square[i][j] == X){
                return false;
            }
        }
    }

    return true;

}

//Function to check if a square is valid
bool correct () {

    for (int i = 0; i < 3; i++){
        //Check differences between terms and make sure they're the same
        if (square[i][1] - square[i][0] != square[i][2] - square[i][1]){
            return false;
        }
    }

    for (int j = 0; j < 3; j++){
        if (square[0][j] - square[1][j] != square[1][j] - square[2][j]){
            return false;
        }
    }

    return true;

}

//Function to actually solve the given square
bool solve () {

    bool changed = true; // Keep track if square has been updated as we fill it out, it may be the case that we cannot solve for X initially until we have solved for another X.

    std::vector<std::vector<int>> affected (3, {0, 0, 0}); // Keep track of what changes have been made in this instance of solve, we will be calling recursively

    while (!correct() && changed){

        changed = false;

        //Solve for X in a row if enough information is found in a row
        for (int i = 0; i < 3; i++){

            int numbers = 0; //Represent the number of actual numbers present in the row

            for (int j = 0; j < 3; j++){

                if (square[i][j] != X){
                    numbers++;
                }

            }

            //We can only solve for X if know 2 other numbers in the row
            if (numbers == 2){

                changed = true;
                
                //If X is on the left
                if (square[i][0] == X){
                    square[i][0] = square[i][1] * 2 - square[i][2];
                    affected[i][0] = 1;
                }

                //If in the middle
                else if (square[i][1] == X){
                    square[i][1] = (square[i][0] + square[i][2]) / 2;
                    affected[i][1] = 1;
                }

                //If on the right
                else{
                    square[i][2] = square[i][1] * 2 - square[i][0];
                    affected[i][2] = 1;
                }

            }

        }

        //Solving by column now
        //Solve for X if enough information is found in its column
        for (int j = 0; j < 3; j++){

            int numbers = 0; //Same idea as before

            for (int i = 0; i < 3; i++){

                if (square[i][j] != X){
                    numbers++;
                }

            }

            if (numbers == 2){

                changed = true;

                //If X is at the top
                if (square[0][j] == X){
                    square[0][j] = square[1][j] * 2 - square[2][j];
                    affected[0][j] = 1;
                }

                //If X is in the middle
                else if (square[1][j] == X){
                    square[1][j] = (square[0][j] + square[2][j]) / 2;
                    affected[1][j] = 1;
                }

                //If X is on the bottom
                else{
                    square[2][j] = square[1][j] * 2 - square[0][j];
                    affected[2][j] = 1;
                }

            }

        }

    }

    //Check if we have solved it
    if (correct()){
        return true;
    }

    //If it's not solved but it's full, it means it's not a valid square, therefore we must undo our changes
    if (complete()){

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){

                if (affected[i][j]){
                    square[i][j] = X;
                }

            }
        }

        return false;

    }

    //If after using math, we still have not completed the square.

    /*
    After filling in the X values that we could, there still may be X values that we couldn't solve for
    For example, imagine the square
    8 X X
    X X X
    X X 20
    We cannot solve for any X mathematically since there's not enough information in any role or column.
    This means we must try filling out a row randomly and then try to fill that square and check if it's solved.
    This is the reason why a Random Number Generator solution can in fact work for this question with enough attempts.
    */

    //For each row
    for (int i = 0; i < 3; i++){

        bool to_fill = false; //Used to determine if there are X's in this row that need to be filled randomly
        int number_index = -1; //Used to determine the index of the actual number in the row

        for (int j = 0; j < 3; j++){

            if (square[i][j] != X){
                number_index = j;
            }

            else{
                to_fill = true;
            }

        }

        //If we need to fill the row and we have knowledge of at least 1 number in the row
        if (to_fill && number_index != -1){

            //If the known number is on the left
            if (number_index == 0){

                square[i][1] = square[i][0] + some_num; //You can see some_num being used as the common difference of the sequence
                square[i][2] = square[i][1] + some_num;

                //After randomly filling out a portion of the square, we recursively call the function to fill the square and see if it's valid
                if (solve()){
                    return true;
                }

            }

            //If in the middle
            else if (number_index == 1){

                square[i][0] = square[i][1] - some_num;
                square[i][2] = square[i][1] + some_num;

                if (solve()){
                    return true;
                }

            }

            //If on the right
            else{
                square[i][1] = square[i][2] - some_num;
                square[i][0] = square[i][1] - some_num;

                if (solve()){
                    return true;
                }

            }

        }

    }

    //Fill columns now
    for (int j = 0; j < 3; j++){
        
        bool to_fill = false; //Same idea as before
        int number_index = -1;

        for (int i = 0; i < 3; i++){

            if (square[i][j] != X){
                number_index = i;
            }

            else{
                to_fill = true;
            }

        }

        if (number_index != -1 && to_fill){

            //If the numer is on the top
            if (number_index == 0){

                square[1][j] = square[0][j] + some_num;
                square[2][j] = square[1][j] + some_num;

                if (solve()){
                    return true;
                }

            }

            //If the number is in the middle
            else if (number_index == 1){

                square[0][j] = square[1][j] - some_num;
                square[2][j] = square[1][j] + some_num;

                if (solve()){
                    return true;
                }

            }

            //If on the bottom
            else{

                square[1][j] = square[2][j] - some_num;
                square[0][j] = square[1][j] - some_num;

                if (solve()){
                    return true;
                }

            }

        }

    }

    //If it's the case that after randomly filling out the square and solving it, that we're still unable to find a solution, we must undo our changes.

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (affected[i][j]) {
                square[i][j] = X;
            }
        }
    }

    return false;

}

int main(){

    int x = 0, num = 0; //x represents the number of X's in a square, num represents a number in the square. Num will be used if x == 8

    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){

            std::string input; //Take input as string since it can be X
            std::cin >> input;

            //If X, put in our filler number
            if (input == "X"){
                square[i][j] = X;
                backup_square[i][j] = X; //Update backup square
                x++;
            }

            //Otherwise
            else{
                square[i][j] = std::stoi(input); //stoi converts string to int, very useful in our case
                backup_square[i][j] = std::stoi(input); //Update backup square
                num = square[i][j];
            }

        }

    } 

    //Special case that I've already explained
    if (x >= 8){

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                std::cout << num << ' ';
            }
            std::cout << std::endl;
        }

    }

    else{

        //I will be linearly changing some_num and testing to see if it can generate a valid sequence
        for (int i = 0; i < 50; i++){
            some_num = i;

            //Attempt to solve, if it works, output the square
            if(solve()){

                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        std::cout << square[i][j] << ' ';
                    }
                    std::cout << std::endl;
                }

                return 0;

            }

            //If it has failed, we must reset the square originally, change our value of some_num and try again
            //Interestingly, I have noted that most problem can be solved when some_num == 0 or 1
            else{

                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        square[i][j] = backup_square[i][j];
                    }
                }

            }

        }

    }

    return 0;

}