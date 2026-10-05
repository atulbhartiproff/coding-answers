#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    if(n==1) cout<<"1"<<endl;
    if(n==2) cout<<"11"<<endl;
    if(n==3) cout<<"101"<<endl;
    if(n==4) cout<<"0101"<<endl;
    if(n==5) cout<<"10101"<<endl;

    if(n>=6)
    {
        string s(n,'0');
        s[n-3]='1';
        s[n-5]='1';
        if(n>6) s[n-7]='1';
        cout<<s<<endl;
    }
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
