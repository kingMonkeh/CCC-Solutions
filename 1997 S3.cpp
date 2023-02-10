/*

1997 S3 - Double Knockout Competition

Difficulty: Very Easy

This problem is quite easy. For each round, get the total number of matchest between undefeated teams, only half the teams will lose, so subtract them from undefeated and add them to one-loss.
For the one-loss teams, do the same thing, add to defeated and subtract from one-loss. Keep repeating this until you reach the special round.
Afterwards, you can hardcode the end.

*/

#include <iostream>

int main(){
    
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++){
        
        int t;
        std::cin >> t;
        
        //Initial statement
        std::cout << "Round 0: " << t << " undefeated, 0 one-loss, 0 eliminated" << '\n';

        int undefeated = t, oneloss = 0, eliminated = 0;
        int round = 1;
    
        //Keep looping until special round
        while (undefeated > 1 || oneloss > 1){
    
            int losers, eliminate;
            losers = undefeated / 2; //Number of undefeated teams that will lose
            eliminate = oneloss / 2; //Number of one-loss teams that will be eliminated
    
            undefeated -= losers;
            oneloss += losers;
            oneloss -= eliminate;
            eliminated += eliminate;
    
            //Output info
            std::cout << "Round " << round << ": " << undefeated << " undefeated, " << oneloss << " one-loss, " << eliminated << " eliminated" << '\n'; 
    
            round++;
    
        }
    
        //Hardcode the rest
        undefeated -= 1; oneloss += 1;
    
        std::cout << "Round " << round << ": " << undefeated << " undefeated, " << oneloss << " one-loss, " << eliminated << " eliminated" << '\n'; 
    
        round++;
        oneloss -= 1;
        eliminated++;
    
        std::cout << "Round " << round << ": " << undefeated << " undefeated, " << oneloss << " one-loss, " << eliminated << " eliminated" << '\n'; 
        
        std::cout << "There are " << round << " rounds." << '\n'; //Remember to terminate with new line, if you don't you will get presentation error.
        
    }

    return 0;
    
}
