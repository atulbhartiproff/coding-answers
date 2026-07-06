#include<bits/stdc++.h>
using namespace std;

void assign(int i,int curr, vector<vector<int>>& adj,vector<int>& ans,bool& flag)
{
    if(flag==false) return;
    ans[i]=curr;
    if(curr==1) curr=2;
    else curr=1;
    for(int j:adj[i])
    {
        if(ans[j]==ans[i])
        {
            flag=false;
            return;
        }
        if(ans[j]!=0) continue;
        assign(j,curr,adj,ans,flag);
    }
}

int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        int l,r; cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    vector<int> ans(n+1,0); int curr=1;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            assign(i,curr,adj,ans,flag);
        }
        if(!flag) break;
    }
    if(flag)
    {
        for(int i=1;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    }
    else {
    cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
