/*

2013 S4 - Who is Taller?

Difficulty: Easy/Medium

This problem is a very easy S4, simple graph traversal

You can view this problem as a directed graph with the taller person pointing to the shorter person

To check if A is taller than B

Start at A and keep going down the chain of shorter people
If you find B, it means B is shorter than A
If you can't find B it either means unknown or B is taller

Repeat the same process with B
If you still cannot find A from B, it's unknown otherwise, A is shorter

*/

#include <iostream>
#include <vector>
#include <queue>

int main(){

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> shorter (N + 1);

    //Construct our graph
    for (int i = 0; i < M; i++){

        int taller, shorterPerson;
        std::cin >> taller >> shorterPerson;
        
        shorter[taller].push_back(shorterPerson);

    }

    int personA, personB;
    std::cin >> personA >> personB;

    std::vector<bool> visited (N + 1, false);
    std::queue<int> q;

    q.push(personA);
    visited[personA] = true;

    char personAisTaller = 'u';

    //Try finding person B starting from A
    while (!q.empty()){

        int currentPerson = q.front();
        q.pop();

        for (auto shorterPerson: shorter[currentPerson]){

            if (shorterPerson == personB) personAisTaller = 'y';

            if (!visited[shorterPerson]){
                q.push(shorterPerson);
                visited[shorterPerson] = true;
            }

        }

    }

    visited.clear();
    visited.resize(N + 1, false);

    q.push(personB);
    visited[personB] = true;

    //Try the other way around, start from person B and go to person A
    while (!q.empty()){

        int currentPerson = q.front();
        q.pop();

        for (auto shorterPerson: shorter[currentPerson]){

            if (shorterPerson == personA) personAisTaller = 'n';

            if (!visited[shorterPerson]){
                q.push(shorterPerson);
                visited[shorterPerson] = true;
            }

        }

    }

    if (personAisTaller == 'y') std::cout << "yes";

    else if (personAisTaller == 'n') std::cout << "no";

    else std::cout << "unknown";

    return 0;

}