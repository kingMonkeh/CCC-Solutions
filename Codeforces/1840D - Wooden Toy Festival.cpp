/*

simplifying the problem statement

given a number line with intergers plotted on it
youre allowed to place 3 addditional points on the number line
every original point on the number line must be connected to one of the 3 added point, emphasis on only one of the 3 added points
minimize the maximum distance between any added point and its connected points

idea is pretty simple
lets write a function try(int dist) that takes in a distance

we check if this max distance is possible, greedily

view the first toy as the left,
to maximize the stretch, we should place our point left + dist
afterward, this will cover all points from the range [left, left + dist + dist] aka the right as well

the first toy that is not within the right side of our added point
will become the next left and we repeat

if we connect all points, this distance is possible
otherwise, we need more distance

we can now apply binary searching to this problem
if a dist is too short, then any distance shorter will also be too short, therefore we need more distance

if a dist is good, then any distance greater than it is also guranteed to be good
therefore we need to see if there exists a distance smaller than it

O(log n + n)

*/

#include <bits/stdc++.h>

bool TRY(std::vector<int>& a, int dist){

    int size = a.size();
    
    //3 dudes
    int l = a[0];
    int ind = 0;
    for (int i = 0; i < 3; i++){
        int x = l + dist;
        while (a[ind] <= x + dist){
            ind++;
            if (ind == size){
                return true;
            }
        }
        l = a[ind];
    }

    return false;
    
}

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        std::sort(a.begin(), a.end());

        int low = 0, high = a[n - 1];
        while (low < high){
            int mid = (low + high) / 2;
            if (TRY(a, mid)) high = mid;
            else low = mid + 1;
        }

        std::cout << high << '\n';
        
    }

    return 0;
    
}