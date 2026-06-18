#include<bits/stdc++.h>
using namespace std;

long long freq(vector<long long>& arr)
{
    long long ans=0;
    long long n=arr.size();
    map<long long,long long> mp;
    mp[0]=1;
    long long rem=0;
    for(long long i:arr)
    {
        rem=(rem+(i+n))%n;
        //(i+n)%n is for making sure the negative numbers can be converted correctly
        // and then the final %n is to make sure remainder doesnt increase n itself
        // can be shortened down to a single mod n as well.
        ans+=mp[rem];
        mp[rem]++;
    }
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<freq(arr);
    return 0;
}
