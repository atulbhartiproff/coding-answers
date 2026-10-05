#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    string s; cin>>s;

    int ans=0;

    for(int i=0;i<n;i=i+k)
    {
        bool ones=true;

        for(int j=i;j<i+k;j++)
        {
            if(s[j]=='0')
            {
                ones=false;
                break;
            }
        }
        if(ones) ans++;
    }
    cout<<ans<<endl;
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
