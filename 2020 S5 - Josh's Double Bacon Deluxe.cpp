/*

2020 S5 - Josh's Double Bacon Deluxe

Difficulty: Hard

This problem was quite difficult for me, although the solution is very short

Basically, the coach has three possibilities:
1. He picks his own burger, everyone's happy
2. He picks someone elses burger, someone gets disrupted
3. He takes Josh's burger, Josh is guranteed to not get his burger

Key insight #1:
Only the last guy of a burger type can get disrupted/lose his burger
This is because, imagine some guy takes your burger
The first person with your burger type has lost their burger
So instead, they take a burger from the next person after them who was supposed to get your burger type as well
Then for this next person, since the first person stole theirs, they steal from the next,
This continues until you reach the last person of this burger type, in which the person before them took their burger, but now there's no one after them to take from
Therefore, they've been scammed

Key insight #2:
No matter how the last person of a burger type loses their burger
The remaining burger types that they can choose from will always be the same
To see this clearly, I recommend reading:
https://ccc.amorim.ca/docs/2020/s5/    (key insight #2, since this was something that helped me solve the problem)

Using these 2 facts, we will iterate starting from the 2nd last person all the way to the coach
Using a DP array to memoize the solutions to each subproblem

*/

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

int main(){

    int N;
    std::cin >> N;

    //Get burgers
    std::vector<int> burgers (N);

    for (int i = 0; i < N; i++){
        std::cin >> burgers[i];
    }

    std::vector<long double> DP (N, 0); //DP array, DP[i] tells us the probability (out of 1) if person i gets their burger stolen by the coach, init with 0 for Josh
    std::map<int, int> last; //last[i] tells us the index of the last person to hold burger type i
    last[burgers[N - 1]] = N - 1; //Map Josh's burger to himself, since if the coach takes anyone's burger who has the same type as Josh, Josh will be disrupted, meaning 0 chance

    long double totalProbability = 0.0; //Total probability of Josh getting his burger, for all people after the current person
    
    //Special edge case, if the coach has the same burger as Josh, it's guranteed Josh will get his burger
    if (burgers[0] == burgers[N - 1]){
        std::cout << 1;
        return 0;
    }

    //Start from 2nd last person, iterate backwards until we reach coach
    for (int i = N - 2; i >= 0; i--){

        //If they have the same burger type as coach, then if coach takes their burger, Josh is still guranteed to get his, therefore 1/1 chance
        if (burgers[i] == burgers[0]){
            DP[i] = 1.0;
        }

        //If we've already calculated this before, use memoized result
        //If they have Josh's burger, we return 0 
        else if (last[burgers[i]]){
            DP[i] = DP[last[burgers[i]]];
        }

        //Otherwise, we've reached the last person of this burger type and they're not coach or josh burger type
        else{
            //This may be very confusing, I will try my best to explain the formula
            //Basically, if coach takes this persons burger, 3 things can happen
            //1. They take coach's burger, everything returns to normal
            //2. They disrupt someone else, more problems
            //3. They steal josh's burger, Josh will never get his
            //In this formula, the 1 stands for if the person takes the coach's burger, we divide this by N - i, since there are N - i burgers for a person to choose from
            //totalProbability is the most confusing here
            //If a person disrupts another person, the probability of Josh getting his burger is (memoized solution of this person)/(N-i or also known as # of burgers remaining to choose from)
            //You would technically repeat this for every person that this person can disrupt, and add them together
            //But if you remember fraction rules, fractions with the same denominator can be combined, that's why we use totalProbability to represent all of the possibilities combined and divide it by N - i
            DP[i] = (1 + totalProbability) / (N - i);
        }

        totalProbability += DP[i];

        //If this person is the last holder for the burger type, add them to map
        if (!last[burgers[i]]){
            last[burgers[i]] = i;
        }

    }

    //Output answer, with good precision
    std::cout << std::setprecision(8) << totalProbability / N;

    return 0;

}