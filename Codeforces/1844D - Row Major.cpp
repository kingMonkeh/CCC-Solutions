#include <bits/stdc++.h>

/*

All possible grid sizes of r * c, can just be viewed as all possible factor pairs of n

essentially for a given grid (r, c)
a string will be valid if, a character does not repeat every r characters from its previous position

Next up, we note something interest
given the factor pairs of a number n, lets take 6 for example
factor pairs are:
{1, 6}
{2, 3}
{3, 2}
{6, 1}

we only care about the r's though, so we can reduce that to
1 2 3 6

we note that the number of  distinct characters required is the first number that is not a factor of n
this is because by saying the factor are 1 2 3 6
we're saying that once we place down a character x
we cannot repeat x 1 character, 2 characters, 3 characters, or 6 characters after
but notice the gap between 3 and 6, it's fine if we place x again here, and so we can reapply this exact same logic starting at this new x

therefore, the moment a gap appears in the factors, we can place down the character again, meaning the min # of distinct = first factor that is not a factor of n

we note that factorizing can be done in linear time so O(n)

important question: is it possible that a string will have more than 26 unique characters, aka the max we can hold?

answer: no

if a string has more than 26 unique characters, that means it has the factors {1, 2, ..., 26}
by this logic the number must be atleast 26! (! here means factorial)

which is far bigger than 100 000 which n is constrained to, therefore we do not need to worry about this

*/

std::string letters = "abcdefghijklmnopqrstuvwxyz";

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;

        std::vector<int> factors;

        for (int i = 1; i < n; i++){
            if (n % i == 0){
                factors.push_back(i);
            }
        }

        std::string pattern = "";
        std::string ans = "";

        int prev_factor = 1;
        int distinct = 2;
        for (int i = 1; i < (int) factors.size(); i++){
            if (factors[i] != prev_factor + 1){
                break;
            }
            else{
                prev_factor++;
                distinct++;
            }
        }

        for (int i = 0, j = 0; i < n; i++, j++){
            std::cout << letters[j % distinct];
        } std::cout << '\n';
        
    }
    
    return 0;
    
}