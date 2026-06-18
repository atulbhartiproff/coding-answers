#include <bits/stdc++.h>
using namespace std;

void printScores(vector<pair<int, int>> &time, int N, int T) {
  int types = 1;
  map<long long, int> cnt;
  map<int, long long> score;

  cnt[0] = N;

  for (auto [A, B] : time) {
    long long old = score[A];

    cnt[old]--;
    if (cnt[old] == 0)
      types--;

    score[A] += B;
    long long nw = score[A];

    if (cnt[nw] == 0)
      types++;
    cnt[nw]++;

    cout << types << '\n';
  }
}

int main() {
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> timearr;
  for (int i = 0; i < T; i++) {
    int A, B;
    cin >> A >> B;
    timearr.push_back({A, B});
  }
  printScores(timearr, N, T);
  return 0;
}
