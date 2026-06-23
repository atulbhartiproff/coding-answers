#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& arr, long long m,long long k)
{
    long long cnt=1;
    long long sum=0;
    for(long long i:arr)
    {
        if(i>m) return false;

        if(sum+i>m)
        {
            cnt++;
            sum=i;
        }
        else {
        sum+=i;
        }
    }

    return cnt<=k;
}


int main()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++) cin>>arr[i];

    long long l=0,r=*max_element(arr.begin(),arr.end())*n;

    while(l<=r)
    {
        long long mid=l+(r-l)/2;

        if(check(arr,mid,k))
        {
            r=mid-1;
        }
        else {
        l=mid+1;
        }
    }

    cout<<l;

    return 0;
}
