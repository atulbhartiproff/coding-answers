#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector <int> arr(n);
    for(auto& i :arr) cin>>i;
    int cnt0=0;
    for(auto& i:arr) if(i==0) cnt0++;
    if(cnt0<2) cout<<-1<<endl;
    else
    {
        cout<<arr[0]+arr[n-1]<<endl;
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
