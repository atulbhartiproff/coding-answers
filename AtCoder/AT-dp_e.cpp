#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,w;
    cin>>n>>w;
    vector<long long> weigh(n);
    vector<long long> val(n);
    int lim=0;
    for(long long i=0;i<n;i++)
    {
        cin>>weigh[i]>>val[i];
        lim+=val[i];
    }

    vector<vector<long long>> dp(n+1,vector<long long>(lim+1,INT_MAX));
    dp[0][0]=0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<=lim;j++)
        {
            if(j-val[i-1]<0) dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j],weigh[i-1]+dp[i-1][j-val[i-1]]);

            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    for(int i=lim;i>=0;i--)
    {
        if(dp[n][i]<=w)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<dp[n][w];
    return 0;

}
