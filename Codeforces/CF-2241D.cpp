#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin>>t;
    while(t-- >0)
    {
        long long n;cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(auto& i:a) cin>>i;
        for(auto& i:b) cin>>i;
        bool flag=true;
        for(long long i=0;i<n;i++)
        {
            if(a[i]>b[i])
            {
                flag=false;
                break;
            }
            long long change=b[i]-a[i];
            if(i!=n-1)
            {
                a[i+1]-=change;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
