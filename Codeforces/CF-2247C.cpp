#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t-- >0)
    {
        int n; cin>>n;
        vector<int> a(n);
        for(auto& i:a) cin>>i;
        vector<int> b(n);
        for(auto& i:b) cin>>i;

        if(n==1 && (a[0]==1 || a[0]==b[0]))
        {
            cout<<0<<endl;
            continue;
        }

        int flip1=0, flip0=0,match1=0,match0=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1 && b[i]==0) flip1++;
            if(a[i]==0 && b[i]==1) flip0++;
            if(a[i]==1 && b[i]==1) match1++;
            if(a[i]==0 && b[i]==0) match0++;
        }
        if(flip1==0 && flip0==0) cout<<0<<endl;
        else if(flip1==0 && flip0>0)
        {
            if(match1>0 && match0>0) cout<<2<<endl;
            else cout<<-1<<endl;
        }
        else if(flip1%2==0) cout<<2<<endl;
        else if(flip1%2==1) cout<<1<<endl;

        continue;
    }
}
