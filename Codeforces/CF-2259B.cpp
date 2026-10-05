#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    int odd=0,twos=0,fours=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==1) odd++;
        else if(arr[i]%4==2)twos++;
        else if(arr[i]%4==0) fours++;
        else continue;
    }
    cout<<max({odd,twos,fours})<<endl;
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
