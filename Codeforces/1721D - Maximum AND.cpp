#include <bits/stdc++.h>

//NOTE (im stupid): 0 & 0 != 1

bool valid (int ans, std::vector<int>& a, std::vector<int>& b){
    std::map<int, int> req; //let req[bitset] tell us the total amount of matching b's that are required to fill in for the remaining a's, when we find an a, we increment, when we find a matching b, we decrement
    for (int i = 0; i < (int) a.size(); i++){
        //a[i] & ans will tell us what 1's are already matching between a[i] and mask
        //ans ^ (a[i] & ans) will tell us what are the remaining bits that need to be turned on
        req[ans ^ (a[i] & ans)]++; //you need this set of bits to be turned on by b
        req[b[i] & ans]--; //by taking b[i] & ans, we know what bits b[i] can activate
    }
    //If there exists a matching b for every a, then they should cancel out from the addition and subtraction above and leave us with 0
    for (auto& x: req) if (x.second != 0) return false;
    return true;
}

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n), b (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];

        //Greedily try adding bits from greatest to least
        //Note that as we add more bits, we still want to ensure that the previous bits are still activated
        int ans = 0;
        for (int bit = 30; bit >= 0; bit--){
            //let temp be a mask that contains the current bits we've already activated + the new bit we'd like to try to turn on
            int temp = ans | (1 << bit);
            if (valid(temp, a, b)) ans |= (1 << bit);
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}