#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

  int N;
  std::cin >> N;

  double pos [N];
  double walkspeed [N];
  double hearingdist [N];

  double P;
  double W;
  double D;
  
  for (int i = 0; i < N; i++){
    std::cin >> P;
    pos[i] = P;
    std::cin >> W;
    walkspeed[i] = W;
    std::cin >> D;
    hearingdist[i] = D;
    
  }

  /*
  
  //TEST DATA

  std::cout << '\n';
  
  for (int i = 0; i < N; i++){
    std::cout << pos[i] << " ";    
  }

  std::cout << '\n';
  
  for (int i = 0; i < N; i++){
    std::cout << walkspeed[i] << " ";    
  }

  std::cout << '\n';
  
  for (int i = 0; i < N; i++){
    std::cout << hearingdist[i] << " ";    
  }

  // TEST OUTPUT END

  */

  // MIN MAX

  double min = pos[0], max = pos[0];
  
  for (int i = 1; i < N; i++){
    // MIN CHECK
    if (pos[i] < min){
      min = pos[i];
    }
    //MAX CHECK
    if (pos[i] > max){
      max = pos[i];
    }
  }
  
  /*
  
  //TEST MIN MAX
  std::cout << '\n';
  std::cout << "Min is " << min << '\n' << "Max is " << max;

  */

//////////////////////////////////////////////////////////////////////////
  
  /*

  Binary Search Algorithm, RANGE(MIN, MAX)
  Notice that if you were to graph out the walking time relative to the concert position, it would form a u shape and in rare cases an exponential funcion. 
  This is why the binary search algorithm works in this case because you can safely rule out one half of the graph depending on which side is greater or less than the midpoint. 
  Another special case you must account for is if at the bottom of the curve, there's a flat line in which successive concert positions all result in the minimum time.
  
  */

  //c rep concert position
  double dist;
  double time = 0;
  double shortest_time = 9.0071993e+15;

  int midpoint;
  int mleft;
  int mright;

  std::vector<double> times;
  
  while (true){
    midpoint = (min + max)/2;
    mleft = midpoint - 1;
    mright = midpoint + 1;

    for (double c = mleft; c <= mright; c++){
    //ITERATE OVER EACH POSITION
      for (int p = 0; p < N; p++){
        //CHECK DISTANCE BETWEEN POS AND C
        dist = std::abs(pos[p] - c);
  
        //IF NOT IN HEARING RANGE
        if (dist > hearingdist[p]){
          //ADD TIME FOR EACH POS IF NECESSARY
          time += (dist - hearingdist[p]) * walkspeed[p];
        }
      }
  
      times.push_back(time);
        
      //CLEAN UP FOR NEXT ITERATION
      time = 0;
    
    }

    if (times[0] < times[1] && times [1] < times[2]){
      max = midpoint;
    }

    if (times[0] > times[1] && times [1] > times[2]){
      min = midpoint;
    }

    if (times[0] >= times[1] && times [1] <= times[2]){
      break;
    }

    times.clear();
    
  }
  
  

  /*
  
  // OUTPUT TEST RESULTS

  int range = max - min;
  
  std::cout << '\n';
  
  for (int i = 0; i < range; i++){
    std::cout << times[i] << " ";    
  }

  */

  std::cout<< std::fixed << std::setprecision(0) << times[1];
  
  return 0;
}