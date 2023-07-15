#include <iostream>

int main (){
    int N;
    std::cin >> N;
    //Keep track of previous 2 negative numbers as well as current positive
    long long neg1 = 0, neg2 = 0, pos = 0;
    //Even N
    if (N % 2 == 0){
        //{1, -2, -3, 4}
        //Previous one, aka last one was positive and already cancelled out negatives, so just put 0
        for (int i = 0; i < N; i++){
            if (i % 4 == 0){
                std::cout << 0 << ' ';
            }
            //one less than pos
            else if (i % 4 == 1){
                std::cout << -pos - 1 << ' ';
                neg1 = -(pos + 1);
            }
            //Already cancelled pos, so just throw -1
            else if (i % 4 == 2){
                std::cout << -1 << ' ';
                neg2 = -1;
            }
            //Equal to two previous negatives to cancel, other positives will help later on
            else{
                std::cout << (neg1 + neg2) * -1 << ' ';
                pos = (neg1 + neg2) * -1;
            }
        }
    }
    //Odd N
    else{
        //{1, 2, -3, -4}
        for (int i = 0; i < N; i++){
            //Only needs to cancel out the previous 2 negatives, since there will be other positives to help out along the way
            if (i % 4 == 0){
                std::cout << (neg1 + neg2) * -1 << ' ';
                pos = (neg1 + neg2) * -1;
            }
            //Previous one already cancels out the negatives, therefore you can ride off of that
            else if (i % 4 == 1){
                std::cout << 0 << ' ';
            }
            //One less than pos to cancel it out
            else if (i % 4 == 2){
                std::cout << -pos - 1 << ' ';
                neg1 = -(pos + 1);
            }
            //Previous already cancelled, so just put -1 for now
            else{
                std::cout << -1 << ' ';
                neg2 = -1;
            }
        }
    }
    return 0;
}