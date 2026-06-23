#include <algorithm>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int, vector<int>> mp;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        mp[temp].push_back(i+1);
    }
    int q;
    cin>>q;
    while(q>0)
    {
        int l,r,x;
        cin>>l>>r>>x;
        cout<<upper_bound(mp[x].begin(),mp[x].end(),r)-lower_bound(mp[x].begin(),mp[x].end(),l)<<endl;
        q--;
    }

    return 0;
}
