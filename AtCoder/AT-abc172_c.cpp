#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,t;
    cin>>a>>b>>t;
    vector<long long> arr(a);
    vector<long long> brr(b);
    for(long long i=0;i<a;i++) cin>>arr[i];
    for(long long i=0;i<b;i++) cin>>brr[i];

    vector<long long> prefa(a);
    vector<long long> prefb(b);
    prefa[0]=arr[0];
    prefb[0]=brr[0];
    for(long long i=1;i<a;i++) prefa[i]=prefa[i-1]+arr[i];
    for(long long i=1;i<b;i++) prefb[i]=prefb[i-1]+brr[i];

    long long maxi=0;
    {
        auto bpart=upper_bound(prefb.begin(),prefb.end(),t);
        long long l=(bpart-prefb.begin());
        maxi=max(maxi,l);
    }
    for(long long i=0;i<a;i++)
    {
        if(prefa[i]>t) break;
        long long now=prefa[i];
        long long rem=t-prefa[i];

        auto bpart=upper_bound(prefb.begin(),prefb.end(),rem);
        long long l=(bpart-prefb.begin());
        maxi=max(maxi,l+i+1);
    }
    cout<<maxi<<endl;
    return 0;
}
