#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int result = 0;
  for (int i = 0; i < n; i++) {
    int solution[3];
    int sure = 0;
    for (int j = 0; j < 3; j++) {
      cin >> solution[j];
      if (solution[j] == 1) {
        sure++;
      }
    }
    if (sure >= 2) {
      result++;
    }
  }
  cout << result;
}
