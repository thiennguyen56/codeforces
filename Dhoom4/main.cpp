#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
int key_value, lock_value;
int n;
vector<ll> adj;
ll dist[100005];

void init() {
  for (ll i = 0; i < 100005; i++) {
    dist[i] = -1;
  }
}

void BFS(ll start) {
  queue<ll> myqueue;
  myqueue.push(start);
  dist[start] = 0;
  while (!myqueue.empty()) {
    ll u = myqueue.front();
    myqueue.pop();
    if (u == lock_value) {
      break;
    }
    for (ll i = 0; i < (ll)adj.size(); i++) {
      ll v = (u * adj[i]) % 100000;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        myqueue.push(v);
      }
    }
  }
}

int main() {
  cin >> key_value >> lock_value;
  cin >> n;

  init();
  for (ll i = 1; i <= n; i++) {
    ll u;
    cin >> u;
    adj.push_back(u);
  }

  BFS(key_value);
  cout << dist[lock_value];
}
