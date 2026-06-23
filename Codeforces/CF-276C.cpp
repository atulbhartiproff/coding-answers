#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> diff(n + 1, 0);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        diff[l - 1]++;
        if (r < n) diff[r]--;
    }

    vector<long long> freq(n);

    long long curr = 0;
    for (int i = 0; i < n; i++) {
        curr += diff[i];
        freq[i] = curr;
    }

    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * freq[i];
    }

    cout << ans << '\n';

    return 0;
}
