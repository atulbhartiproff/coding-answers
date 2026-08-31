#include<bits/stdc++.h>
using namespace std;

vector<long long> solve()
{
    long long n; cin>>n;
    vector<long long> b(n);
    for(auto& i:b) cin>>i;

    vector<long long> temp=b;
    sort(temp.begin(),temp.end());
    if(temp[0]!=0) return {-1};
    if(temp.size()==1) return {1};
    map<long long,long long> mp; mp[temp[0]]=1;
    long long l=0,r=1,sum=0;

    while(r<temp.size())
    {
        if(temp[l]==temp[r]) r++;
        else
         {
             long long target=temp[r]-sum;
             if(target%(r-l)!=0 ) return {-1};
             if(target/(r-l)<mp[temp[l]]) return {-1};
             mp[temp[l]]=target/(r-l);
             mp[temp[r]]=mp[temp[l]]+1;
             sum=temp[r];
             l=r;
             r++;
         }
    }

    vector<long long> ans;
    for(long long i=0;i<n;i++)
    {
        ans.push_back(mp[b[i]]);
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;cin>>t;
    while(t-- >0)
    {
        vector<long long> ans=solve();
        for(long long i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}
