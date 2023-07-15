/*

O(n) time, just simulate it

*/

class Solution {
public:
    string convert(string s, int numRows) {
        std::string ans = "";
        std::vector<std::string> grid (numRows);
        int row = 0; bool down = true;
        for (int i = 0; i < s.length(); i++){
            std::cout << row << '\n';
            grid[row] += s[i];
            if (down){
                row++;
                if (row == numRows){
                    down = false;
                    row = std::max(0, row - 2);
                }
            }
            else{
                row--;
                if (row == -1){
                    down = true;
                    row = row + 2 < numRows ? row + 2 : 0;
                }
            }
        }
        for (int i = 0; i < numRows; i++){
            ans += grid[i];
        }
        return ans;
    }
};