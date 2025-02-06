#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {

  int n;
  std::cin >> n;

  std::vector<int> a (n);
  std::vector<int> b (n);

  for (int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    std::cin >> b[i];
  }

  //lets approach the problem in parts
  //note that the grading of the problem, you receive half marks if you correctly print out the first line
  //this indicates that we should think about the necessary conditions to transform A -> B

  //obvious points
  //you need all the numbers in B to also be in A

  //A: 1 3 2
  //B  1 2 3

  //we can clearly see that A contains all the numbers in B, but there is no way to transform A -> B
  //therefore we note our second necessary condition
  //the order in which the numbers appear in A must be the same as the order in B, consecutive duplicates are ok

  //ie 
  //A: 1 8 7 7 2 7 9 9 0 3
  //B: 1 2 2 2 2 2 3 3 3 3
  //is solvable because we note that there is a 1, 2, 3 in A, which matches the 1, 2, 3 in B

  std::vector<std::vector<int>> important; // keep the positions of the important values
  //an example important vector for the above A, B example would look like
  /*
  {1, 0}
  {2, 4}
  {3, 9}
  */
  
  int target = b[0]; //set the target we are looking for in A
  int A_index = 0;
  for (int i = 0; i < n; i++){
    //pass all the duplicate targets in B
    while (i < n && b[i] == target){
      i++;
    }
    //Sift through A to find the target
    while (A_index < n && a[A_index] != target){
      A_index++;
    }
    //std::cout << A_index << '\n';
    //If we are unable to find the target in A,
    if (A_index >= n){
      std::cout << "NO\n";
      return 0;
    }
    important.push_back({target, A_index});
    target = b[i];
    i--; //since we are doing i++ in the while loop
  }

  /*
  for (auto& a: important){
    std::cout << a[0] << ' ' << a[1] << '\n';
  }
  */

  //If it did not fail, then print yes
  std::cout << "YES\n";

  //NOTICE, we must perform the left moves first,
  //the logic is that for the leftmost value of b, we just gotta swipe left when we first see it in A
  std::vector<std::vector<int>> leftMoves;
  int left = 0;
  target = b[0]; //set the target we are looking for in A
  int impIndex = 0; //index in important
  for (int i = 0; i < n && impIndex < important.size(); i++, impIndex++){
    //pass all the duplicate targets in B
    while (i < n && b[i] == target){
      i++;
    }
    //If we need to swipe left
    if (important[impIndex][1] > left){
      leftMoves.push_back({left, important[impIndex][1]});
    }
    target = b[i];
    left = i;
  }

  //After we swipe left, we can then safely do right swipes
  //we note that we need to right swipes starting from the right side of the array
  //this is to avoid overwriting important values when swiping right
  std::vector<std::vector<int>> rightMoves;

  int right = n - 1;
  target = b[n - 1]; //set the target we are looking for in A
  impIndex = important.size() - 1;
  for (int i = n - 1; i >= 0 && impIndex >= 0; i--, impIndex--){
    //pass all the duplicate targets in B
    while (i >= 0 && b[i] == target){
      i--;
    }
    if (important[impIndex][1] < right){
      rightMoves.push_back({important[impIndex][1], right});
    }
    target = b[i];
    right = i;
  }

  //Afterward output our moves, remember
  //left moves first, then right moves after
  std::cout << leftMoves.size() + rightMoves.size() << '\n';
  for (auto& m: leftMoves){
    std::cout << "L " << m[0] << ' ' << m[1] << '\n';
  }
  for (auto& m: rightMoves){
    std::cout << "R " << m[0] << ' ' << m[1] << '\n';
  }
  
}