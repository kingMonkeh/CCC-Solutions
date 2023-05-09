/*

2022 J5 - Square Pool

Difficulty: Hard (Idk why I find this problem so difficult)

I'm basically gonna say what the editorial said, but like dumb it down even more
General idea:
Basically, notice that you can either slide the biggest square left or up until you hit a tree or boundary
This forms like an invisible rectangle, the biggest square in this rectangle has side = min(length rectangle, width rectangle)
There are many such rectangles, to find them we will examine the trees, since theyre stuck on the trees

We will essentially have multiple lines
One of them is a horizontal line that starts from the top and goes down

This line represents the top of the rectangle
We will then examine each point below it, each point will make a new bottom line for our rectangle
There are now many left and right lines along the horizontal, these are determined by the number of trees between the top and bottom line
We iterate through each possible left and right to obtain the width of a rectangle, then compare it to the height of the rectangle

In other words:
For each tree:
    For every tree below this tree or equal height:
        For every point above this inner for loop tree along the horizontal:
            Calculate the width
        Biggest square in this rectangle = min(width, height)


*/

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main(){

    int N, T;
    std::cin >> N >> T;
    std::vector<std::pair<int, int>> trees;
    for (int i = 0; i < T; i++){
        int r, c;
        std::cin >> r >> c;
        trees.push_back({r, c});
    }
    trees.push_back({0, 0});
    trees.push_back({N + 1, N + 1});
    //Sort trees top down
    std::sort(trees.begin(), trees.end(), [&](std::pair<int, int>& a, std::pair<int, int>& b){
        return a.first < b.first;
    });

    int biggestSquare = 0;
    //For each tree, note that the tree in the outer loop represents the top boundary, all trees above are basically ignored
    for (int i = 0; i < trees.size(); i++){
        std::vector<int> horizontal = {0, N + 1};
        //For every tree lower than it or equal height to it, this dictatest the lower boundary
        for (int j = i + 1; j < trees.size(); j++){
            int width = 0, height = trees[j].first - trees[i].first - 1;
            std::sort(horizontal.begin(), horizontal.end()); //Sort left right
            //Check every rectangle formed by the horizontal
            for (int k = 1; k < horizontal.size(); k++){
                width = std::max(width, horizontal[k] - horizontal[k - 1] - 1); //Find max width out of all windows across the horizontal
            }
            biggestSquare = std::max(biggestSquare, std::min(height, width));
            horizontal.push_back(trees[j].second);
            //We're lowering the lower boundary in the next iteration, therefore this tree will now be above or equal to the lower boundary, meaning it divides the horizontal
        }
    }

    std::cout << biggestSquare;
    
    return 0;
    
}