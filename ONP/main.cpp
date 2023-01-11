#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solve() {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    cin >> s;
    stack<char> mystack;
    for (int i = 0; i < (int)s.size(); i++) {
      if ('a' <= s[i] && s[i] <= 'z') {
        cout << s[i];
      } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ||
                 s[i] == '^') {
        mystack.push(s[i]);
      } else if (s[i] == ')') {
        cout << mystack.top();
        mystack.pop();
      }
    }
    cout << endl;
  }
}

int main() { solve(); }
