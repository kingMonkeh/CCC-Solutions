#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct point{
    long long x, y;
};

int main (){

    int N, K;
    std::cin >> N >> K;
    std::vector<point> points (N);
    for (int i = 0; i < N; i++){
        std::cin >> points[i].x >> points[i].y;
    }

    if (K == 1){
        std::cout << "Infinity\n";
        return 0;
    }

    //Once we check a line, we dont want to check that same line again, therefore every pair of points, which we can also view as a line, should be marked as visited once searched
    std::vector<std::vector<int>> vis (N, std::vector<int> (N, false));
    std::map<long long, int> xvis; //Vertical line vis array
    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (vis[j][i]) continue;
            //y = mx + b, check number of points on this line
            int cnt = 0;
            if (points[i].x - points[j].x != 0){
                std::vector<int> collinear;
                for (int k = 0; k < N; k++){
                    //if 3 points on the line, the slope between the first two points should equal the slope between the last 2 points, its up to the reader to prove this equation below
                    if ((points[i].y - points[j].y) * (points[j].x - points[k].x) == (points[j].y - points[k].y) * (points[i].x - points[j].x)){
                        cnt++;
                        collinear.push_back(k);
                    }
                } 
                //mark visited
                int s = collinear.size();
                for (int l = 0; l < s; l++) for (int m = l + 1; m < s; m++){
                    vis[collinear[l]][collinear[m]] = true; vis[collinear[m]][collinear[l]] = true;
                };
            }
            else{
                if (!xvis[points[i].x]){
                    for (int k = 0; k < N; k++){
                        if (points[k].x == points[i].x) cnt++;
                    }
                }
                xvis[points[i].x] = true;
            }
            if (cnt >= K) ans++;
        }
    }

    std::cout << ans << '\n';

    return 0;
    
}