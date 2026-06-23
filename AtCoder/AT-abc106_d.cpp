#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long answer(vector<vector<long long>> &trains, long long r1, long long c1,
                 long long r2, long long c2) {
  long long top = 0, left = 0, last = 0, add = 0;

  if (r1 > 0)
    top = trains[r1 - 1][c2];
  if (c1 > 0)
    left = trains[r2][c1 - 1];
  if (r1 > 0 && c1 > 0)
    add = trains[r1 - 1][c1 - 1];
  last = trains[r2][c2];
  return last + add - top - left;
}

int main() {
  long long N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<long long>> trains(N + 1, vector<long long>(N + 1.0));
  for (long long i = 0; i < M; i++) {
    long long l, r;
    cin >> l >> r;
    trains[l][r] += 1;
  }
  for (long long i = 1; i <= N; i++) {
    for (long long j = 1; j <= N; j++) {
      trains[i][j] = trains[i - 1][j] + trains[i][j - 1] + trains[i][j] -
                     trains[i - 1][j - 1];
    }
  }

  for (long long i = 0; i < Q; i++) {
    long long l, r;
    cin >> l >> r;
    cout << answer(trains, l, l, r, r) << endl;
  }

  return 0;
}
