#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> color(N + 1, -1);

    function<void(int, int)> dfs = [&](int u, int parent) {
        for (auto [v, w] : adj[u]) {
            if (v == parent) continue;

            if (w % 2 == 0)
                color[v] = color[u];
            else
                color[v] = color[u] ^ 1;

            dfs(v, u);
        }
    };

    color[1] = 0;
    dfs(1, -1);

    for (int i = 1; i <= N; i++)
        cout << color[i] << '\n';

    return 0;
}
