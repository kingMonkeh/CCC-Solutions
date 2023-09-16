#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*

Observations:

if S starts with B and N > 2, you can do BAAAAAA...AB

if S starts with A and does not end with A, we cannot do anything since we can't change the first element or the last element

Heres our proof that everything else will work
If the string starts with A, and ends with A
We can view the substring excluding those two A's as the new string and keep trying

A______A becomes ______

We notice that regardless of what ______ looks like, its always solvable

If it starts with B, refer to observation 1

If it starts with A,

Ends with A, recurse deeper

Ends with B, Since this A is no longer technically the first element and the previous element is guranteed to be A
We can use the AB operation to convert this into B, and then since we start with B, we can always solve

AA____BA
AB____BA
Always solvable

*/

int main (){

    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    if (N == 2){
        if (S[0] == S[1]){
            std::cout << "Yes\n";
            return 0;
        }
        else{
            std::cout << "No\n";
            return 0;
        }
    }
    
    if (S[0] == 'A' && S[N - 1] == 'B'){
        std::cout << "No\n";
    }
    else std::cout << "Yes\n";

    return 0;
    
}