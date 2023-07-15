#include <bits/stdc++.h>

/*

To gurantee a solve, we could just chop every tower into singular blocks
And then just combine them

But note that if a set of blocks is already in order, there's no point in chopping it since you would have to reassemble it
Therefore, chop each tower into segments of sorted blocks

Then just combine the blocks together

*/

int main(){
    
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> towers (n);
    std::vector<int> blocks;
    
    for (int i = 0; i < n; i++){
        int k;
        std::cin >> k;
        towers[i].resize(k);
        for (int j = 0; j < k; j++){
            std::cin >> towers[i][j];
            blocks.push_back(towers[i][j]);
        }
    }

    //Create map --> [block] : index in all the blocks sorted
    std::sort(blocks.begin(), blocks.end());
    std::map<int, int> order;
    for (int i = 0; i < blocks.size(); i++) order[blocks[i]] = i;

    int s = 0, c = 0;
    for (int i = 0; i < n; i++){
        c++;
        int k = towers[i].size();
        for (int j = 0; j < k - 1; j++){
            //End of a sorted segment of blocks
            if (order[towers[i][j]] != order[towers[i][j + 1]] - 1){
                s++; c++;
            }
        }
    }

    //We don't need to combine the first block since its the main block
    std::cout << s << ' ' << --c << '\n';
    
    return 0;
    
}