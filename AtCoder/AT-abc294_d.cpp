#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    priority_queue<int,vector<int>,greater<>> pq;
    for(int i=1;i<=n;i++)
    {
        pq.push(i);
    }
    set<int> st;
    for(int i=0;i<q;i++)
    {
        int t; cin>>t;
        if(t==1)
        {
            int curr=pq.top();
            pq.pop();
            st.insert(curr);
        }
        else if(t==3){cout<<*st.begin()<<endl;}
        else
        {
             int num; cin>>num;
             st.erase(num);
        }
    }
}
