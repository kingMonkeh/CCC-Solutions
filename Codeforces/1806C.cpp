/*

Basically note, if n == 1, then both elements in q must be the same
therefore answer is just the diff between the 2 numbers in p

If n == 2, try 2, 2, 2, 2 for q

Afterward notice that you can construct an array q
by putting a bunch of -1's and then for the final element, you can place n
For example
-1 -1 -1 -1 -1 -1 -1 4
Notice that this only works when n % 2 == 0 since the -1's multiply to become positive
Only when an even amount of -1's are present, otherwise they become negative

Lastly, notice that if none of the above work
Then you can always just do
0 0 0 0 0 0 0 0
Since this will always be a good sequence

*/


#include <iostream>
#include <algorithm>

long long p[400000];

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        int n;
        std::cin >> n;
        long long ans = 0; //Assuming everything is 0 in q
        long long sum = 0; //Assume everything is -1 in q initially
        for (int i = 0; i < 2 * n; i++){
            std::cin >> p[i];
            ans += llabs(p[i]);
            sum += llabs(p[i] - (-1));
        }
        if (n == 1){
            std::cout << llabs(p[0] - p[1]) << '\n';
            continue;
        }
        if (n == 2){
            ans = std::min(ans, llabs(p[0] - 2) + llabs(p[1] - 2) + llabs(p[2] - 2) + llabs(p[3] - 2));
        }
        if (n % 2 == 0){
            for (int i = 0; i < 2 * n; i++){
                ans = std::min(ans, sum - llabs(p[i] - (-1)) + llabs(p[i] - n));
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}