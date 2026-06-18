#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int>& arr, int& target)
{
    map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        int ans=target-arr[i];
        if(mp.find(ans)!=mp.end())
        {
            return {mp[ans]+1,i+1};
        }
        else {
            mp[arr[i]]=i;
        }
    }
    return {-1,-1};
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ans=twosum(arr, x);
    if(ans[0]==-1) cout<<"IMPOSSIBLE";
    else cout<<ans[0]<<" "<<ans[1];
    return 0;
}
