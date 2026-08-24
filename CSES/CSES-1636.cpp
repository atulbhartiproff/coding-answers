#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mod =1e9+7;
    int n,k;
    cin>>n>>k;
    vector<int> coins(n);
    for(auto& i : coins) cin>>i;

    vector<int> dp(k+1,0);
    dp[0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j-coins[i]<0) continue;
            dp[j]=(dp[j]+dp[j-coins[i]])%mod;
            // cout<<dp[j]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp[k]<<endl;
    return 0;
}
