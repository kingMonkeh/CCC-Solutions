/*
ID:
TASK: friday
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>

/*

Main idea: Just loop through every month of every year one by one, there is at max 4800 months to loop through

*/

int main(){

    std::ifstream input ("friday.in");
    std::ofstream output ("friday.out");

    int N;
    input >> N;

    int year = 1900;
    int month = 1;
    int dayofweek = 6; //1 = monday, 2 = tuesday, 3 = wednsday, ...

    std::vector<int> frequency (8, 0);
    frequency[dayofweek]++;

    while (year < 1900 + N){

        //30 day months
        if (month == 9 || month == 4 || month == 6 || month == 11){
            dayofweek += 30 % 7;
        }

        //31 day months
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            dayofweek += 31 % 7;
        }

        //Centuries, special case
        else if (month == 2 && year % 100 == 0){

            //400 year rule
            if (year % 400 == 0){
                dayofweek += 29 % 7;
            }

            //Not a leap year
            else{
                dayofweek += 28 % 7;
            }

        }

        //Leap years
        else if (month == 2 && year % 4 == 0){
            dayofweek += 29 % 7;
        }

        //Non leap years
        else{
            dayofweek += 28 % 7;
        }

        if (dayofweek > 7){
            dayofweek %= 7;
        }

        frequency[dayofweek]++; //Increase frequency

        month++;
        
        //Update year accordingly
        if (month == 13){
            month = 1;
            year++;
        }

    }

    frequency[dayofweek]--; //We count an extra month because of the way the loop has been implemented

    output << frequency[6] << ' ' << frequency[7] << ' ' << frequency[1] << ' ' << frequency[2] << ' ' << frequency[3] << ' ' << frequency[4] << ' ' << frequency[5] << '\n';

    return 0;

}