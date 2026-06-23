#include<bits/stdc++.h>
using namespace std;


auto comp(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.first==b.first) return a.second<b.second;
    else return a.first<b.first;
}

bool test()
{
    long long N,W;
    cin>>N>>W;
    vector<pair<long long,long long>> events;
    for(long long i=0;i<N;i++)
    {
        long long S,T,P;
        cin>>S>>T>>P;
        events.push_back({S,P});
        events.push_back({T,0-P});
    }

    sort(events.begin(),events.end(),comp);

    long long curr=0;
    for(auto a:events)
    {
        curr+=a.second;
        if(curr>W)
        {
            return false;

        }
    }
    return true;
}

int main()
{
    if(test()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
