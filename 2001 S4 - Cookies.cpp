/*

2001 S4 - Cookies

Difficulty: Medium

This problem is another annoying gemoetry problem
It's not actually that hard, but i forgot to square root my answer which caused me to waste 2+ hours on this problem

Basic idea:

For every triplet of points:

If the the points form a right angled triangle or acute angled triangle, we will find the circumradius of that triangle
via perpendicular bisectors. We will use the formula of abc / 4 * area of ABC to find the circumradius

I reccomend the following video to help you understand how this formula works
https://www.khanacademy.org/math/geometry-home/triangle-properties/perpendicular-bisectors/v/area-circumradius-formula-proof

Otherwise, if the triangle formed is obtuse, the diameter of the circle must be the longest length of that triangle

*/

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>

int main(){

    int n; std::cin >> n;

    //Store coordinates
    std::vector<double> x (n);
    std::vector<double> y (n);

    for (int i = 0; i < n; i++){
        std::cin >> x[i] >> y[i];
    }

    double circumradius = 0; //Circumardius, technically this is actually storing the diameter, but we ignore that part

    //For each triplet of points
    for (int i = 0; i < n; i++){

        for (int j = i + 1; j < n; j++){

            for (int k = j + 1; k < n; k++){

                //The formula for circumradius is abc/4*area of triangle ABC where a, b and c are the side lengths of triangle ABC

                //Calculate side lengths of each side

                double IJ, JK, KI;
                IJ = std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                JK = std::sqrt((x[k] - x[j]) * (x[k] - x[j]) + (y[k] - y[j]) * (y[k] - y[j]));
                KI = std::sqrt((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]));

                //If the triangle formed by the three points is obtuse, then the diameter of the circle is actually the length of the longest side
                std::vector<double> sides;
                sides.push_back(IJ); sides.push_back(JK); sides.push_back(KI);
                std::sort(sides.begin(), sides.end());
                //We know if its obtuse by pythagorean theorem if a^2 + b^2 < c^2, then it must be obtuse
                if (sides[0] * sides[0] + sides[1] * sides[1] < sides[2] * sides[2]){
                    if (sides[2] > circumradius) circumradius = sides[2]; //Only change if it's greater than
                }

                //Otherwise, the triangle must be acute or right angle
                else{

                    //Determine the height of the triangle so that we can find area,
                    //To do this, we will first find slope of IJ, then we will find perpendicular slope
                    //With this perpendicular slope, we make sure it passes through point K and then we determine its point of intersection with IJ
                    //Afterward, we calculate distance between point of intersection and point K
                    double slope, perpslope, height;
                    //Diagonal line, aka normal slope
                    if (x[i] - x[j] != 0 && y[i] - y[j] != 0){
                        slope = (y[i] - y[j]) / (x[i] - x[j]); //Slope of IJ
                        double b1 = y[i] - slope * x[i]; //y=mx+b, b value for line IJ
                        perpslope = -1/slope; //perpendicular line just has negative reciprocal for slope
                        double b2 = y[k] - perpslope * x[k]; //Solve for b with the perpendicular line such that it passes through K

                        double POIx = (b1 - b2) / (perpslope - slope); //Get their point of intersection, I will leave this as an exercise for you, hint just rearrange a linear system
                        double POIy = slope * POIx + b1;

                        height = std::sqrt((POIx - x[k]) * (POIx - x[k]) + (POIy - y[k]) * (POIy - y[k]));

                    }

                    //Vertical line case, if IJ is vertical
                    if (x[i] - x[j] == 0){
                        height = std::abs(x[i] - x[k]);
                    }

                    //Horizontal line, if IJ is horizontal
                    if (y[i] - y[j] == 0){
                        height = std::abs(y[i] - y[k]);
                    }

                    //Use our information to find circumradius by plugging into the formula
                    double area = IJ * height / 2; //Area of triangle
                    double abc = IJ * JK * KI; //The side lengths multiplied
                    if ((abc / (4 * area)) * 2 > circumradius){
                        circumradius = (abc / (4 * area)) * 2;
                    }

                }

            }

        }
        
    }

    //Output to two decimal places
    std::cout << std::fixed << std::setprecision(2) << circumradius << '\n';

    return 0;

}