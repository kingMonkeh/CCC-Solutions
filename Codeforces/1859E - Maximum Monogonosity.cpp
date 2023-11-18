#include <bits/stdc++.h>

#define vi std::vector<int>

long long DP [3001][3001][5]; //declar globally to avoid stack overflow

signed main (){

    int tests;
    std::cin >> tests;
    while (tests--){

        int n, K;
        std::cin >> n >> K;

        std::vector<long long> a (n), b (n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];

        //dp[i][j][k] tells us max sum with all elements up to a[i], total length used = j and k tells us interval state
        //k = 0 means we're not in an interval,
        //k = 1, 2, 3, 4 corresponds to one of the possible absolute max values:
        //think about how we can change absolute value to regular subtract depending on what values are the greatest in the equation
        //-al + bl - ar + br 
        //al + bl - ar - br 
        //-al - bl + ar + br
        //al - bl + ar  - br 
        
        for (int i = 0; i <= n; i++) for (int j = 0; j <= K; j++) for (int k = 0; k < 5; k++) DP[i][j][k] = -100000000000;
        DP[0][0][0] = 0; //base case
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= K; j++){

                //don't take
                DP[i + 1][j][0] = std::max(DP[i + 1][j][0], DP[i][j][0]);

                //continue the segment we're currently in
                if (j < K){
                    for (int k = 1; k < 5; k++){
                        DP[i + 1][j + 1][k] = std::max(DP[i + 1][j + 1][k], DP[i][j][k]);
                    }
                }
                
                //start a new segment
                if (j < K){
                    //-al + bl - ar + br 
                    DP[i + 1][j + 1][1] = std::max(DP[i + 1][j + 1][1], DP[i][j][0] - a[i] + b[i]);
                    //al + bl - ar - br 
                    DP[i + 1][j + 1][2] = std::max(DP[i + 1][j + 1][2], DP[i][j][0] + a[i] + b[i]); 
                    //-al - bl + ar + br
                    DP[i + 1][j + 1][3] = std::max(DP[i + 1][j + 1][3], DP[i][j][0] - a[i] - b[i]);
                    //al - bl + ar  - br 
                    DP[i + 1][j + 1][4] = std::max(DP[i + 1][j + 1][4], DP[i][j][0] + a[i] - b[i]);
                }

                //end segment
                if (j < K){
                    //-al + bl - ar + br 
                    DP[i + 1][j + 1][0] = std::max(DP[i + 1][j + 1][0], DP[i][j][1] - a[i] + b[i]); 
                    //al + bl - ar - br 
                    DP[i + 1][j + 1][0] = std::max(DP[i + 1][j + 1][0], DP[i][j][2] - a[i] - b[i]); 
                    //-al - bl + ar + br
                    DP[i + 1][j + 1][0] = std::max(DP[i + 1][j + 1][0], DP[i][j][3] + a[i] + b[i]);
                    //al - bl + ar  - br 
                    DP[i + 1][j + 1][0] = std::max(DP[i + 1][j + 1][0], DP[i][j][4] + a[i] - b[i]);
                }
                
                //edge case: segment size 1
                if (j < K){
                    DP[i + 1][j + 1][0] = std::max(DP[i + 1][j + 1][0], DP[i][j][0] + llabs(a[i] - b[i]) * 2);
                }
                
            }
        }

        std::cout << DP[n][K][0] << '\n';
        
    }
    
    return 0;
    
}
