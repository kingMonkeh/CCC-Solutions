#include <bits/stdc++.h>

/*

USE PRIORITY QUEUE TO MAINTAIN THE FIRST GUY TO DEPART

*/

struct person{
    int a, b, i;
    bool operator < (person& x){
        return this->a == x.a ? this->b < x.b : this->a < x.a;
    }
};

int main(){

    int n;
    std::cin >> n;

    std::vector<person> customers (n);
    for (int i = 0; i < n; i++){
        person c;
        std::cin >> c.a >> c.b;
        c.i = i;
        customers[i] = c;
    }

    std::sort(customers.begin(), customers.end());
    std::priority_queue<std::pair<int, int>> pq;
    std::vector<int> rooms (n);

    int room = 0;
    for (int i = 0; i < n; i++){
        if (pq.empty()){
            room++;
            pq.push(std::make_pair(-customers[i].b, room));
            rooms[customers[i].i] = room;
        }
        else{
            std::pair<int, int> firstleave = pq.top();
            if (-firstleave.first < customers[i].a){
                pq.pop();
                pq.push(std::make_pair(-customers[i].b, firstleave.second));
                rooms[customers[i].i] = firstleave.second;
            }
            else{
                room++;
                pq.push(std::make_pair(-customers[i].b, room));
                rooms[customers[i].i] = room;
            }
        }
    }

    std::cout << room << '\n';
    for (auto& x: rooms) std::cout << x << ' '; std::cout << '\n';
    
    return 0;
    
}