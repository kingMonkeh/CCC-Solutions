/*

2000 J5/S3 - Surfing

Difficulty: Easy/Medium

This problem is very interesting, it's not too difficult however with the easy test data.

General idea:
Search for "HREF" in the each website, output the websites as you come across them. Save them somewhere so that you can perform DFS later.
Afterwards, for each query, just perform DFS or BFS to find if two sites connect. Output answer accordingly.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

int main(){

    int n; std::cin >> n;

    std::unordered_map<std::string, std::vector<std::string>> connections; //connections[i] is a vector containing all links that connect to site i

    //For each site
    for (int i = 0; i < n; i++){

        std::string current_site; //Name of site
        std::cin >> current_site;

        connections[current_site] = {}; //Initialize vector

        std::string text; //Random chunk of text
        while (true){

            std::cin >> text; //Remember that cin terminates at white space or new line, so I can't check for "<A". Note that you can use std::getline() to obtain a full line of text, but this is unnecessary

            //If end of website
            if (text == "</HTML>"){
                break;
            }
                
            //If it's a link to a URL
            if (text.substr(0, 6) == "HREF=\""){

                std::string url;

                for (int j = 6; j < text.length(); j++){

                    //URL terminates with " so we can use that to tell when to stop
                    if (text[j] != '"'){
                        url += text[j];
                    }

                    else{
                        break;
                    }

                }
                
                connections[current_site].push_back(url); //Add connection
                std::cout << "Link from " << current_site << " to " << url << '\n'; //Output site on the spot

            }

        }

    }

    //For the remaining queries
    while (true){

        std::string start_site, target_site;
        std::cin >> start_site;

        //Remember that cin stops at white space
        if (start_site == "The"){
            break;
        }

        std::cin >> target_site;

        //Perform DFS
        std::stack<std::string> s;
        std::unordered_map<std::string, bool> visited; //Keep track of visited, if a key has not been manually created, it will default to false
        s.push(start_site);

        bool possible = false; //Determine if you can surf from start_site to target_site

        while (!s.empty()){

            std::string current_site = s.top();
            s.pop();

            //For all connecting sites
            for (std::string url: connections[current_site]){

                //If not already visited
                if (!visited[url]){

                    s.push(url); visited[url] = true; //Mark visited

                    //If we hit the target site
                    if (url == target_site){
                        possible = true;
                        break;
                    }

                }

            }

        }

        //If it's possible, remember to add period to the end of each URL, this can easily cause you WA
        if (possible){
            std::cout << "Can surf from " << start_site << " to " << target_site << '.' << '\n';
        }

        //Otherwise
        else{
            std::cout << "Can't surf from " << start_site << " to " << target_site << '.' << '\n';
        }

    }

    return 0;

}