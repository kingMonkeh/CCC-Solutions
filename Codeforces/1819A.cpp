/*

Find mex

2 main cases:

if mex + 1 is already in the set, you have to replace every mex + 1 with mex, 
Try this and see if the new mex = mex + 1, if not not possible

If mex + 1 is not present in the set, you just need to introduce mex into the set somehow without fully erasing all values less than mex
If there's any value greater than mex, u can just replace that with mex
If there exists duplicate values of numbers less than mex, than you can choose to replace one of those with mex as well

*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int findmex(std::vector<int> a){
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int mex = 0, n = a.size();
    for (int i = 0; i < n; i++, mex++){
        if (a[i] != i){
            mex = i;
            break;
        }
    }
    return mex;
}

int main(){
    int tests;
    std::cin >> tests;
    while (tests--){
        std::map<int, int> left;
        std::map<int, int> right;
        int n;
        std::cin >> n;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++){
            std::cin >> a[i];
            if (!left.count(a[i])){
                left[a[i]] = i; 
            }
            right[a[i]] = i;
        }
        int mex = findmex(a);
        //If mex + 1 is present already
        if (left.count(mex + 1)){
            for (int i = left[mex + 1]; i <= right[mex + 1]; i++){
                a[i] = mex;
            }
            int newmex = findmex(a);
            if (newmex == mex + 1){
                std::cout << "Yes\n";
            }
            else{
                std::cout << "No\n";
            }
        }
        //If not
        else{
            for (int i = 0; i < n; i++){
                if (a[i] > mex || left[a[i]] != right[a[i]]){
                    std::cout << "Yes\n";
                    goto nextTest;
                }
            }
            std::cout << "No\n";
        }
        nextTest: ;
    }
    return 0;
}