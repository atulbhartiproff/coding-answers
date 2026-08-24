#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mod=1e9+7;
    long long n,k;
    cin>>n>>k;
    vector<long long> coins(n);
    for(auto& i:coins) cin>>i;
    sort(coins.begin(),coins.end());
    vector<long long> dp(k+1,0);

    dp[0]=1;
    for(long long i=1;i<=k;i++)
    {
        for(long long j=0;j<n;j++)
        {
            if(i-coins[j]<0 || dp[i-coins[j]]==0 ) continue;
            dp[i]=(dp[i]+dp[i-coins[j]])%mod;
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}
