class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int asize = A.size(), bsize = B.size();
        int totalsize = asize + bsize;
        //If odd
        if (totalsize % 2){
            return solve (A, B, totalsize / 2, 0, asize - 1, 0, bsize - 1);
        }
        //If even
        else{
            return 1.00 * (solve (A, B, totalsize / 2 - 1, 0, asize - 1, 0, bsize - 1) + solve (A, B, totalsize / 2, 0, asize - 1, 0, bsize - 1)) / 2;
        }
    }
    
    int solve (std::vector<int>& A, std::vector<int>& B, int target, int aleft, int aright, int bleft, int bright){
        //Base case, we've used up one array
        //Return otherArray[target - usedUpArrayLeft]
        //Think to the kth - index diagram in the editorial
        if (aright < aleft){
            return B[target - aleft];
        }
        if (bright < bleft){
            return A[target - bleft];
        }

        //Find midpoint in each as well as corresponding value
        int amid = (aleft + aright) / 2, bmid = (bleft + bright) / 2;
        int aval = A[amid], bval = B[bmid];

        if (amid + bmid < target){
            //Chop off B left
            if (aval > bval){
                return solve (A, B, target, aleft, aright, bmid + 1, bright);
            }
            //Chop off A left
            else{
                return solve (A, B, target, amid + 1, aright, bleft, bright);
            }
        }
        else{
            //Chop off A right 
            if (aval > bval){
                return solve (A, B, target, aleft, amid - 1, bleft, bright);

            }
            //Chop off B right
            else{
                return solve (A, B, target, aleft, aright, bleft, bmid - 1);

            }
        }
    }
};