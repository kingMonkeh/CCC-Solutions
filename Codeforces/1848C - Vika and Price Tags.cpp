/*

i hate this problem so much

key idea:
we note that once we reach 0, it will repeat every 3 moves
for example
2 0 2 2 0
  ^     ^

therefore, if it takes cnt1 steps for index i to reach 0
and cnt2 steps for index j to reach 0

if cnt1 % 3 == cnt2 % 3, then a[i] and a[j] will reach 0 at the same time

so now we must determine the number of steps to reach 0 given a and b
we notice something, lets just assume a >= b

a, b, a - b, a - 2 * b, b, a - 3 * b, a - 4 * b, b, ...
we notice that b repeats itself every 3 terms as well, and before it is a - k * 2b = 0 for some k
if we know k, then we can skip the tedious subtraction and immediately obtain
that we did k * 3 + 1 steps, inclusive of our original a and b

what if k < 1?
we can just manually perform a single step and try again with the new a, b
this significantly cuts down runtime


*/

#include <bits/stdc++.h>

int solve (int a, int b){
    
    //will repeat on step 4
    if (a == 0 && b){
        return 1;
    }
    //will repeat on step 5
    else if (a && b == 0){
        return 2;
    }
    
    //total steps
    long long iter = 0;
    //ensure a >= b by manually performing 1 step
    if (a < b){
        int temp = abs(a - b);
        a = b; b = temp;
        iter++;
    }

    bool change = false;
    long long times = a / (2 * b); // k
    if (times >= 1){
        iter += times * 3 + 1; //this is inclusive of the element, a - k * 2b, therefore if we need to go recurse deeper, we dont want to add another step this is why we have the bool change
        a -= 2 * times * b; //update a, b is guranteed to be the same as seen from our proved equation
        change = true;
    }

    if (a != 0){
        //progress 1 manually
        long long temp = abs(a - b);
        a = b;
        b = temp;
        if (!change) iter++; //if already counted when subtracting, we dont want to count again
        return iter + solve(a, b); //call again
    }

    return iter;
    
}

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<long long> a (n), b (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];

        std::set<int> mods;
        for (int i = 0; i < n; i++){
            if (a[i] == 0 && b[i] == 0) continue; //always 0
            mods.insert((solve(a[i], b[i])) % 3);
        }

        if (mods.size() == 1 || mods.size() == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    
    return 0;
    
}