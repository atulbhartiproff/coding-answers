#include <algorithm>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

long long countfreq(vector<long long>& arr,long long x)
{
    long long l=0,r=arr.size()-1;
    long long cnt=0;
    while(l<r)
    {
        if(arr[l]+arr[r]<=x)
        {
            cnt+=(r-l);
            l++;
        }
        else {
        r--;
        }
    }
    return cnt;
}

void test()
{
    long long n,l,r;
    cin>>n>>l>>r;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    cout<<countfreq(arr, r)-countfreq(arr, l-1)<<endl;
}


int main()
{
    long long t;
    cin>>t;
    while(t-- >0)
    {
        test();
    }

    return 0;
}
