/*

Very similar to 2023 S2 from Waterloo CCC

Expand from center approach
Although seems inefficient at first, notice that most string wont expand that far
unless string is "aaaaaaa...."

DP can also be used, but im lazy :|

*/

class Solution {
public:
    string longestPalindrome(string s) {
        std::string ans = ""; ans += s[0];
        for (int i = 0; i < s.length(); i++){
            int l = i, r = i;
            while (l >= 0 && r <= s.length() && s[l] == s[r]){
                l--; r++;
            }
            l++; r--;
            if (r - l > ans.length()){
                ans = s.substr(l, r - l + 1);
            }
        }
        for (int i = 0; i < s.length(); i++){
            int l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]){
                l--; r++;
            }
            if (r - l > ans.length()){
                ans = s.substr(l + 1, r - l - 1);
            }
        }
        return ans;
    }
};