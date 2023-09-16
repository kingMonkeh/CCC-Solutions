#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

//d - f
//we want to maximize d and minimize f
//how do we minimize f?
//choose shortest tasks
//if two tasks have same length?
//do the task with the longer deadline first to maximize d

struct task{
    int a, d;
    bool operator < (task& x){
        return a == x.a ? d > x.d : a < x.a;
    }
};

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<task> tasks (n);
    for (int i = 0; i < n; i++){
        std::cin >> tasks[i].a >> tasks[i].d;
    }

    std::sort(tasks.begin(), tasks.end());

    int ans = 0, time = 0;
    for (int i = 0; i < n; i++){
        time += tasks[i].a;
        ans += tasks[i].d - time;
    }

    std::cout << ans;
        
    return 0;
    
}