/*

2012 S3 - Absolutely Acidic

Difficulty: Easy/Medium

General idea:
As you collect the readings, keep track of the largest frequency and second largest frequency.
Using information collected, iterate over each reading and its frequencies, if it lines up with largest frequency or second largest frequency, put it in a container
Lastly, use if statements to navigate the tie breaker rules

*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

int main(){

    int N;
    std::cin >> N;

    std::vector<int> frequencies (1001, 0); //frequencies[i] represents how many times the reading i has occured

    int maxFrequency = 0, secondMaxFrequency = 0;

    std::set<int> mostFrequentReadings; //Store the readings with the highest frequency
    std::set<int> secondMostFrequentReadings; //Store the readings with the second highest frequency

    for (int i = 0; i < N; i++){

        int reading;
        std::cin >> reading;
        frequencies[reading]++;

        //Determine largest and second largest frequency
        if (frequencies[reading] > maxFrequency){
            maxFrequency = frequencies[reading];
        }

        else if (frequencies[reading] > secondMaxFrequency){
            secondMaxFrequency = frequencies[reading];
        }

    }
    
    //Since the readings can range from 1 to 1000
    for (int i = 1; i <= 1001; i++){

        //If reading has a frequency equal to the largest frequency
        if (frequencies[i] == maxFrequency){
            mostFrequentReadings.insert(i);
        }
        

        //If reading has a frequency equal to the second largest frequency
        if (frequencies[i] == secondMaxFrequency){
            secondMostFrequentReadings.insert(i);
        }
    }
    
    //If there are two or more readings with the highest frequency
    if (mostFrequentReadings.size() > 1){
        std::cout << std::abs(*mostFrequentReadings.rbegin() - *mostFrequentReadings.begin()); //Largest absolute difference would be between the max and min value of the set. Since the set is ordered, we just use begin and rbegin
    }
    
    //One reading with the highest frequency
    else{
        
        //Multiple values with second highest frequency
        if (secondMostFrequentReadings.size() > 1){
            //To find the largest possible absolute difference, imagine that the second most frequent readings form a number line. The reading with the largest frequency can be placed somewhere along this number line. Thus, the largest absolute difference must occur either by subtracting the min of the number of line or the maximum.
            int minDifference = std::abs(*mostFrequentReadings.begin() - *secondMostFrequentReadings.begin());
            int maxDifference = std::abs(*mostFrequentReadings.begin() - *secondMostFrequentReadings.rbegin());
            std::cout << std::max(minDifference, maxDifference);
        }
        
        //One reading with second highest frequency
        else{
            std::cout << std::abs(*mostFrequentReadings.begin() - *secondMostFrequentReadings.begin());
        }
        
    }
    
    return 0;

}