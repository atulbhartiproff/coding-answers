#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    string st; cin>>st;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(st[i-1]==st[i]) continue;
        ans++;
    }
    ans++;
    int minus=0;
    for(int i=1;i<n-1;i++)
    {
        if(st[i-1]!=st[i] && st[i]!=st[i+1])
        {
            if(st[i-1]==st[i+1]) {minus=2;break;}
            else minus=1;
        }
    }
    cout<<ans-minus<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
