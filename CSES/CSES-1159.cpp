#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> pr(n);
  vector<int> pg(n);
  vector<int> cp(n);

  for (auto &i : pr)
    cin >> i;

  for (auto &i : pg)
    cin >> i;

  for (auto &i : cp)
    cin >> i;

  // Convert multiple copies into 0/1 groups
  vector<int> cost;
  vector<int> value;

  for (int i = 0; i < n; i++) {
    int copies = cp[i];
    int power = 1;

    while (copies - power >= 0) {
      cost.push_back(power * pr[i]);
      value.push_back(power * pg[i]);

      copies -= power;
      power *= 2;
    }

    // Remaining copies
    if (copies > 0) {
      cost.push_back(copies * pr[i]);
      value.push_back(copies * pg[i]);
    }
  }

  int m = cost.size();

  vector<vector<int>> dp(m + 1, vector<int>(x + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i - 1][j];

      if (j >= cost[i - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i - 1]] + value[i - 1]);
      }
    }
  }

  cout << dp[m][x] << '\n';

  return 0;
}
