/*

2013 J5/S3 - Chances of Winning

Difficulty: Easy

This question doesn't require any special algorithm.
To solve, you can quite literaly just generate every possible scenario and count each one.
I will be doing this via recursion

*/

#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> gamesToPlay; //Games to be played, each pair <i, j> indicates i and j must play a game together
std::vector<int> score (5, 0); //Keep track of score, note that 1 indexing so there's a filler number at the beginning
int possibilities = 0; //Answer, number of possibilites
int remainingGames; //Remaining games needed to be played
int T, G;

//Recurse through all posibilites
void future (char result, int gameNumber = 1){

    //If all games have been completed, note that my recursion is quite inefficient and accidentally duplicates 3 times since i call the function 3 times each recurse, therefore i will divide my answer by 3 at the end
    if (gameNumber > remainingGames){

        bool winner = true; //If team T has won

        for (int i = 1; i <= 4; i++){
            //Remember that team T must have the highest score, ties are not allowed
            if (score[i] >= score[T] && i != T){
                winner = false;
            }
        }

        if (winner == true){
            possibilities++;
        }

    }

    else{

        //Remember to undo changes after recursing

        //if i have the pair <a, b>, if team a wins
        if (result == 'a'){
            score[gamesToPlay[gameNumber - 1].first] += 3;
            future('a', gameNumber + 1);
            future('b', gameNumber + 1);
            future('t', gameNumber + 1);
            score[gamesToPlay[gameNumber - 1].first] -= 3;
        }

        //If team b wins
        else if (result == 'b'){
            score[gamesToPlay[gameNumber - 1].second] += 3;
            future('a', gameNumber + 1);
            future('b', gameNumber + 1);
            future('t', gameNumber + 1);
            score[gamesToPlay[gameNumber - 1].second] -= 3;
        }

        //If they tie, that's what 't' stands for
        else{
            score[gamesToPlay[gameNumber - 1].first]++;
            score[gamesToPlay[gameNumber - 1].second]++;
            future('a', gameNumber + 1);
            future('b', gameNumber + 1);
            future('t', gameNumber + 1);
            score[gamesToPlay[gameNumber - 1].first]--;
            score[gamesToPlay[gameNumber - 1].second]--;
        }

    }

}

int main(){

    std::cin >> T >> G;

    std::vector<std::vector<bool>> played (5, std::vector<bool> (5, false)); //Determine which teams have already played each other
    
    for (int i = 0; i < G; i++){

        int teamA, teamB, scoreA, scoreB;

        std::cin >> teamA >> teamB >> scoreA >> scoreB;

        played[teamA][teamB] = true;
        played[teamB][teamA] = true; //2-D list moment, just marking it true on the other end as well

        //If team a wins
        if (scoreA > scoreB){
            score[teamA] += 3;
        }

        //If they tie
        else if (scoreA == scoreB){
            score[teamA]++;
            score[teamB]++;
        }

        //If team b wins
        else{
            score[teamB] += 3;
        }

    }

    //Determine which games have yet to play
    for (int i = 1; i <= 4; i++){

        for (int j = 1; j <= 4; j++){

            //i cannot be equal to j because a team cannot play itself
            if (played[i][j] == false && i != j){

                gamesToPlay.push_back(std::make_pair(i, j));
                played[i][j] = true;
                played[j][i] = true; //Since this is a 2-D list, i need to make sure [j][i] are also marked as true

            }

        }

    }

    remainingGames = gamesToPlay.size(); //Obtain remaining games

    future('a');
    future('b');
    future('t');

    std::cout << possibilities / 3;

    return 0;

}