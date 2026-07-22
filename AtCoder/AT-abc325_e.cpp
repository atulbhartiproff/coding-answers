#include<bits/stdc++.h>
#include <climits>
using namespace std;

void djikstra(vector<vector<long long>>& vehicle, long long start,vector<long long>& dist)
{
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty())
    {
        long long curr=pq.top().second;
        long long path=pq.top().first;
        pq.pop();

        if(path>dist[curr]) continue;
        for(long long i=0;i<vehicle.size();i++)
        {
            if(i==curr) continue;
            long long newpath=path+vehicle[curr][i];
            if(dist[i]>newpath)
            {
                dist[i]=newpath;
                pq.push({newpath,i});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<vector<long long>> car(n,vector<long long>(n,0));
    vector<vector<long long>> train(n,vector<long long>(n,0));

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            long long temp;
            cin>>temp;
            car[i][j]=temp*a;
            if(i==j)train[i][j]=0;
            else train[i][j]=temp*b+c;
        }
    }

    vector<long long> destc(n,LONG_MAX);
    vector<long long> destt(n,LONG_MAX);
    djikstra(train, n-1,destt);
    djikstra(car, 0, destc);

    long long ans=LLONG_MAX;
    for(long long i=0;i<n;i++)
    {
        ans=min(ans,destc[i]+destt[i]);
    }
    cout<<ans<<endl;
    return 0;


}
