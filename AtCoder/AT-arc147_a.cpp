#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int,vector<int>,less<>> high;
    priority_queue<int,vector<int>,greater<>> low;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int num; cin>>num;
        high.push(num);
        low.push(num);
    }
    int cnt=0;
    while(high.size()>1)
    {
        cnt++;
        int maxi=high.top(); high.pop();
        int mini=low.top();
        int ans=maxi%mini;
        if(ans==0) continue;
        high.push(ans);
        if(ans<mini) low.push(ans);
    }
    cout<<cnt;
    return 0;
}
