#include <bits/stdc++.h>

int main(){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        int ans = 1;
        //a_i + x = p^2, a_j + x = q^2, where p < q
        //(a_j + x) - (a_i + x) = a_j - a_i = q^2 - p^2 = (q - p)(q + p)
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int diff = a[j] - a[i];
                //Find all factors of diff
                //let (q - p) = d
                //let (q + p) = (a_j - a_i) / d
                //elimination, (q + p) - (q - p) = ((a_j - a_i) / d) - d
                //2p = ((a_j - a_i) / d) - d
                //p = (1/2) * (((a_j - a_i) / d) - d)
                //same idea, q = (1/2) * (((a_j - a_i) / d) + d)
                for (int f = 1; f * f <= diff; f++){
                    //if (a_j - a_i) divisible by d or (q - p)
                    if (diff % f == 0){
                        long long q = diff / f + f;
                        //Make sure q is actually an integer
                        if (q % 2 == 0){
                            q /= 2;
                            //Ensure q is not negative either
                            if (q * q >= a[j]){
                                int squaredness = 0;
                                long long x = q * q - a[j];
                                //Evaluate squaredness of x value
                                for (auto v: a){
                                    if (sqrt(v + x) == floor(sqrt(v + x))){
                                        squaredness++;
                                    }
                                }
                                ans = std::max(ans, squaredness);
                            }
                        }
                    }
                }
            }
        }

        std::cout << ans << '\n';
        
    }
    
    return 0;
    
}