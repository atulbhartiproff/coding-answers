#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << 0 << endl;
    return 0;
  }
  vector<bool> vis(20001, false);
  queue<pair<int, int>> q;
  q.push({n, 0});
  vis[n] = true;
  while (!q.empty()) {
    int curr = q.front().first;
    int push = q.front().second;

    if (curr * 2 == m) {
      cout << push + 1 << endl;
      return 0;
    }
    if (curr - 1 == m) {
      cout << push + 1 << endl;
      return 0;
    }

    q.pop();

    if (curr - 1 > 0 && vis[curr - 1] == false) {
      q.push({curr - 1, push + 1});
      vis[curr - 1] = true;
    }
    if (curr * 2 <= 20000 && vis[curr * 2] == false) {
      q.push({curr * 2, push + 1});
      vis[curr * 2] = true;
    }
  }
  cout << -1 << endl;
  return 0;
}
