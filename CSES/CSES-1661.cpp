#include<bits/stdc++.h>
using namespace std;

long long freq(vector<long long>& arr,long long k)
{
    long long cnt=0;
    long long sum=0;
    map<long long,long long> mp;
    mp[0]=1;

    for(auto i:arr)
    {
        sum+=i;
        long long target=sum-k;
        cnt+=mp[target];
        mp[sum]++;
    }
    return cnt;

}
int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<freq(arr,k);
    return 0;
}
