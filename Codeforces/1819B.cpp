/*

Very interesting problem

Basically notice that with the first cut, it can be vertical or horizontal
The resulting rectangle will either represent the height or width of the original rectangle

We will essentially try to see if it's possible for the first cut to have been horizontal
as well as vertical

Notice that if you continously chop vertically
All the pieces will have the same height

If you chop all horizontally
The pieces will have the same width

Basically, combine all these to determine the total height or width they consume

Essentially, keep track of how much more space is left in the rectangle that you can fill
And repeatedly check if it's possible

*/

#include <iostream>
#include <vector>
#include <utility>
#include <set>

int n;
std::vector<std::pair<long long, long long>> blocks;

std::pair<long long, long long> solve (){

    std::set<std::pair<long long, long long>> tallest, widest;
    for (int i = 0; i < n; i++){
        tallest.insert({blocks[i].first, i});
        widest.insert({blocks[i].second, i});
    }

    bool initial = true;
    long long initialBase = 0;
    long long cut = 0; //0 for vertical, 1 for horizontal
    long long heightRemaining, widthRemaining;
    std::pair<long long, long long> answer = {-1, -1};

    while (tallest.size() > 0){

        //Chop vertically
        if (cut == 0){

            //Find largest height
            long long largestHeight = (*tallest.rbegin()).first;
            
            long long collectiveWidth = 0;
            while (tallest.size() > 0 && (*tallest.rbegin()).first == largestHeight){
                auto it = (--tallest.end());
                widest.erase({blocks[it->second].second, it->second});
                collectiveWidth += blocks[it->second].second;
                tallest.erase(it);
            }

            //Form the initial rectangle
            if (initial){
                heightRemaining = largestHeight;
                answer.first = largestHeight;
                answer.second = collectiveWidth;
                initialBase += collectiveWidth;
            }
            else{
                //Subtract the total width of all the vertically chopped rectangles
                widthRemaining -= collectiveWidth;
                //The largest height should match with the height remaining, otherwise it wouldnt be a rectangle
                if (largestHeight != heightRemaining) return {-1, -1};
            }
            
        }
        //Chop horizontally
        else{
    
            long long largestWidth = (*widest.rbegin()).first;
            
            long long collectiveHeight = 0;
            while (widest.size() > 0 && (*widest.rbegin()).first == largestWidth){
                auto it = (--widest.end());
                tallest.erase({blocks[it->second].first, it->second});
                collectiveHeight += blocks[it->second].first;
                widest.erase(it);
            }
    
            if (initial){
                initialBase += largestWidth;
                widthRemaining = largestWidth;
                heightRemaining -= collectiveHeight;
                answer.second = initialBase;
                initial = false;
            }
            else{
                heightRemaining -= collectiveHeight;
                if (largestWidth != widthRemaining) return {-1, -1};
            }
            
        }

        cut = !cut;

    }

    if (widthRemaining == 0 || heightRemaining == 0 || initial == true){
        return answer;
    }
    else{
        return {-1, -1};
    }
    
}

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        blocks.clear();
        std::cin >> n;
        blocks.resize(n);
        for (int i = 0; i < n; i++){
            std::cin >> blocks[i].first >> blocks[i].second;
        }
        std::vector<std::pair<long long, long long>> answers;
        answers.push_back(solve());
        if (answers[0].first == -1){
            answers.pop_back();
        }
        //Rotate all shapes, do the same process again, note that the height and width will be swapped, so you should rotate your answer as well
        for (auto& block: blocks){
            std::swap(block.first, block.second);
        }        
        answers.push_back(solve());
        std::swap(answers.back().first, answers.back().second);
        if (answers.back().first == -1){
            answers.pop_back();
        }
        if (answers.size() == 2 && answers[0] == answers[1]){
            answers.pop_back();
        }
        std::cout << answers.size() << '\n';
        for (auto ans: answers){
            std::cout << ans.first << ' ' << ans.second << '\n';
        }
    }
    return 0;
}