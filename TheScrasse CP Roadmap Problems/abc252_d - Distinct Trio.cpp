#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*

We can rephrase the problem as find all distinct triplets
where A[i] < A[j] < A[k]

The reason for this is quite simple
Although the i j and k may not be in the correct order
There exists a unique permutation of them which is in the correct order, therefore we can still count it

*/

int main (){

    int N;
    std::cin >> N;

    std::vector<int> A (N);
    for (auto& a: A) std::cin >> a;

    std::sort(A.begin(), A.end());

    std::map<int, int> lower, freq;
    int cnt = 0, cur = -1;
    for (int i = 0; i < N; i++){
        if (A[i] != cur){
            cur = A[i];
            lower[cur] = cnt;
        }
        freq[cur]++;
        cnt++;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++){
        ans += (long long) lower[A[i]] * (N - lower[A[i]] - freq[A[i]]);
    }

    std::cout << ans << '\n';
    
}