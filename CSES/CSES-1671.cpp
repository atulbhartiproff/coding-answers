#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long>>> adj(n+1,vector<pair<long long,long long>>());
    for(long long i=0;i<m;i++)
    {
        long long l,r,w;
        cin>>l>>r>>w;
        adj[l].push_back({r,w});
        // adj[r].push_back({l,w});
    }
    vector<long long> dis(n+1,LONG_LONG_MAX);
    dis[1]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        long long curr=pq.top().second;
        long long dist=pq.top().first;
        pq.pop();
        if(dist>dis[curr]) continue;
        for(auto it:adj[curr])
        {
            long long next=it.first;
            long long newpath=it.second+dist;
            if(newpath<dis[next])
            {
                dis[next]=newpath;
                pq.push({newpath,next});
            }
        }
    }

    for(long long i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}
