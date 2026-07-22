#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k; cin>>n>>k;
    long long x,a,b,c; cin>>x>>a>>b>>c;
    vector<long long> arr(n,0);
    arr[0]=x;
    for(long long i=1;i<n;i++)
    {
        arr[i]=(a*arr[i-1]+b)%c;
    }
    long long l=0,r=0,sum=0;
    for(;r<k;r++)
    {
        sum+=arr[r];
    }
    long long ans=sum;
    while(r<n)
    {
        sum-=arr[l];sum+=arr[r];
        ans=ans^sum;
        r++;l++;
    }
    cout<<ans<<endl;
    return 0;
}
