#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> arr(n);
    for(auto& i:arr) cin>>i;
    int sum=0;
    for(auto& i:arr) sum+=i;;
    set<int> ans;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-arr[i-1]<0) {dp[i][j]=dp[i-1][j];continue;}

            if(dp[i-1][j-arr[i-1]]==1) {dp[i][j]=1;ans.insert(j);}
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<ans.size()<<endl;
    for(auto& i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}
