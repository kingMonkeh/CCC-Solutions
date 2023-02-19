/*
ID: 
TASK: ride
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <string>


int main(){
    
    std::ofstream output ("ride.out");
    std::ifstream input ("ride.in");
    
    std::string comet, group;
    
    input >> comet >> group;
    
    int cometNumber = 1, groupNumber = 1;
    
    for (int i = 0; i < comet.length(); i++){
        cometNumber *= comet[i] - 'A' + 1; //Since comet name only has capital letters, subtracting by 'A' will return the correct ASCII code difference
    }
    
    for (int i = 0; i < group.length(); i++){
        groupNumber *= group[i] - 'A' + 1;
    }
    
    cometNumber %= 47;
    groupNumber %= 47;
    
    if (cometNumber == groupNumber) output << "GO" << '\n';
    
    else output << "STAY" << '\n';
    
    return 0;
    
}
