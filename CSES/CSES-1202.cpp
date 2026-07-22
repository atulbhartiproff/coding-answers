#include<bits/stdc++.h>
#include <climits>
using namespace std;

void djikstra(vector<vector<pair<long long,long long>>>& adj, vector<long long>& dest, long long n,vector<long long>& ways,vector<long long>& mx,vector<long long>& mn)
{
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,n});
    dest[n]=0;
    ways[n]=1;
    mn[n]=0;
    mx[n]=0;
    while(!pq.empty())
    {
        long long curr=pq.top().second;
        long long path=pq.top().first;
        pq.pop();

        if(path>dest[curr]) continue;

        for(auto i:adj[curr])
        {
            long long next=i.second;
            long long newpath=i.first+path;

            if(newpath<dest[next])
            {
                dest[next]=newpath;
                ways[next]=ways[curr];
                mn[next]=mn[curr]+1;
                mx[next]=mx[curr]+1;
                pq.push({newpath,next});
            }
            else if(newpath==dest[next])
            {
                ways[next]=(ways[curr]+ways[next])%(long long)(1e9+7);
                mn[next]=min(mn[next],mn[curr]+1);
                mx[next]=max(mx[next],mx[curr]+1);
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

    for(long long i=0;i<m;i++)
    {
        long long l,r,w;
        cin>>l>>r>>w;
        adj[l].push_back({w,r});
    }

    vector<long long> dest(n+1,LLONG_MAX);
    vector<long long> ways(n+1,0);
    vector<long long> mn(n+1,LLONG_MAX);
    vector<long long> mx(n+1,0);
    djikstra(adj,dest,1,ways,mx,mn);
    cout<<dest[n]<<" "<<ways[n]<<" "<<mn[n]<<" "<<mx[n]<<endl;
    return 0;
}
