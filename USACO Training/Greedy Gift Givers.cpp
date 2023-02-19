/*
ID: 
TASK: gift1
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

int main(){

    std::ofstream output ("gift1.out");
    std::ifstream input ("gift1.in");

    int NP;
    input >> NP;

    std::map<std::string, int> money; //money[name] tells us the the amount of money this person has
    std::vector<std::string> people (NP); //store the names in the order they were inputted so we can output them later

    for (int i = 0; i < NP; i++){

        std::string person;
        input >> person;
        money[person] = 0; //default to 0, as stated in problem
        people[i] = person;

    }

    //For each person
    for (int p = 0; p < NP; p++){

        std::string gifter; //Person who's giving money
        input >> gifter;

        int total, numOfPeople, gift = 0, takeback = 0; //Total money they're giving, number of people, gift for each person, takeback
        input >> total >> numOfPeople;

        //We don't want to calculate if numOfPeople == 0 since you can't divide by 0
        if (numOfPeople != 0){
            gift = total / numOfPeople; //Amount for each person
            takeback = total % numOfPeople; //Leftover money
        }

        for (int i = 0; i < numOfPeople; i++){

            std::string receiver;
            input >> receiver;

            money[receiver] += gift; //Add money to each receiver's account

        }

        money[gifter] -= total; //Take away money from gifter's account
        money[gifter] += takeback; //Add back leftover

    }

    for (int i = 0; i < NP; i++){

        output << people[i] << " " << money[people[i]] << '\n'; //Output people in order

    }

    return 0;

}