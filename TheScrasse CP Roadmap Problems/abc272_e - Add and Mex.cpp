#include <iostream>
#include <vector>
#include <map>

/*

We notice the max MEX is N + 1
Therefore lets mark what values can be reached on each step

Since the value of i is always increasing, we notice a harmonic series
for the first term a[1]

there will be (N / 1) values in the worst case
for term a[2]

there will be (N / 2) values in the worst case before a[2] > N

(N / 3) values worst case for a[3]

... and so on

Therefore O N log N time worst case, which is still in bounds

*/

int main (){

    int N, M;
    std::cin >> N >> M;
    std::vector<int> A (N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std::vector<std::map<int, int>> vals (M + 1); //tells us what positive values exist at operation M
    for (int i = 0; i < N; i++){
        if (A[i] >= N) continue;   // will never impact answer 
        //let l represent the first operation of M in which A[i] >= 0
        int l = (A[i] >= 0 ? 1 : (-A[i]) / (i + 1));
        A[i] += (i + 1) * l;
        while (l <= M && A[i] <= N){
            vals[l][A[i]] = true;
            A[i] += (i + 1);
            l++;
        }
    }

    for (int i = 1; i <= M; i++){
        int ans = 0;
        while (vals[i][ans]) ans++;
        std::cout << ans << '\n';
    }
    
}