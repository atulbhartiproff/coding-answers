#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long MOD=1e9+7;
    long long h,w;
    cin>>h>>w;

    vector<vector<char>> grid(h,vector<char>(w,'.'));
    for(long long i=0;i<h;i++)
    {
        for(long long j=0;j<w;j++)
        {
            cin>>grid[i][j];
        }
    }

    vector<vector<long long>> dp(h,vector<long long>(w,0));

    long long curr=1;
    for(long long i=0;i<w;i++)
    {
        if(grid[0][i]=='#') curr=0;
        dp[0][i]=curr;
    }
    curr=1;
    for(long long i=0;i<h;i++)
    {
        if(grid[i][0]=='#') curr=0;
        dp[i][0]=curr;
    }



    for(long long i=1;i<h;i++)
    {
        for(long long j=1;j<w;j++)
        {
            if(grid[i][j]=='#') continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }

    // for(long long i=0;i<h;i++)
    // {
    //     for(long long j=0;j<w;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[h-1][w-1]<<endl;
    return 0;
}
