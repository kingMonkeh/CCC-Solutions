#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {

  //Get input
  int t, n;
  std::cin >> t >> n;

  //For every string
  for (int i = 0; i < t; i++){

    std::string s;
    std::cin >> s;

    //make a map, where map[letter] = # of times the letter appears in the string
    //setup the map with the frequncies
    std::map<char, int> freq;
    for (auto& c: s){
      freq[c]++;
    }

    //now check for light heavy
    bool isLight = freq[s[0]] <= 1; //check whether first letter is light or heavy, this will decide the ordering
    bool passed = true;
    for (auto& c: s){
      //If the current letter is supposed to be light, but is actually heavy, its wrong
      if (isLight){
        if (freq[c] > 1){
          std::cout << "F" << '\n';
          passed = false;
          break;
        }
      }
      else{
        if (freq[c] <= 1){
          std::cout << "F" << '\n';
          passed = false; break;
        }
      }
      isLight = !isLight;
    }

    if (passed){
      std::cout << "T" << '\n';
    }
    
  }
  
}