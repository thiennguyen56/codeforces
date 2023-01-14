#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int testCase = 0;
  while (true) {
    int P, C;
    cin >> P >> C;
    if (P == 0 && C == 0) {
      return;
    }
    testCase++;
    cout << "Case " << testCase << ":" << endl;
    queue<int> myqueue;
    for (int i = 1; i <= C && i <= P; i++) {
      myqueue.push(i);
    }
    for (int i = 1; i <= C; i++) {
      char command;
      cin >> command;
      if (command == 'N') {
        int patient = myqueue.front();
        myqueue.pop();
        cout << patient << endl;
        myqueue.push(patient);
      } else {
        vector<int> tmp;
        int priority;
        cin >> priority;
        while (!myqueue.empty()) {
          int patient = myqueue.front();
          myqueue.pop();
          if (patient != priority) {
            tmp.push_back(patient);
          }
        }
        myqueue.push(priority);
        for (int i = 0; i < (int)tmp.size(); i++) {
          myqueue.push(tmp[i]);
        }
      }
    }
  }
}

int main() {
  solve();
  return 0;
}
