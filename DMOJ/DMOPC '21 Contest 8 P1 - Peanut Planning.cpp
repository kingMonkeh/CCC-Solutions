/*

hehehehaw funny greedy problem

Basically, sort the numbers, highly recommended you just throw them in multiset

make array ordered[] to store the correct order
next just throw the smallest number as the first shop in ordered[]

This ensures lexicographically smallest

Afterwards, pretty simple logic
You want to find the next smallest number in the set
that when added will satisfy Anya's peanut requirement

taking the smallest shop will allow the lexicographically smallest arrangement

hint: lower_bound() literaly does this
if no such shop exists that will satisfy anya's requirement
Then its impossible

Otherwise, you have successfully created the shop arrangement

*/

#include <iostream>
#include <set>

std::multiset<int> shops;

int main(){
    int N, M;
    std::cin >> N >> M;
    int ordered [N];
    for (int i = 0; i < N; i++){
        int a;
        std::cin >> a;
        shops.insert(a);
    }
    ordered[0] = *shops.begin();
    shops.erase(shops.find(ordered[0]));
    int i = 1;
    while (shops.size() > 0){
        auto peanuts = shops.lower_bound(M - ordered[i - 1]);
        if (peanuts == shops.end()){
            std::cout << -1;
            return 0;
        }
        shops.erase(peanuts);
        ordered[i] = *peanuts;
        i++;   
    }
    for (int i = 0; i < N; i++){
        std::cout << ordered[i] << ' ';
    }
    return 0;
}