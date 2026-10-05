#include<bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
using namespace std;

void solve()
{
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(auto& i:arr) cin>>i;
    long long sum=0;
    long long ans=LLONG_MIN;
    priority_queue<long long,vector<long long>,less<>> pq;
    for(long long i=0;i<n;i++)
    {
        if(pq.size()==k-1)
        {
            ans=max(ans,1LL*k*arr[i]-sum);
        }

        pq.push(arr[i]);
        sum+=arr[i];
        while(pq.size()>k-1)
        {
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
