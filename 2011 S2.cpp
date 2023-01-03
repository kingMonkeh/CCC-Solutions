/*

2011 S2 - Multiple Choice

Difficulty: Very Easy

Ad Hoc Problem

Store student answers and correct answers in seperate arrays. Compare the two arrays and count the total number of matching elements.

*/

#include <iostream>
#include <vector>

int main(){

    int N;

    std::cin >> N;

    std::vector<char> student_answers (N), correct_answers (N); //For storing the answers

    //Collecting student answers
    for (int i = 0; i < N; i++){
        std::cin >> student_answers[i];
    }

    //Collecting the correct test answers
    for (int i = 0; i < N; i++){
        std::cin >> correct_answers[i];
    }

    int score = 0; //Keep track of how many correct answers the student has

    //Check if the student answered correctly
    for (int i = 0; i < N; i++){

        if (student_answers[i] == correct_answers[i]){
            score++;
        }

    }

    //Output student score
    std::cout << score << std::endl;

    return 0;

}