#include<bits/stdc++.h>
using namespace std;

auto comp(pair<long long,long long> a, pair<long long,long long> b)
{
    // long long fir=a.second-a.first;
    // long long sec=b.second-b.first;
    // if(fir==sec) return a.second<b.second;
    // else return fir<sec;
    return a.first<b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin>>n;
    vector<pair<long long,long long>> arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    // cout<<"---"<<endl;
    sort(arr.begin(),arr.end(),comp);
    // for(long long i=0;i<n;i++)
    // {
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }
    long long curr=0,sum=0;
    for(long long i=0;i<n;i++)
    {
        curr+=arr[i].first;
        sum+=(arr[i].second-curr);
        // cout<<"Sum now: "<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
