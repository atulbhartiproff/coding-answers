#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(auto&i:coins) cin>>i;

    vector<long long> dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j-coins[i]<0) continue;

            dp[j]=min(dp[j-coins[i]]+1,dp[j]);
        }
    }

    cout<<(dp[x]==INT_MAX?-1:dp[x])<<endl;
    return 0;
}
