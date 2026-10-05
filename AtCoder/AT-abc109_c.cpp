#include<bits/stdc++.h>
using namespace std;

long long divi(long long a , long long b)
{
    if(b==0) return a;
    return divi(b,a%b);
}

long long fingcd(vector<long long>& arr)
{
    long long gcd=-1;
    for(long long i=1;i<arr.size();i++)
    {
        if(arr[i]==0) continue;

        if(gcd==-1) gcd=arr[i];
        else gcd=divi(max(gcd,arr[i]),min(gcd,arr[i]));
        // cout<<"GCD at "<<arr[i]<<" = "<<gcd<<endl;

    }
    return gcd==-1?1:gcd;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,x;
    cin>>n>>x;
    vector<long long> arr(n);
    for(auto&i:arr) {cin>>i;i-=x;i=abs(i);}
    long long ans=fingcd(arr);
    cout<<ans<<endl;
    return 0;
}
