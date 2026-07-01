#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin>>n;
    vector<long long> arr(n);
    for(auto& i:arr) cin>>i;
    sort(arr.begin(),arr.end());
    vector<long long> pre=arr;
    if(arr[0]!=1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(long long i=1;i<n;i++)
    {
        if(pre[i-1]<arr[i] && arr[i]!=pre[i-1]+1)
        {
            cout<<pre[i-1]+1<<endl;
            return 0;
        }
        pre[i]+=pre[i-1];
    }
    cout<<pre[n-1]+1<<endl;
    return 0;
}
