#include <algorithm>
#include<bits/stdc++.h>
#include <functional>
using namespace std;

int dia (vector<vector<int>>& adj,vector<bool>& vis, int i,int& diameter)
{
    vis[i]=true;
    vector<int> len;
    for(int j:adj[i])
    {
        if(vis[j]) continue;
        len.push_back(dia(adj,vis,j,diameter));
    }
    sort(len.begin(),len.end(),greater());
    if(len.size()==1) diameter=max(diameter,len[0]+1);
    else if (len.size()>1) diameter=max(diameter,len[0]+len[1]+2);
    // cout<<i<<" "<<len.size()<<endl;
    if(len.size()!=0)return *max_element(len.begin(),len.end())+1;
    return 0;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int r,c;cin>>r>>c;
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    // cout<<"---"<<endl;
    int diameter=0;
    vector<bool> vis(n+1,false);
    if(dia(adj,vis,1, diameter)) cout<<"";
        cout<<diameter<<endl;
    return 0;
}
