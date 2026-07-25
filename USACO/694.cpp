#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        char temp; cin>>temp;
        if(temp=='H') arr[i]=0;
        if(temp=='P') arr[i]=1;
        if(temp=='S') arr[i]=2;
    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(k+1,0)));

    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=0;j--)
        {
            dp[i][2][j]=dp[i-1][2][j];
            dp[i][1][j]=dp[i-1][1][j];
            dp[i][0][j]=dp[i-1][0][j];

            if(j>0){
            dp[i][2][j]=max(max(dp[i-1][2][j],dp[i-1][1][j-1]),dp[i-1][0][j-1]);
            dp[i][1][j]=max(max(dp[i-1][1][j],dp[i-1][2][j-1]),dp[i-1][0][j-1]);
            dp[i][0][j]=max(max(dp[i-1][0][j],dp[i-1][2][j-1]),dp[i-1][1][j-1]);
            }

            int win=(arr[i-1]+1)%3;
            dp[i][win][j]++;
        }



    }

    int ans = 0;

    for(int g = 0; g < 3; g++)
        for(int j = 0; j <= k; j++)
            ans = max(ans, dp[n][g][j]);

    cout << ans<<endl;

    return 0;
}
