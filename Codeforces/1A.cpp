#include <iostream>

int main(){

    long long n, m, a;
    std::cin >> n >> m >> a;

    long long x = n / a;
    if (n % a != 0){
        x++;
    }
    long long y = m / a;
    if (m % a != 0){
        y++;
    }

    long long total = x * y;
    std::cout << total;

    return 0;

}