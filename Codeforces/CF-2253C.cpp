#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long t;
  cin >> t;
  while (t-- > 0) {
    // cout<<"Testcase "<<t<<endl;
    long long n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<long long> a(x);
    vector<long long> b(y);
    for (auto &i : a) {
      cin >> i;
    }
    for (auto &i : b) {
      cin >> i;
    }
    long long ka = min(n, x), kb = min(m, y);
    long long K = min(ka + kb, n + m - 1);
    long long total_sum = 0;
    long long cnt_A = 0, cnt_B = 0;
    long long tc = 0;
    long long i = x - 1, j = y - 1;
    while ((i >= 0 || j >= 0) && tc < K) {
      long long val;
      long long ty;
      if (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
          val = a[i];
          ty = 3;
          i--;
          j--;
        } else if (a[i] > b[j]) {
          val = a[i];
          ty = 1;
          i--;
        } else {
          val = b[j];
          ty = 2;
          j--;
        }
      } else if (i >= 0) {
        val = a[i];
        ty = 1;
        i--;
      } else {
        val = b[j];
        ty = 2;
        j--;
      }
      // cout<<ty<<endl;
      if (ty == 1) {
        if (cnt_A < ka) {
          cnt_A++;
          tc++;
          total_sum += val;
        }
      } else if (ty == 2) {
        if (cnt_B < kb) {
          cnt_B++;
          tc++;
          total_sum += val;
        }
      } else if (ty == 3) {
        tc++;
        total_sum += val;
      }
      // cout<<"COunt A: "<<cnt_A;
      // cout<<"Count B: "<<cnt_B;
    }
    // cout << "ANSWER: " << endl;
    cout << total_sum << endl;
  }
  return 0;
}
