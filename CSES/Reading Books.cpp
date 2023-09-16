#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>
#define f first
#define s second

signed main (){

    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    //if one of them starts with longest book and the other person can read all the books before the first person finishes
    //ans = 2 * longest book since person 2 has to wait
    //if person 1 finishes the longest book before person 2 can read all the other books, they can simply read all books in a slightly different order to allow for them to not overlap at any moment in time
    vi books (n);
    int longest = 0, sum = 0;
    for (int i = 0; i < n; i++){
        std::cin >> books[i];
        sum += books[i];
        longest = std::max(longest, books[i]);
    }

    std::cout << (longest > sum - longest ? longest * 2 : sum);
    
    return 0;
    
}