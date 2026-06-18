#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<pair<long long,long long>> pref(n);
    long long co=0;
    long long maxi=0;
    pref[0].first=arr[0];
    co+=pref[0].first;
    pref[0].second=arr[0];
    maxi=max(maxi,pref[0].second);
    for(long long i=1;i<n;i++)
    {
        pref[i].first=pref[i-1].first+arr[i];
        pref[i].second=max(pref[i-1].second,pref[i].first);
        maxi=max(maxi,co+pref[i].second);
        co+=pref[i].first;
        // cout<<"Round"<<i<<"\nMax this round: "<<pref[i].second<<endl;
        // cout<<"End this round: "<<pref[i].first<<endl;
        // cout<<"Coordinate now: "<<co<<endl;
        // cout<<"Max Coordinate ever: "<<maxi<<endl;
    }

    // cout<<"END AT:  "<<co<<endl;

    cout<<maxi;
    return 0;
}
