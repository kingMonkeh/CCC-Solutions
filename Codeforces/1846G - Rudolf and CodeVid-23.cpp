/*

Dijkstras lmao
just think of a graph where our original symptoms is the root
when we apply a medicine, its like traversing an edge with weight d and it will lead us to a new set of symptoms
therefore, we just check the shortest path from root to 0, since 0 means we're cured

if its not possible to reach, then we just output -1

*/

#include <bits/stdc++.h>

struct medicine{
    int d; std::bitset<10> cure, cause;
};

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n, m;
        std::cin >> n >> m;
        std::bitset<10> symptoms;
        std::cin >> symptoms;

        std::vector<medicine> meds (m);
        for (int i = 0; i < m; i++){
            std::cin >> meds[i].d >> meds[i].cure >> meds[i].cause;
        }

        if (symptoms.to_ulong() == 0){
            std::cout << 0 << '\n';
            continue;
        }

        std::vector<int> time (1024, INT_MAX);
        std::queue<std::bitset<10>> q;
        q.push(symptoms);
        time[symptoms.to_ulong()] = 0;

        while (!q.empty()){
            std::bitset<10> cur = q.front();
            q.pop();
            for (int i = 0; i < m; i++){
                std::bitset<10> temp = (cur ^ (cur & meds[i].cure)) | meds[i].cause;
                if (time[temp.to_ulong()] > time[cur.to_ulong()] + meds[i].d){
                    q.push(temp);
                    time[temp.to_ulong()] = time[cur.to_ulong()] + meds[i].d;
                }
            }
        }

        if (time[0] == INT_MAX) std::cout << -1 << '\n';
        else std::cout << time[0] << '\n';
        
    }
    
    return 0;
    
}