/*

2011 S3 - Alice Through the Looking Glass

Difficulty: Medium/Hard

Personally, the recursion in this question was a bit confusing but here is the general idea:

1. Regardless of magnification, we can always divide the grid into a 5x5 grid.

E = Empty, C = Crystal, P = Possibly a crystal

E E E E E
E E E E E
E E P E E
E P C P E
E C C C E

2. Notice how when doing so, the 3 bottom middle parts and the one right above the bottom middle is always going to be a crystal, regardless of magnification
3. The tricky part about this question are the parts just above the guranteed crystal parts, since they're ambiguous, they can contain the crystal but not guranteed
4. Therefore we will recurse deeper if the cell is in the ambiguous zone

*/

#include <iostream>
#include <math.h>

bool solve(int magnification, int x, int y){
    
    //The length of each subsection from the 5x5 grid we draw over the existing grid can be represented as 5 ^ magnification / 5 or 5 ^ (magnification - 1) by exponent laws
    int lengthOfSubsection = std::pow(5, magnification - 1); 

    //In the case that we recurse, we need to know the x and y value we're searching for in that subsection. That is why we're using modulus
    int subsection_x = x % lengthOfSubsection;
    int subsection_y = y % lengthOfSubsection;
    
    //Determining the what subsection of the grid the current cell is in the larger grid
    x /= lengthOfSubsection;
    y /= lengthOfSubsection;
    
    //If it's in the guranteed crystal zone
    if ((x == 1 && y == 0) || (x == 2 && y == 0) || (x == 3 && y == 0) || (x == 2 && y == 1)){
        return true;
    }
    
    //If it's in the ambiguous zone, remember to only recurse if magnification > 1 since we can't have negative magnification
    if (magnification > 1 && ((x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 1))){
        return solve(magnification - 1, subsection_x, subsection_y);
    }
    
    //If it's in neither then return false since it must be in an empty zone
    return false;
    
}

int main()
{
    
    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; i++){
        
        int magnification, x, y; std::cin >> magnification >> x >> y;
        
        //If it's a crystal
        if (solve(magnification, x, y)){
            std::cout << "crystal" << '\n';
        }
        
        //If not
        else{
            std::cout << "empty" << '\n';
        }
        
    }

    return 0;
}