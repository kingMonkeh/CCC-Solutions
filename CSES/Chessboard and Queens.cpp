#include <bits/stdc++.h>

#define int long long
const int MOD = 1e9 + 7;

struct queen{
    int r, c;
};

std::vector<std::string> board (8);
std::vector<queen> queens;
int ans = 0;
void solve (int q, int r){

    if (q == 8){
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++){
        bool good = true;
        for (auto& qu: queens){
            if (r - qu.r == i - qu.c || r - qu.r == -(i - qu.c) || i == qu.c){
                good = false;
                break;
            }
        }
        if (board[r][i] == '*') good = false;
        if (good){
            queen qu; qu.r = r; qu.c = i;
            queens.push_back(qu);
            solve(q + 1, r + 1);
            queens.pop_back();
        }
    }
    
}

signed main (){

    int tests;
    //std::cin >> tests;
    tests = 1;
    while (tests--){

        for (int i = 0; i < 8; i++) std::cin >> board[i];

        solve(0, 0);

        std::cout << ans << '\n';
        
    }

    return 0;
    
}