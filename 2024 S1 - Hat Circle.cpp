#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> hats (n);
  for (int i = 0; i < n; i++){
    std::cin >> hats[i];
  }
  int ans = 0;
  for (int i = 0; i < n / 2; i++){
    if (hats[i] == hats[i + n / 2]){
      ans += 2;
    }
  }
  std::cout << ans;
}