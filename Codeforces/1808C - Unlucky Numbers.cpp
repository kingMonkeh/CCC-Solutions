#include <bits/stdc++.h>

//find luck of number x
long long luck (long long x){
    long long mx = 0, mn = 10;
    while (x){
        mx = std::max(mx, x % 10);
        mn = std::min(mn, x % 10);
        x /= 10;
    }
    return mx - mn;
}

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        long long l, r;
        std::cin >> l >> r;

        std::string a = std::to_string(l), b = std::to_string(r);

        //if theyre not the same amount of digits, you can always just output 99999... this is guranteed 0 luck
        if (a.size() != b.size()){
            for (int i = 0; i < a.size(); i++) std::cout << 9;
            std::cout << '\n';
            continue;
        }

        //if theyre the same, the answer is obvious
        else if (l == r){
            std::cout << l << '\n';
            continue;
        }

        int bestluck = 10; //best luck so far
        long long base = 0; //common prefix of both l and r
        long long ans; //our actual answer
        for (int i = 0; i < a.size(); i++){
            //common prefix
            if (a[i] == b[i]){
                base = base * 10 + (a[i] - '0');
            }
            else{
                //get digits
                int x = a[i] - '0', y = b[i] - '0';
                i++;
                //get second digits as well
                //imagine we have l = 59, r = 63, if we tried this 1 digit at a time, the logic would get extremely complex
                //since your boundaries would be dependant on whether the first digit chosen matches the first dig of l or r
                //therefore by considering both digits simultaneously, we can remove this obstacle
                if (i != a.size()){
                    x = x * 10 + (a[i] - '0');
                    y = y * 10 + (b[i] - '0');
                }
                //for every possible set of 2 digits
                for (int j = x; j <= y; j++){
                    //combine the base with the digit pair
                    long long temp = (i < a.size() ? base * 100 + j : base * 10 + j);
                    //continuously repeat the same digit that we ended with, there's no point in trying new digits
                    //our max and min are clearly defined by the first 2 digits we chose, everything after cannot improve from our first 2 digits
                    for (int k = i + 1; k < a.size(); k++){
                        temp = temp * 10 + (j % 10);
                    }
                    //if it's better, we take it, otherwise move on
                    if (l <= temp && temp <= r && luck(temp) < bestluck){
                        bestluck = luck(temp);
                        ans = temp;
                    }
                }
                break; //exit
            }
        }

        std::cout << ans << '\n';
            
    }
    
    return 0;
    
}