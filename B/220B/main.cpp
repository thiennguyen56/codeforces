#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  std::cout << std::setprecision(12) << std::fixed;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double current_drink;
    cin >> current_drink;
    if (current_drink > 0) {
      sum += current_drink / n;
    }
  }
  cout << sum;
}
