#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> arr(n);
    for(auto&i:arr) cin>>i;
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    if(n<=1)
    {
        cout<<0<<endl;
        return 0;
    }
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++)
    {
        dp[i]=min(abs(arr[i]-arr[i-1])+dp[i-1],dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
