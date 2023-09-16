#include <bits/stdc++.h>

int n;
std::vector<std::pair<int, int>> people;

//Check if it's possible to invite x people
bool check (int x){

    //If we want to invite x people
    //Given a person p, b >= # of people poorer at the moment
    //a >= x - # of people poorer at the moment = # of people richer
    //Combine and rearrange, we get x - a <= # of poorer <= b
    int poorer = 0;
    int i = 0;
    for (; i < n; i++){
        if (x - people[i].first - 1 <= poorer && poorer <= people[i].second){
            poorer++;
        }
    }

    return (poorer >= x ? true : false);
    
}

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        std::cin >> n;
        
        people.resize(n);
        for (int i = 0; i < n; i++){
            std::cin >> people[i].first >> people[i].second;
        }

        int l = 1, r = n + 1;
        while (l < r){
            int mid = (l + r) / 2;
            if (check(mid)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        std::cout << --l << '\n';

        people.clear();
        
    }
    
    return 0;
    
}