#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i)
{
    vis[i]=true;

    for(int j:adj[i])
    {
        if(vis[j]) continue;
        dfs(adj,vis,j);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());

    for(int i=0;i<m;i++)
    {
        int l,r; cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    vector<bool> vis(n+1,false);
    int cnt=-1;
        int last=0;
        vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            cnt++;
            dfs(adj,vis,i);
            if(cnt>0) ans.push_back({last,i});
            last=i;
        }
    }
    cout<<cnt<<endl;
    for(auto i:ans)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
