#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;cin>>n;
    vector<long long> arr(n);
    for(auto& i:arr) cin>>i;
    if(arr.size()==1)
    {
        cout<<arr[0]*2<<endl;
        return 0;
    }
    sort(arr.begin(),arr.end());

    long long sum=0;
    for(long long i=0;i<n;i++) sum+=arr[i];

    if(sum-arr[n-1]<arr[n-1]) cout<<arr[n-1]*2<<endl;
    else cout<<sum<<endl;
    return 0;
}
