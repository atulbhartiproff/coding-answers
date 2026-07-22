#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin>>n;
    vector<vector<pair<long long,long long>>> adj(n+1,vector<pair<long long,long long>>());
    for(long long i=1;i<n;i++)
    {
        long long a,b,x;
        cin>>a>>b>>x;
        adj[i].push_back({a,i+1});
        adj[i].push_back({b,x});
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

        if(dis[curr]<dist) continue;
        for(auto it:adj[curr])
        {
            long long newpath=dist+it.first;
            long long next=it.second;
            if(newpath<dis[next])
            {
                dis[next]=newpath;
                pq.push({newpath,next});
            }
        }
    }

    cout<<dis[n]<<endl;
    return 0;
}
