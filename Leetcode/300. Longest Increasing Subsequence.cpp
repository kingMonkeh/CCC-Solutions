/*

let len[i] tell us the max length increasing subsequence that ends at index i in nums

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> len (n, 1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    len[i] = std::max(len[i], len[j] + 1);
                }
            }
        }
        int ans = 1;
        for (auto l: len) ans = std::max(ans, l);
        return ans;
    }
};