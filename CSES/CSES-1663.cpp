#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mod=1e9+7;
    long long n; cin>>n;

    vector<long long> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(long long i=2;i<=n;i++)
    {
        for(long long j=i-6;j<i;j++)
        {
            if(j<0) j=0;
            dp[i]+=dp[j];
        }
        dp[i]=dp[i]%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
