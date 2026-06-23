#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,c;
    cin>>n>>c;
    map<long long,long long> mp;
    long long endterm=-1;
    for(long long i=0;i<n;i++)
    {
        long long a,b,d;
        cin>>a>>b>>d;
        mp[a]+=d;
        mp[b+1]-=d;
        endterm=max(endterm,b+1);
    }

    long long curr=0;
    long long total=0;
    long long last=-1;
    for(auto it:mp)
    {
        if(last==-1)
        {
            last=it.first;
            curr=it.second;
            continue;
        }
        // cout<<it.first<<" "<<it.second<<"\n"<<last<<" "<<curr<<" ";
        long long tenure=(it.first-last);
        // cout<<tenure<<" ";
        // cout<<curr<<" ";
        if(curr>c)tenure*=c;
        else tenure*=curr;
        // cout<<tenure<<" "<<endl;
        total+=tenure;

        last=it.first;
        curr+=it.second;
    }

    cout<<total<<endl;

    return 0;
}
