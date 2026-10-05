#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long x,y,k;
    cin>>x>>y>>k;

    long long diff=y-x;
    long long ans=0;
    long long cnt=min(k,max(0LL,diff-x+1));

    for(long long i=0;i<cnt;i++)
    {
        ans+=diff%(x+i);
    }
    ans+=(k-cnt)*diff;
    cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
