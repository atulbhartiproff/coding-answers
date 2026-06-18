#include<bits/stdc++.h>
using namespace std;

auto comp(pair<int,int>& a, pair<int,int>& b)
{
    return a.first<b.first;
}

int main()
{
    int n; cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int ar,dep;cin>>ar>>dep;
        arr.push_back({ar,+1});
        arr.push_back({dep,-1});
    }
    sort(arr.begin(),arr.end(),comp);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"customer "<< arr[i].first<<" "<<arr[i].second<<endl;
    // }

    int maxi=0;
    int curr=0;
    for(int i=0;i<arr.size();i++)
    {
        curr+=arr[i].second;
        maxi=max(curr,maxi);
    }
    cout<<maxi<<endl;
    return 0;
}
