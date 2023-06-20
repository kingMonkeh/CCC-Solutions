class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        std::set<char> window;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            while (window.count(s[r])){
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};