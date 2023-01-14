#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string word;
    cin >> word;
    if ((int)word.length() <= 10) {
      cout << word << endl;
    } else {
      int count = 0;
      for (int i = 0; i < (int)word.length(); i++) {
        if (i == 0) {
          cout << word[i];
        } else if (i == (int)word.length() - 1) {
          cout << count << word[word.length() - 1] << endl;
        } else {
          count++;
        }
      }
    }
  }
}
