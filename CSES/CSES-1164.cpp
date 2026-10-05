#include<bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<vector<int>> cust(n);
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        cust[i]={l,r,i};
    }

    sort(cust.begin(),cust.end());

    vector<int> ans(n);
    int rooms=0;

    for(auto c:cust)
    {
        int arr=c[0], dep=c[1], ind=c[2];

        if(!pq.empty() && pq.top().first<arr)
        {
            auto toproom=pq.top();
            pq.pop();
            ans[ind]=toproom.second;
            pq.push({dep,toproom.second});
        }
        else {
        rooms++;

        ans[ind]=rooms;
        pq.push({dep,rooms});
        }
    }
    cout<<rooms<<endl;
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}
