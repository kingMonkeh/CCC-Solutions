/*

2007 S3 - Friends

Difficulty: Easy

This problem is a very simple Depth First Search problem.
All you have to do is start from the initial person and perform DFS until you reach this initial person again.
If you can't reach them, it's impossible. As you're on the path, keep track of the level of separation, since this will also let you know if there the other person is in the circle or not.
Afterwards, output answer accordingly.

*/

#include <iostream>
#include <vector>
#include <stack>

int main(){

    int n;
    std::cin >> n;

    //Technically, a map would be much better, but from what I've read in the DMOJ comment section, there are troll cases where one person is not assigned a friend at all, thus producing key errors
    std::vector<std::vector<int>> friends (10000); //friends[i] contains a vector storing who [i] must be friends with

    //Store friendships, remember they're one directional
    for (int i = 0; i < n; i++){

        int personA, personB; std::cin >> personA >> personB;
        friends[personA].push_back(personB);

    }

    //For the remaining queues
    while (true){

        int personA, personB; std::cin >> personA >> personB;

        //Termination of input
        if (personA == 0 && personB == 0){
            break;
        }

        //DFS will allow us to find a circle of friends, there's no need to worry about multiple circle of friends since every person can only have one friend
        std::stack<int> s; //Stack allows Last in First out and is used for DFS
        std::vector<bool> visited (10000, false); //Mark which nodes have been visited
        std::vector<int> separation (10000, -1); //Level of separation
        s.push(personA); visited[personA] = true; //Initialize

        int count = 0; //To count whether or not personA has been found again, aka a circle of friends is possible

        while (!s.empty()){

            int current_person = s.top();
            s.pop();

            //To deal with the troll case, in the original CEMC test data, you wouldn't have to worry, but DMOJ wants to be different
            if (friends[current_person].size() > 0){

                //I actually don't think you need to mark which nodes are visited since the edges are one-directional, but it's habit for me
                if (!visited[friends[current_person][0]]){
                    s.push(friends[current_person][0]); //Add to stack
                    visited[friends[current_person][0]] = true;
                    separation[friends[current_person][0]] = separation[current_person] + 1; //Separation of next node is equal to separation of current node + 1
                }

                //If we've made it back at personA, aka a circle of friends is made
                else if (friends[current_person][0] == personA){
                    count++;
                    break;
                }
                
            }

            

        }

        //If a circle of friends exist and personB is apart of this circle, output the answer
        if (separation[personB] > -1 && count == 1){
            std::cout << "Yes " << separation[personB] << '\n';
        }

        //Otherwise
        else{
            std::cout << "No" << '\n';
        }

    }

    return 0;
    
}