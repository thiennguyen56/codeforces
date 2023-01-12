#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  queue<int> myqueue;
  cin >> n;
  if (n < 1) {
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    myqueue.push(i);
  }

  cout << "Discarded cards: ";
  while ((int)myqueue.size() > 1) {
    cout << myqueue.front() << " ";
    myqueue.pop();
    myqueue.push(myqueue.front());
    myqueue.pop();
  }
  cout << endl;
  cout << "Remaining card:" << myqueue.front();
}
