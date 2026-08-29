#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n , k;
    cin>>n>>k;

    const long long mod=1e9+7;
    vector<long long> arr(n);
    for(auto& i:arr)
    {
        cin>>i;
    }

    vector<vector<long long>> dp(n+1,vector<long long> (k+1,0));
    dp[0][0]=1;
    for(long long i=1;i<=n;i++)
    {
        long long window=0;
        for(long long j=0;j<=k;j++)
        {
            window+=dp[i-1][j];

            if(j-arr[i-1]-1>=0) window-=dp[i-1][j-arr[i-1]-1];

            window=(window+mod)%mod;
            dp[i][j]=window;
        }
    }

    cout<<dp[n][k]<<endl;

    return 0;
}
