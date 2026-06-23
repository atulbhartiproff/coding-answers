#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());
    int cnt=0;

    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            int maxc=arr[i]+arr[j]-1;
            int minc=arr[j]-arr[i]+1;
            cnt+=upper_bound(arr.begin()+j+1,arr.end(),maxc)-lower_bound(arr.begin()+j+1,arr.end(),minc);
        }
    }

    cout<<cnt;
    return 0;
}
