#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        int l,r; cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    queue<int> q;
    vector<int> par(n+1,-1);
    vector<bool> vis(n+1,false);
    q.push(1);
    vis[1]=true; bool flag=false;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int i:adj[curr])
        {
            if(vis[i]==true) continue;
            par[i]=curr;
            if(i==n)
            {
                flag=true;
                break;
            }
            q.push(i);
            vis[i]=true;
        }
        if(flag) break;
    }

    if(par[n]==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    int curr=n;
    while(curr!=1)
    {
        path.push_back(curr);
        curr=par[curr];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(int i:path) cout<<i<<" ";
    cout<<endl;
 return 0;
}
