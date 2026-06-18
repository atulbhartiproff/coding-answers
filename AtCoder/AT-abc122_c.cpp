#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> pre(n);
    pre[0]=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='C' && s[i-1]=='A')
        {
            pre[i]=pre[i-1]+1;
        }
        else {
            pre[i]=pre[i-1];
        }
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<pre[r-1]-pre[l-1]<<endl;
    }

    return 0;
}
