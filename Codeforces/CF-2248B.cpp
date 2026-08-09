#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t-- >0)
    {
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        for(auto& i : a) cin>>i;
        for(auto& i : b) cin>>i;

        if(2*m>n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        bool flag=true;
        for(int i=0;i<m;i++)
        {
            if(a[i]<b[i] && a[n-m+i]>b[i]) continue;
            flag=false;
            break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        continue;
    }
}
