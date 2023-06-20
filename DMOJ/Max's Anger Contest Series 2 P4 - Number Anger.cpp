/*

a a a aa a a a ahahaha 6-D DP array so funny
ahahahahahahahahahahahahahhahahahahaha

I fucking hate dp

basic idea:
view R as string
basically recursively construct every possible number up to R

What are the parameters we need to have for our function?
-the index we're currently at (obvious)
-the current digit we're adding (obvious)
-whether we're still adding leading zeros (not as obvious, but still logical)
-if we're matching R still (not as obvious, but important in determining what digits can be added to the string)
-current number of consecutive digits (more efficient than manually checking at the end)
-whether or not D consecutive digits have already been made (seems a bit redundant at first, but it's useful)


*/

#include <iostream>
#include <string>
#include <string.h>

#define ll long long

//Memoize, based off of the 6 states we listed above
//DP[index][has D consecutive digits][if still leading zero][if equal to R exactly][consecutive digits so far][current digit]
ll DP[19][2][2][2][19][10];
std::string R;
ll D;

ll solve (int index, bool d_consec, bool started, bool equalR, int consec_count, int cur_digit){

    //Base case, we have made a string of the correct length, return whether it contained D consecutive digits or not
    if (index == R.length()){
        return d_consec;
    }

    //Try using memoized result
    ll& ans = DP[index][d_consec][started][equalR][consec_count][cur_digit];

    if (ans != -1){
        return ans;
    }
    
    //Otherwise, solve manually
    ans = 0;
    int limit;
    if (equalR) limit = R[index] - '0';
    else limit = 9;
    //For each digit
    for (int dig = 0; dig <= limit; dig++){
        //Check if D consecutive digits yet
        bool next_d_consec;
        if (started){
            //if already d_consec, then it stays the same, otherwise if we just hit exactly D consecutive digits with the addition of this digit, then also true
            next_d_consec = d_consec || ((consec_count + (dig == cur_digit)) == D); 
        }
        //If still leading zeros, then we can't count D digits yet
        else{
            //Edge case, D = 1, then any dig != 0 will count as D consecutive digits
            if (dig != 0 && D == 1){
                next_d_consec = true;
            }
            else{
                next_d_consec = false;
            }
        }
        //Check if still leading zero
        bool still_leading = started || dig != 0;
        //Check if we're still equal to R, this helps us limit what numbers we recurse to
        bool still_equal = equalR && (dig == R[index] - '0');
        //Count number of consecutive digits so far
        int next_consec_count;
        if (started){
            //Streak continues
            if (dig == cur_digit){
                next_consec_count = consec_count + 1;
            }
            //New digit, streak resets
            else{
                next_consec_count = 1;
            }
        }
        //If we haven't started, then either we begin a streak, or don't start yet
        else{
            if (dig != 0){
                next_consec_count = 1;
            }
            else{
                next_consec_count = 0;
            }
        }
        //Recurse deeper :)
        ans += solve(index + 1, next_d_consec, still_leading, still_equal, next_consec_count, dig);
    }
    return ans;
}

int main(){
    std::cin >> R >> D;
    memset(DP, -1, sizeof(DP));
    std::cout << solve(0, false, false, true, 0, 0) << '\n';
    return 0;
}