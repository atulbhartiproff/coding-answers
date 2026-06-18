#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,q;
    cin>>n>>q;
    vector<long long> arr(n),presum(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0) presum[i]=arr[i];
        else presum[i]=arr[i]+presum[i-1];
    }

    for(long long i=0;i<q;i++)
    {
        long long l,r;
        cin>>l>>r;
        cout<<presum[r-1]-presum[l-1]+arr[l-1]<<endl;
    }

    return 0;
}
