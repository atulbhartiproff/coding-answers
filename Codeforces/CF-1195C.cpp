#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;cin>>n;
    vector<vector<long long>> arr(2,vector<long long>(n,0));
    for(long long i=0;i<2;i++)
    {
        for(long long j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<vector<long long>> dp(2,vector<long long>(n,0));
    dp[0][0]=arr[0][0];
    dp[1][0]=arr[1][0];
    for(long long i=1;i<n;i++)
    {
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]+arr[0][i]);
        dp[1][i]=max(dp[1][i-1],dp[0][i-1]+arr[1][i]);
    }

    cout<<max(dp[0][n-1],dp[1][n-1])<<endl;
    return 0;
}
