#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto&i:a) cin>>i;
    for(auto&i:b) cin>>i;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(a==b)
    {
        cout<<"YES"<<endl; return;
    }

    int xora=0,xorb=0;
    for(int i=0;i<n;i++)
    {
        xora=xora^a[i];
        xorb=xorb^b[i];
    }

    int target=xora^xorb;
    bool found = binary_search(a.begin(),a.end(),target);

    if(!found)
    {
        cout<<"NO"<<endl;
        return;
    }

    int idx=find(a.begin(),a.end(),target)-a.begin();
    for(int i=0;i<n;i++)
    {
        if(i==idx) continue;
        a[i]=a[i]^a[idx];
    }
    sort(a.begin(),a.end());
    if(a==b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
