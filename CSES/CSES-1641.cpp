#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

auto comp(pair<int,int> a, pair<int,int> b)
{
    return a.first<b.first;
}

vector<long long> test(vector<long long> &arr, long long x, long long n) {

    vector<pair<int,int>> sorted(n);
    for(long long i=0;i<n;i++)
    {
        sorted[i].first=arr[i];
        sorted[i].second=i;
    }
    sort(sorted.begin(),sorted.end());

    for(long long i=0;i<n-1;i++)
    {
        long long l=i+1;
        long long r=n-1;
        while(l<r)
        {
            long long sum=sorted[i].first+sorted[l].first+sorted[r].first;
            if(sum==x) return {sorted[i].second,sorted[l].second,sorted[r].second};
            if(sum>x) r--;
            else l++;
        }
    }

  return {-1, -1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  long long n, x;
  cin >> n >> x;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<long long> ans = test(arr, x, n);
  if (ans[0] == -1)
    cout << "IMPOSSIBLE" << endl;
  else {
      sort(ans.begin(),ans.end());
    for (long long a : ans) {
      cout << a+1 << " ";
    }
  }
  return 0;
}
