#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++) cin>>arr[i];

    vector<long long> res;
    res.push_back(arr[0]);

    for(long long i=1;i<n;i++)
    {
        if(res.back()<=arr[i]) {res.push_back(arr[i]);}
        else
         {
             // cout<<arr[i]<<" "<<res.back()<<endl;
             long long idx=upper_bound(res.begin(),res.end(),arr[i])-res.begin();
             res[idx]=arr[i];
         }
    }

    cout<<res.size()<<endl;

    return 0;
}
