#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> arr(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i]={a,b,c};
    }
    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][j]=arr[i][j]+max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
        }
    }
    cout<<*max_element(dp[n-1].begin(),dp[n-1].end())<<endl;
    return 0;
}
