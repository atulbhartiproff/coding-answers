#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> arr(n); for(auto& i:arr) cin>>i;
    int z=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) z++;
    }
    if(z>=2)
    {
        cout<<"YES"<<endl;
        string st="";
        bool first=false,second=false;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0 && !first)
            {
                first=true;
                st+="A";
            }
            else if(arr[i]==0 && first && !second)
            {
                second =true;
                st+="B";
            }
            else if(arr[i]==0)
            {
                st+="A";
            }
            else
            {
                st+="C";
            }
        }
        cout<<st<<endl;
    }
    else if(z==0)
    {
        cout<<"YES"<<endl;
        string st="";
        for(int i=0;i<n-1;i++)
        {
            st+="A";
        }
        st+="B";
        cout<<st<<endl;
    }
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t-- >0)
    {
        solve();
    }

    return 0;
}
