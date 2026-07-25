#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vector<int> dp(n+1,1e9);
    for(int i=0;i<=n;i++)
    {
        int x=i;
        if(x<10)
        {
            dp[i]=1;
            continue;
        }
        while(x>0)
        {
            int dig=x%10;
            x/=10;
            dp[i]=min(dp[i],dp[i-dig]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
