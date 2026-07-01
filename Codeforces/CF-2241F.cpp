#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;

    while(t-- >0)
    {
        int n;cin>>n;
        string s;cin>>s;
        int l=0,r=n-1;
        for(;l<n;l++) if(s[l]!='0') break;
        for(;r>=0;r--) if(s[r]!='1') break;
        if(l>=r)
        {
            cout<<"Bob"<<endl;
            continue;
        }
        bool flag=false;
        int cnt=1;
        for(int i=l;i<r;i++)
        {
            if(s[i]==s[i+1]) cnt++;
            else
            {
                if(cnt%2==1) flag=true;
                cnt=1;
            }
        }
        if(cnt%2==1) flag=true;
        if(!flag) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}
