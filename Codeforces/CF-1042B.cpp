#include<bits/stdc++.h>
#include <climits>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    unordered_map<string,long long> mp;
    mp["A"]=mp["B"]=mp["C"]=mp["AB"]=mp["BC"]=mp["AC"]=mp["ABC"]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        long long p; cin>>p;
        string vit;cin>>vit;
        int x=0;
        sort(vit.begin(),vit.end());
        mp[vit]=min(mp[vit],p);
    }
    long long ans=INT_MAX;
    ans=min(ans,mp["A"]+mp["B"]+mp["C"]);
    ans=min(ans,mp["AB"]+mp["C"]);
    ans=min(ans,mp["AC"]+mp["B"]);
    ans=min(ans,mp["BC"]+mp["A"]);
    ans=min(ans,mp["AB"]+mp["AC"]);
    ans=min(ans,mp["AC"]+mp["BC"]);
    ans=min(ans,mp["BC"]+mp["AB"]);
    ans=min(ans,mp["ABC"]);
    cout<<(ans==INT_MAX?-1:ans)<<endl;
}
