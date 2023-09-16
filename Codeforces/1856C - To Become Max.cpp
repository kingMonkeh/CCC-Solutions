#include <bits/stdc++.h>

/*

An infinite amount of pain courses through me, as I look at this question with 3 Wrong Answers and 5 minutes left on the clock
I check standings to see that I'm now 8000th place and will be losing 60 rating because of my incompetence
One can only imagine the pain

- Hy Lac

*/

long long a [1000];
long long n, k;

bool check (long long x){

    bool ok = false;
    
    for (int i = 0; i < n; i++){
        long long _x = x;
        long long ops = 0;
        for (int j = i; j < n; j++){
            //if bigger than _x, then we don't need to do anything
            if (a[j] >= _x){
                ok |= ops <= k;
                break;
            }
            ops += _x - a[j];
            _x--;
        }
    }

    return ok;
    
}

int main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        std::cin >> n >> k;
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        long long l = 0, r = 2e8 + 1;
        while (r - l > 1){
            long long mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        }

        std::cout << l << '\n';
        
    }
    
    return 0;
    
}