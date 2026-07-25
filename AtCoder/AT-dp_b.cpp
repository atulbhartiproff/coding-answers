#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    vector<int> dp(n,INT_MAX);
    dp[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=max(i-k,0);j<i;j++)
        {
            dp[i]=min(dp[i],dp[j]+abs(arr[j]-arr[i]));
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
