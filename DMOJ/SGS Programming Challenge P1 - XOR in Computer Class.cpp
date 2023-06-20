/*

Notice that if XOR something
if we XOR by 1, the bit will flip
1 XOR 1 -> 0
0 XOR 1 -> 1
If we XOR by 0 the bit remains the same
0 XOR 0 -> 0
1 XOR 0 -> 1

*/

#include <iostream>
#include <bitset>

int N;
std::bitset<200000> b;

bool solveBit(){
    long long zero = 0, one = 0; //sum if we put 0, or 1
    for (int i = 0; i < N; i++){
        //Total subarrays that contain this element is (i) * (N - i + 1)
        //This can be obtained from the fact that starting from middle
        //You can go i units to the left, meaning i subarrays
        //Then you can go N - i + 1 units right, meaning N - i + 1 subarrays to the right
        //Then obviously, you can combine the two, aka, 2 units left and 3 units right
        //Which is why we multiply them
        zero += (long long) b[i] * (N - i + 1) * i;
        one += (long long) (b[i] ^ 1) * (N - i + 1) * i;
    }
    return one < zero;
}

int main(){
    std::cin >> N;
    int a [N];
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
    //32 bits lmao
    int x = 0;
    for (int i = 0; i < 32; i++){
        //Get all the ith bit of every number and add to bitset
        for (int j = 0; j < N; j++){
            b[j] = a[j] >> i & 1;
        }
        //x = x | (solveBit() shifted i units left)
        x |= solveBit() << i;
    }
    std::cout << x << '\n';
    return 0;
}