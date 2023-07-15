#include <iostream>
#include <cstdio>
#include <cstring>

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int farmer_l, farmer_r, bessie_l, bessie_r;
    std::cin >> farmer_l >> farmer_r >> bessie_l >> bessie_r;
    int fence [100]; memset(fence, 0, sizeof(fence));
    for (int i = farmer_l; i < farmer_r; i++){
        fence[i] = 1;
    }
    for (int i = bessie_l; i < bessie_r; i++){
        fence[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 100; i++){
        ans += fence[i];
    }
    std::cout << ans;
    return 0;
}