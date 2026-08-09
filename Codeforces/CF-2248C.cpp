#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t-- >0)
    {
        int n; cin>>n;

        int total=2*n;
        vector<int> a(total+1);
        for(int i=1;i<=total;i++)
        {
            cin>>a[i];
        }

        vector<int> left(n+1,0);
        vector<long long> dp(total+1,0);

        for(int i=1;i<=total;i++)
        {
            dp[i]=dp[i-1];
            int x=a[i];

            if(left[x]!=0)
            {
                long long l=left[x];
                long long len=i-l+1;
                long long gain=(len*len)-len;

                dp[i]=max(dp[i],dp[l-1]+gain);
            }
            else {
                left[x]=i;
            }
        }

        long long ans=(long long)total+dp[total];
        cout<<ans<<endl;
    }
    return 0;
}
