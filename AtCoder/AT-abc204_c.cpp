#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, set<pair<int,int>> &st,
         vector<int> &vis, int src, int u)
{
    if (vis[u]) return;
    vis[u] = 1;

    st.insert({src, u});

    for (int v : adj[u])
        dfs(adj, st, vis, src, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    set<pair<int,int>> st;

    for (int i = 1; i <= n; i++)
    {
        vector<int> vis(n + 1, 0);
        dfs(adj, st, vis, i, i);
    }

    cout << st.size() << '\n';
    return 0;
}
