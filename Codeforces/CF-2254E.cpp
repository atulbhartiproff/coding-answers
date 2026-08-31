#include<bits/stdc++.h>
using namespace std;

vector<long long> solve()
{
    long long n; cin>>n;
    vector<long long> b(n);
    for(auto& i:b) cin>>i;
    map<long long,long long> mp;
    for(long long i:b)
    {
        mp[i]++;
    }

    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        if(i==0)
        {
            auto it=mp.upper_bound(0);
            if(it==mp.end()) return {-1};

            long long val=it->first;
            a[i]=val;
            mp[val]--;
            if(mp[val]==0) mp.erase(val);
        }
        else
        {
            auto it=mp.upper_bound(-a[i-1]);
            if(it==mp.end()) return {-1};

            long long val=it->first;
            a[i]=val+a[i-1];
            mp[val]--;
            if(mp[val]==0) mp.erase(val);
        }
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;cin>>t;
    while(t-- >0)
    {
        vector<long long> ans=solve();
        for(auto& i:ans) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
