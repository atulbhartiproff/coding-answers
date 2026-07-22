#include<bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;

void djikstra(vector<vector<pair<long long,long long>>>& adj, vector<long long>& dist, long long s)
{
    long long n=adj.size()-1;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,s});
    dist[s]=0;

    while(!pq.empty())
    {
        long long curr=pq.top().second;
        long long path=pq.top().first;
        pq.pop();
        if(dist[curr]<path) continue;

        for(auto it:adj[curr])
        {
            long long next=it.second;
            long long newpath=it.first+path;
            if(newpath<dist[next])
            {
                dist[next]=newpath;
                pq.push({newpath,next});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long>>> adj(n+1,vector<pair<long long,long long>>());
    vector<vector<pair<long long,long long>>> rev(n+1,vector<pair<long long,long long>>());
    vector<vector<long long>> edges;
    for(long long i=0;i<m;i++)
    {
        long long l,r,w;
        cin>>l>>r>>w;
        adj[l].push_back({w,r});
        rev[r].push_back({w,l});
        edges.push_back({l,r,w});
    }
    vector<long long> distf(n+1,LLONG_MAX);
    vector<long long> distb(n+1,LLONG_MAX);
    djikstra(adj, distf,1);
    cout<<endl;
    djikstra(rev, distb,n);
    long long ans=distf[n];
    for(auto i:edges)
    {
        if (distf[i[0]] == LLONG_MAX || distb[i[1]] == LLONG_MAX) continue;
        ans=min(ans,distf[i[0]]+(i[2]/2)+distb[i[1]]);
    }
    cout<<ans<<endl;
    return 0;
}
