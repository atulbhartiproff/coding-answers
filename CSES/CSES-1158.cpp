#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,p;
    cin>>n>>p;
    vector<int> price(n);
    for(auto& i:price)cin>>i;

    vector<int> pages(n);
    for(auto& i:pages)cin>>i;

    vector<vector<int>> dp(n+1,vector<int>(p+1,0));


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=p;j++)
        {
            if(j-price[i-1]<0) dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-price[i-1]]+pages[i-1]);
        }
    }

    cout<<dp[n][p]<<endl;
    return 0;

}
