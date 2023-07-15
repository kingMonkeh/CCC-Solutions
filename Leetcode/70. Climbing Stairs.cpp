class Solution {
public:
    int DP [46];
    int climbStairs(int n) {
        memset(DP, 0, sizeof(DP));
        return solve(n);
    }
    int solve (int step){
        if (step < 0){
            return 0;
        }
        if (DP[step]){
            return DP[step];
        }
        if (step == 0){
            return 1;
        }
        int ans = 0;
        ans += solve(step - 1);
        ans += solve(step - 2);
        return DP[step] = ans;
    }
};