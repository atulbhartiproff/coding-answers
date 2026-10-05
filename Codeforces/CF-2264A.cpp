#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    int l=0,r=n-1;
    while(l<r)
    {
        if(l+1==arr[l]){ l++ ; continue;}
        if(r+1==arr[r]){ r--; continue;}
        if(arr[l]==r+1 && arr[r]==l+1) { l++; r--; continue;}
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
