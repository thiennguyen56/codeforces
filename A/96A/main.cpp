#include <iostream>

using namespace std;

int main() {
  string input;
  cin >> input;
  int count = 1;
  for (int i = 1; i < (int)input.size(); i++) {
    if (input[i] == input[i - 1]) {
      count++;
      if (count >= 7) {
        cout << "YES";
        return 0;
      }
    } else {
      count = 1;
    }
  }
  cout << "NO";
}
