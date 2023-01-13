#include <iostream> 
#include <stack> 
#include <vector> 

using namespace std; 

void solve() {
  while (true) {
    int n; 
    cin >> n;
    if (n == 0) {
      return; 
    }
    vector <int> a(n + 3, 0); 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    int currentTruck = 1;
    stack <int> mystack;  
    for (int i = 1; i <= n; i++) {
      while (mystack.empty() == false && mystack.top() == currentTruck) {
        currentTruck++; 
        mystack.pop(); 
      }  
      if (currentTruck == a[i]) {
        currentTruck++;  
      }
      else {
        mystack.push(a[i]); 
      }
    }
    while (mystack.empty() == false && mystack.top() == currentTruck) {
      currentTruck++; 
      mystack.pop();
    }
    if (currentTruck > n) {
      cout << "yes" << endl; 
    }
    else {
      cout << "no" << endl; 
    }
  }  
}

int main () {
  solve(); 
  return 0; 
}