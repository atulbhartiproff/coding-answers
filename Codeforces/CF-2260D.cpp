#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    string st;cin>>st;

    bool imp=false,need2=false;

    for(int i=1;i<n;i++)
    {
        if(st[i]=='0' && st[i-1]=='0') imp=false;

        if((st[i]=='+' && st[i-1]=='-') || (st[i]=='-' && st[i-1]=='+')) need2=true;
    }

    if(imp) cout<<-1<<endl;
    else if(need2) cout<<2<<endl;
    else cout<<1<<endl;
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
