#include<bits/stdc++.h>
using namespace std;

auto comp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vector<pair<int,int>> events(n);
    for(int i=0;i<n;i++) cin>>events[i].first>>events[i].second;

    sort(events.begin(),events.end(),comp);

    // for(auto i:events)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    int cnt=1,last=events[0].second;
    for(auto i:events)
    {
        if(i.first<last) continue;

        cnt++;last=i.second;
    }

    cout<<cnt<<endl;


    return 0;
}
