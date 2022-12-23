#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N; // # of stations
    int W; // # of walkways
    int D; // # of days

    std::cin >> N;
    std::cin >> W;
    std::cin >> D;

    //Collect walkway inputs
    std::vector<int> walkway_start(W);
    std::vector<int> walkway_stop(W);

    for (int i = 0; i < W; i++){
        std::cin >> walkway_start[i];
        std::cin >> walkway_stop[i];
    }

    //Collect initial subway route
    std::vector<int> subway_route(N);
    for (int i = 0; i < N; i++){
        std::cin >> subway_route[i];
    }

    //Collect daily route changes
    std::vector<int> changes1(D);
    std::vector<int> changes2(D);
    for (int i = 0; i < D; i++){
        std::cin >> changes1[i];
        std::cin >> changes2[i];

        //To match with index number
        changes1[i] -= 1;
        changes2[i] -= 1;
    }

    //Initialise some variables
    int temp;
    int start;
    int time;
    int elements_remaining_per_level;
    std::vector<int> stack;
    std::vector<int> already_visited;
    std::vector<int> times(D, 2147483647);

    //For each day...
    for (int d = 0; d < D; d++){
        //Adjust subway route according to day
        temp = subway_route[changes1[d]];
        subway_route[changes1[d]] = subway_route[changes2[d]];
        subway_route[changes2[d]] = temp;

        /*
        //Testing route changes
        std::cout << '\n';
        for (int i = 0; i < N; i++){
        std::cout << subway_route[i] << " ";
        }
        std::cout << '\n';
        */

        //Breadth first search/Brute force
        for (int i = 0; i < N; i++){
            start = subway_route[i];
            time = i;
            stack.push_back(start);
            elements_remaining_per_level = 1;

            //In case there's no possible walkways
            while (true){

                /*
                //TEST
                for (int u = 0; u < stack.size(); u++){
                    std::cout << stack[u] << " ";
                }
                std::cout << '\n';
                */

                //Find possible initial walkways
                for (int z = 0; z < W; z++){

                    if (walkway_start[z] == stack[0]){

                        if (std::find(already_visited.begin(), already_visited.end(), walkway_start[z]) != already_visited.end()){
                            continue;
                        }

                        else{
                            stack.push_back(walkway_stop[z]);
                        }
                        
                    }

                }

                if (stack[0] == N){

                    if (time < times[d]){
                        times[d] = time;
                    }

                    stack.clear();
                    already_visited.clear();
                    break;
                }

                already_visited.push_back(stack[0]);
                stack.erase(stack.begin());

                //In case of dead end or having fully traversed the tree
                if (stack.size() == 0){
                    already_visited.clear();
                    break;
                }

                elements_remaining_per_level -= 1;

                if (elements_remaining_per_level == 0){
                    time += 1;
                    elements_remaining_per_level = stack.size();
                }

            }

        }

    }

    for (int i = 0; i < times.size(); i++){
        std::cout << times[i] << '\n';
    }


    //Test Print
    /*
    std::cout << '\n';

    for (int i = 0; i < N; i++){
        std::cout << subway_route[i] << " ";
    }

    std::cout << '\n';

    for (int i = 0; i < W; i++){
        std::cout << walkway_start[i] << " " << walkway_stop[i] << '\n';
    }

    for (int i = 0; i < D; i++){
        std::cout << changes1[i] << " " << changes2[i] << '\n';
    }

    std::cout << '\n' << '\n';

    for (int i = 0; i < times.size(); i++){
        std::cout << times[i] << ' ';
    }
    */

    return 0;

}

