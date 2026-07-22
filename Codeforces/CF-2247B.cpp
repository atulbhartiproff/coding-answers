#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t-- >0)
    {
        int n,k,m;
        cin>>n>>k>>m;
        if(k>m)
        {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        for(int i=0;i<n-1;i++)
        {
            cout<<m+1<<" ";
        }
        cout<<m+(m-k+1)<<endl;
        continue;
    }
    return 0;
}
