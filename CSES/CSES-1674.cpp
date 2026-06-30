#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int total(vector<vector<int>>& adj,int i,unordered_map<int, int>& mp)
{
    int cnt=adj[i].size();

    for(auto j:adj[i])
    {
        if(mp.find(j)!=mp.end()) cnt+=mp[j];
        else cnt+=total(adj,j,mp);
    }
    mp[i]=cnt;
    return cnt;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=2;i<=n;i++)
    {
        int temp; cin>>temp;
        adj[temp].push_back(i);
    }
    unordered_map<int, int> mp;
    for(int i=1;i<=n;i++)
    {
        if(mp.find(i)!=mp.end()) cout<<mp[i]<<" ";
        else cout<<total(adj,i,mp)<<" ";
    }
    return 0;
}
