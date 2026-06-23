#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long n,p;
    cin>>n>>p;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++) cin>>arr[i];

    long long l=1;
    long long r=*min_element(arr.begin(),arr.end())*p;

    while(l<=r)
    {
        long long mid=l+(r-l)/2;

        long long cnt=0;
        for(long long i:arr)
        {
            cnt+=mid/i;
            if(cnt>p) break;
        }

        if(cnt<p)
        {
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }

    cout<<l<<endl;

    return 0;
}
