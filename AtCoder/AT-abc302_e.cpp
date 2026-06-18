#include<bits/stdc++.h>
using namespace std;


void insert(map<long long,unordered_set<long long>>& mp,long long x, long long y,long long& cnt)
{
    mp[x].insert(y);
    mp[y].insert(x);
    if(mp[x].size()==1) cnt--;
    if(mp[y].size()==1) cnt--;
}

void rem(map<long long,unordered_set<long long>>& mp,long long x, long long& cnt)
{
    if(mp[x].empty()) return;

    for(auto i:mp[x])
    {
        if(mp[i].size()==1) cnt++;
        mp[i].erase(x);
    }
    mp[x].clear();
    cnt++;
}

int main()
{
    long long n,q;
    cin>>n>>q;
    map<long long,unordered_set<long long>> mp;
    long long cnt=n;
    for(long long i=0;i<q;i++)
    {
        long long m;
        cin>>m;
        if(m==1)
        {
            long long x,y;
            cin>>x>>y;
            insert(mp,x,y,cnt);
            cout<<cnt<<endl;
        }

        if(m==2)
        {
            long long x;
            cin>>x;
            rem(mp,x,cnt);
            cout<<cnt<<endl;
        }
    }
    return 0;
}
