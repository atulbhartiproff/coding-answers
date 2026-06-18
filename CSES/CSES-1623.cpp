#include<bits/stdc++.h>
using namespace std;

void dfs(long long i,long long total,long long sum,long long& ans,vector<long long>& arr)
{
    if(i==arr.size())
    {
        ans=min(ans,abs(sum-(total-sum)));
        return;
    }

    dfs(i+1,total,sum,ans,arr);
    dfs(i+1,total,sum+arr[i],ans,arr);
}


int main()
{
    long long n; cin>>n; long long total=0;
    vector<long long> arr;
    for(long long i=0;i<n;i++)
    {
        long long temp; cin>>temp;
        arr.push_back(temp);
        total+=temp;
    }
    long long ans=LONG_LONG_MAX;
    dfs(0,total,0,ans,arr);
    cout<<ans;
    return 0;
}
