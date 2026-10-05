#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> arr(n); for(auto&i:arr) cin>>i;
    vector<int> fin(n,0);
    for(int i=0;i<n;i++) if(arr[i]==0) fin[i]=1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            int len=arr[i]-1;
        }
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
